#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
char s[701];
size_t n, pos[701], st[701], top;
int dp[701][701][3][3];
void Dfs(size_t l, size_t r)
{
    if (l + 1 == r)
    {
        dp[l][r][1][0] = dp[l][r][2][0] = dp[l][r][0][1] = dp[l][r][0][2] = 1;
        return;
    }
    if (pos[l] == r)
    {
        Dfs(l + 1, r - 1);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != 1)
                {
                    dp[l][r][1][0] = (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % kMod;
                }
                if (i != 2)
                {
                    dp[l][r][2][0] = (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % kMod;
                }
                if (j != 1)
                {
                    dp[l][r][0][1] = (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % kMod;
                }
                if (j != 2)
                {
                    dp[l][r][0][2] = (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % kMod;
                }
            }
        }
    }
    else
    {
        Dfs(l, pos[l]);
        Dfs(pos[l] + 1, r);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int p = 0; p < 3; p++)
                {
                    for (int q = 0; q < 3; q++)
                    {
                        if (j && j == p)
                        {
                            continue;
                        }
                        dp[l][r][i][q] = (dp[l][r][i][q] + dp[l][pos[l]][i][j] * static_cast<long long>(dp[pos[l] + 1][r][p][q]) % kMod) % kMod;
                    }
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> (s + 1);
    n = std::strlen(s + 1);
    for (size_t i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            st[++top] = i;
        }
        else
        {
            pos[st[top--]] = i;
        }
    }
    Dfs(1, n);
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = (ans + dp[1][n][i][j]) % kMod;
        }
    }
    std::cout << ans;
    return 0;
}