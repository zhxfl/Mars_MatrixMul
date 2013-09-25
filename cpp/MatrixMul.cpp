#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;

void GetMatrix(float *matrix, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            matrix[i*m + j] = rand() % 100;
        }
    }
}

int main( int argc, char** argv)
{
        int n,m;
        sscanf(argv[1], "%d", &n);
        sscanf(argv[2], "%d", &m);
        printf("%d %d\n", n, m);
        float *matrix1 = new float [n*m];
        float *matrix2 = new float [n*m];
        float *matrix3 = new float [n*n];
        memset(matrix3, 0, sizeof(matrix3));
        GetMatrix(matrix1, n, m);
        GetMatrix(matrix2, m, n);
        float start = clock();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int k =0; k < n; k++)
                {
                    //matrix3[i][k] += matrix1[i][j] * matrix2[j][k];
                    matrix3[i * k + k] += matrix1[i * j + j] * matrix1[j * k + k];
                }
            }
        }
        float end = clock();
        printf("time = %f\n", (end - start) / CLOCKS_PER_SEC);
        delete []matrix1;
        delete []matrix2;
        delete []matrix3;
        return 0;
}

