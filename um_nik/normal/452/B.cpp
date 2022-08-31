#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;
int a[4][5][3];
double b[5];
int t = -1;

int sqr(int x)
{
    return x * x;
}

int main()
{
    scanf("%d%d", &n, &m);
    if (n == 0)
    {
        printf("0 %d\n", m - 1);
        printf("0 0\n");
        printf("0 %d\n", m);
        printf("0 1\n");
        return 0;
    }
    if (m == 0)
    {
        printf("%d 0\n", n - 1);
        printf("0 0\n");
        printf("%d 0\n", n);
        printf("1 0\n");
        return 0;
    }

    a[0][0][0] = 0;
    a[0][0][1] = 1;

    a[0][1][0] = n;
    a[0][1][1] = m;

    a[0][2][0] = 0;
    a[0][2][1] = 0;

    a[0][3][0] = n;
    a[0][3][1] = m - 1;

    
    a[1][0][0] = 1;
    a[1][0][1] = 0;

    a[1][1][0] = n;
    a[1][1][1] = m;

    a[1][2][0] = 0;
    a[1][2][1] = 0;

    a[1][3][0] = n - 1;
    a[1][3][1] = m;

    
    a[2][0][0] = 0;
    a[2][0][1] = 0;

    a[2][1][0] = n;
    a[2][1][1] = m;

    a[2][2][0] = n;
    a[2][2][1] = 0;

    a[2][3][0] = 0;
    a[2][3][1] = m;

    
    a[3][0][0] = 0;
    a[3][0][1] = 0;

    a[3][1][0] = n;
    a[3][1][1] = m;

    a[3][2][0] = 0;
    a[3][2][1] = m;

    a[3][3][0] = n;
    a[3][3][1] = 0;

    for (int i = 0; i < 4; i++)
    {
        b[i] = 0.;
        for (int k = 0; k < 3; k++)
            b[i] += sqrt((double)( sqr(a[i][k][0] - a[i][k + 1][0]) + sqr(a[i][k][1] - a[i][k + 1][1]) ));
        if (t == -1 || b[i] > b[t])
            t = i;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", a[t][i][j]);
        printf("\n");
    }
    return 0;
}