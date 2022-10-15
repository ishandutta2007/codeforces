#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int t, n, m, sum[505][505];
char a[505][505];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++)
            {
                sum[i][j] = sum[i][j - 1] + (a[i][j] == '*');
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= n - i + 1; k++)
                {
                    if (j - k + 1 < 1 || j + k - 1 > m)
                    {
                        break;
                    }
                    if (sum[i + k - 1][j + k - 1] - sum[i + k - 1][j - k] == 2 * k - 1)
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}