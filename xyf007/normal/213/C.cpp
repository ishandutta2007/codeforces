#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, a[301][301], dp[601][301][301];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
        }
    }
    std::memset(dp, 0xcf, sizeof(dp));
    dp[1][1][1] = 0;
    for (int k = 1; k <= 2 * n - 1; k++)
    {
        for (int i = std::max(1, k + 1 - n); i <= n && i <= k; i++)
        {
            for (int j = std::max(1, k + 1 - n); j <= n && j <= k; j++)
            {
                int v = a[i][k - i + 1] + (i != j) * a[j][k - j + 1] + dp[k][i][j];
                checkmax(dp[k + 1][i][j], v);
                checkmax(dp[k + 1][i + 1][j], v);
                checkmax(dp[k + 1][i][j + 1], v);
                checkmax(dp[k + 1][i + 1][j + 1], v);
            }
        }
    }
    std::cout << dp[2 * n - 1][n][n] + a[n][n];
    return 0;
}