#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, a[5][101], dp[101][21], tmp[5];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            for (int s1 = 0; s1 <= (1 << n) - 1; s1++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int s2 = 0; s2 <= (1 << n) - 1; s2++)
                    {
                        if (s1 & s2)
                        {
                            continue;
                        }
                        int sum = 0;
                        for (int k = 0; k < n; k++)
                        {
                            if ((1 << k) & s2)
                            {
                                sum += a[k][i];
                            }
                        }
                        checkmax(dp[i][s1 | s2], dp[i - 1][s1] + sum);
                    }
                    for (int k = 1; k < n; k++)
                    {
                        tmp[k - 1] = a[k][i];
                    }
                    tmp[n - 1] = a[0][i];
                    for (int k = 0; k < n; k++)
                    {
                        a[k][i] = tmp[k];
                    }
                }
            }
        }
        printf("%d\n", dp[m][(1 << n) - 1]);
    }
    return 0;
}