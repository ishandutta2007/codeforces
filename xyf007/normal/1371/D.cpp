#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k, a[1001][1001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        int len = k / n, t = k % n;
        if (!t)
        {
            printf("0\n");
        }
        else
        {
            printf("2\n");
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = 0;
            }
        }
        for (int i = 1; i <= n - t; i++)
        {
            for (int j = 0; j < len; j++)
            {
                a[i][(i + j - 1) % n + 1] = 1;
            }
        }
        for (int i = n - t + 1; i <= n; i++)
        {
            for (int j = 0; j < len + 1; j++)
            {
                a[i][(i + j - 1) % n + 1] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}