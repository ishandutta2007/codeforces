#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int k, dp[35][35][2], pw[35];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> k;
    pw[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        pw[i] = pw[i - 1] << 1;
    }
    dp[30][0][1] = 1;
    for (int i = 30; i >= 1; i--)
    {
        for (int j = 0; j <= 30 - i; j++)
        {
            dp[i - 1][j + 1][0] = (dp[i - 1][j + 1][0] + dp[i][j][0]) % kMod;
            dp[i - 1][j][0] = (dp[i - 1][j][0] + dp[i][j][0] * static_cast<long long>(pw[j]) % kMod) % kMod;
            long long e = j ? pw[j - 1] : 1LL, o = j ? pw[j - 1] : 0LL;
            if (!((k >> (i - 1)) & 1))
            {
                dp[i - 1][j][1] = (dp[i - 1][j][1] + dp[i][j][1] * e % kMod) % kMod;
            }
            else
            {
                dp[i - 1][j + 1][1] = (dp[i - 1][j + 1][1] + dp[i][j][1]) % kMod;
                dp[i - 1][j][0] = (dp[i - 1][j][0] + dp[i][j][1] * e % kMod) % kMod;
                dp[i - 1][j][1] = (dp[i - 1][j][1] + dp[i][j][1] * o % kMod) % kMod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 30; i++)
    {
        ans = (ans + (dp[0][i][0] + dp[0][i][1]) % kMod) % kMod;
    }
    std::cout << ans;
    return 0;
}