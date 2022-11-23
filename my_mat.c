#include "my_mat.h"
#include "stdio.h"
#define INT_MAX 999999 

int shortest_path(int mat [10][10],int a, int b);

void insert(int mat [10][10])
{
    int weight;
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
             scanf("%d",&weight);
             mat[i][j] = weight;
        }
    }
    
}

void has_path(int mat [10][10],int a, int b)
{
    if(shortest_path(mat,a,b) == -1)
    {
       printf("False");
    }
    else
    { 
    printf("True");
    }
}


int shortest_path(int mat [10][10],int a, int b)
{ 
    
    //Using Floyd Warshall's algorithm
    int dist[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dist[i][j] = mat[i][j];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(dist[i][j]==0)
            {
                dist[i][j] = INT_MAX;
            }
        }
    

    }
    print_mat(dist);
    for (int k = 0; k < 10; k++) {

       for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
       }
    }
    if (dist[a][b]!=INT_MAX)
        return dist[a][b];
    return -1;
}

void print_mat(int mat[10][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}