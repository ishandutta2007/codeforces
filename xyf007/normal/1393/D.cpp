#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, lu[2001][2001], ru[2001][2001], ld[2001][2001], rd[2001][2001];
char a[2001][2001];
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", a[i] + 1);
    }
    for (int T = 2; T <= n + m; T++)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = T - i;
            if (j < 1 || j > m)
            {
                continue;
            }
            if (i == 1 || j == 1 || a[i][j] != a[i - 1][j] || a[i][j] != a[i][j - 1])
            {
                lu[i][j] = 1;
                continue;
            }
            lu[i][j] = min(lu[i - 1][j], lu[i][j - 1]) + 1;
        }
    }
    for (int T = m - 1; T >= 1 - n; T--)
    {
        for (int j = 1; j <= m; j++)
        {
            int i = j - T;
            if (i < 1 || i > n)
            {
                continue;
            }
            if (i == 1 || j == m || a[i][j] != a[i - 1][j] || a[i][j] != a[i][j + 1])
            {
                ru[i][j] = 1;
                continue;
            }
            ru[i][j] = min(ru[i - 1][j], ru[i][j + 1]) + 1;
        }
    }
    for (int T = 1 - n; T <= m - 1; T++)
    {
        for (int j = 1; j <= m; j++)
        {
            int i = j - T;
            if (i < 1 || i > n)
            {
                continue;
            }
            if (i == n || j == 1 || a[i][j] != a[i + 1][j] || a[i][j] != a[i][j - 1])
            {
                ld[i][j] = 1;
                continue;
            }
            ld[i][j] = min(ld[i + 1][j], ld[i][j - 1]) + 1;
        }
    }
    for (int T = n + m; T >= 2; T--)
    {
        for (int i = 1; i <= n; i++)
        {
            int j = T - i;
            if (j < 1 || j > m)
            {
                continue;
            }
            if (i == n || j == m || a[i][j] != a[i + 1][j] || a[i][j] != a[i][j + 1])
            {
                rd[i][j] = 1;
                continue;
            }
            rd[i][j] = min(rd[i + 1][j], rd[i][j + 1]) + 1;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans += min(min(lu[i][j], ru[i][j]), min(ld[i][j], rd[i][j]));
        }
    }
    printf("%lld", ans);
    return 0;
}