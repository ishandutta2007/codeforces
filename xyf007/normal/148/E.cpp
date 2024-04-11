#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m, k[101], v[101][101], sum[101][101], max[101][101], dp[101][10001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            std::cin >> v[i][j];
        }
        std::partial_sum(v[i] + 1, v[i] + k[i] + 1, sum[i] + 1);
        for (int j = 1; j <= k[i]; j++)
        {
            int min = 0x7ffffff;
            for (int l = k[i] - j; l <= k[i]; l++)
            {
                checkmin(min, sum[i][l] - sum[i][l - k[i] + j]);
            }
            max[i][j] = sum[i][k[i]] - min;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k[i]; j++)
        {
            for (int l = j; l <= m; l++)
            {
                checkmax(dp[i][l], dp[i - 1][l - j] + max[i][j]);
            }
        }
    }
    std::cout << dp[n][m];
    return 0;
}