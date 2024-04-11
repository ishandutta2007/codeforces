#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int n, a[10], dp[101][10], C[101][101];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    for (int i = 0; i <= 100; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % kMod;
        }
    }
    std::cin >> n;
    for (int i = 0; i < 10; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][9] = i >= a[9];
        for (int j = 8; j >= 1; j--)
        {
            for (int k = a[j]; k <= i; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - k][j + 1] * static_cast<long long>(C[i][k]) % kMod) % kMod;
            }
        }
        if (i)
        {
            for (int j = a[0]; j <= i; j++)
            {
                dp[i][0] = (dp[i][0] + dp[i - j][1] * static_cast<long long>(C[i - 1][j]) % kMod) % kMod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[i][0]) % kMod;
    }
    std::cout << ans;
    return 0;
}