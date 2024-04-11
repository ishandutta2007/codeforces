#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1100;
int k;
int a[N][N];

int main()
{
    scanf("%d", &k);
    a[0][0] = 1;
    for (int i = 0; i < k; i++)
    {
        int n = 1 << i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[n + i][j] = a[i][n + j] = a[n + i][n + j] = a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[n + i][j] *= -1;
    }
    int n = 1 << k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", (a[i][j] == 1 ? '+' : '*'));
        printf("\n");
    }

    return 0;
}