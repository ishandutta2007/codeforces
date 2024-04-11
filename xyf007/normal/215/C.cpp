#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <cassert>
int n, m, s;
long long dp[501][501];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> s;
    long long ans = 0LL;
    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= m; j += 2)
        {
            if (i * j < s)
            {
                continue;
            }
            else if (i * j == s)
            {
                dp[i][j] = 2 * (i / 2 + 1) * (j / 2 + 1) - 1;
            }
            else
            {
                if ((i * j - s) % 4)
                {
                    continue;
                }
                int sz = (i * j - s) >> 2;
                for (int k = 1; k <= i >> 1; k++)
                {
                    if (sz % k)
                    {
                        continue;
                    }
                    int l = sz / k;
                    if (l <= j >> 1)
                    {
                        dp[i][j] += 2;
                    }
                }
            }
            ans += dp[i][j] * (n - i + 1) * (m - j + 1);
        }
    }
    std::cout << ans;
    return 0;
}