#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, a[31][31];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = 0;
        if (n <= m)
        {
            for (int k = 2; k <= (n + m + 1) >> 1; k++)
            {
                int cnt0 = 0, cnt1 = 0;
                for (int i = 1, j = k - 1; i <= n && j >= 1; i++, j--)
                {
                    if (!a[i][j])
                    {
                        cnt0++;
                    }
                    else
                    {
                        cnt1++;
                    }
                }
                for (int i = n, j = m + 2 - k; i >= 1 && j <= m; i--, j++)
                {
                    if (!a[i][j])
                    {
                        cnt0++;
                    }
                    else
                    {
                        cnt1++;
                    }
                }
                ans += min(cnt0, cnt1);
            }
        }
        else
        {
            for (int k = 2; k <= (n + m + 1) >> 1; k++)
            {
                int cnt0 = 0, cnt1 = 0;
                for (int i = k - 1, j = 1; i >= 1 && j <= m; i--, j++)
                {
                    if (!a[i][j])
                    {
                        cnt0++;
                    }
                    else
                    {
                        cnt1++;
                    }
                }
                for (int i = n + 2 - k, j = m; i <= n && j >= 1; i++, j--)
                {
                    if (!a[i][j])
                    {
                        cnt0++;
                    }
                    else
                    {
                        cnt1++;
                    }
                }
                ans += min(cnt0, cnt1);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}