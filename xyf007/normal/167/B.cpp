#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, l, k, a[201];
double p[201], dp[201][201][201];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> l >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
        p[i] /= 100;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                std::swap(p[j], p[j + 1]);
            }
        }
    }
    dp[0][0][std::min(k, n)] = 1.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int l = 0; l <= n; l++)
            {
                if (l + a[i + 1] >= 0)
                {
                    dp[i + 1][j + 1][std::min(l + a[i + 1], n)] += dp[i][j][l] * p[i + 1];
                }
                dp[i + 1][j][l] += dp[i][j][l] * (1 - p[i + 1]);
            }
        }
    }
    double ans = 0.0;
    for (int i = l; i <= n; i++)
    {
        ans += std::accumulate(dp[n][i], dp[n][i] + n + 1, 0.0);
    }
    std::cout << std::setprecision(8) << std::fixed << ans;
    return 0;
}