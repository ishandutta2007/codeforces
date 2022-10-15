#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
long long l, r;
int dp[101][101];
long long Solve(long long n)
{
    long long tmp = n, ans = 0LL;
    std::memset(dp, 0, sizeof(dp));
    std::vector<int> bit;
    while (tmp)
    {
        bit.emplace_back(tmp & 1);
        tmp >>= 1;
    }
    std::reverse(bit.begin(), bit.end());
    for (size_t i = 2; i < bit.size(); i++)
    {
        for (size_t j = 1; j <= i >> 1; j++)
        {
            if (!(i % j))
            {
                dp[i][j] = 1LL << (j - 1);
            }
        }
    }
    for (size_t i = 1; i <= (bit.size() >> 1); i++)
    {
        if (bit.size() % i)
        {
            continue;
        }
        for (size_t j = 1; j < i; j++)
        {
            if (bit.at(j))
            {
                dp[bit.size()][i] += 1LL << (i - j - 1);
            }
        }
        bool f = true;
        for (size_t j = i; j < bit.size(); j++)
        {
            if (bit.at(j) < bit.at(j - i))
            {
                f = false;
                break;
            }
            else if (bit.at(j) > bit.at(j - i))
            {
                break;
            }
        }
        dp[bit.size()][i] += f;
    }
    for (size_t i = 2; i <= bit.size(); i++)
    {
        for (size_t j = 1; j <= i >> 1; j++)
        {
            if (!(i % j))
            {
                for (size_t k = 1; k <= j >> 1; k++)
                {
                    if (!(j % k))
                    {
                        dp[i][j] -= dp[i][k];
                    }
                }
            }
        }
    }
    for (size_t i = 2; i <= bit.size(); i++)
    {
        ans += std::accumulate(dp[i] + 1, dp[i] + i, 0LL);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> l >> r;
    std::cout << Solve(r) - Solve(l - 1);
    return 0;
}