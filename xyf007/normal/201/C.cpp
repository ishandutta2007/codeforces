#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, a[100001];
long long dp[100001][2][2];
void checkmax(long long &x, long long y)
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
    for (int i = 1; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][0][0] = dp[i][0][1] = a[i - 1] < 2 ? 0 : dp[i - 1][0][1] + a[i - 1] / 2 * 2;
        checkmax(dp[i][0][0], std::max(dp[i - 1][0][0] + a[i - 1] - !(a[i - 1] & 1), dp[i - 1][0][1] + a[i - 1]));
    }
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i][1][0] = dp[i][1][1] = a[i] < 2 ? 0 : dp[i + 1][1][1] + a[i] / 2 * 2;
        checkmax(dp[i][1][0], std::max(dp[i + 1][1][0] + a[i] - !(a[i] & 1), dp[i + 1][1][1] + a[i]));
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; i++)
    {
        checkmax(ans, std::max(dp[i][0][1] + dp[i][1][0], dp[i][0][0] + dp[i][1][1]));
    }
    std::cout << ans;
    return 0;
}