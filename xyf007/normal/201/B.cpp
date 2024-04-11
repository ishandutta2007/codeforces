#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m, a[1001][1001], sum1[1001], sum2[1001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
        }
        sum1[i] = std::accumulate(a[i] + 1, a[i] + m + 1, 0);
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            sum2[j] += a[i][j];
        }
    }
    long long min1 = 0x7fffffffffffffffLL, min2 = 0x7fffffffffffffffLL;
    int px = -1, py = -1;
    for (int i = 0; i <= n; i++)
    {
        long long tmp = 0LL;
        for (int j = 1; j <= n; j++)
        {
            if (j > i)
            {
                tmp += (4LL * (j - i) - 2) * (4LL * (j - i) - 2) * sum1[j];
            }
            else
            {
                tmp += (4LL * (i - j) + 2) * (4LL * (i - j) + 2) * sum1[j];
            }
        }
        if (tmp < min1)
        {
            min1 = tmp;
            px = i;
        }
    }
    for (int i = 0; i <= m; i++)
    {
        long long tmp = 0LL;
        for (int j = 1; j <= m; j++)
        {
            if (j > i)
            {
                tmp += (4LL * (j - i) - 2) * (4LL * (j - i) - 2) * sum2[j];
            }
            else
            {
                tmp += (4LL * (i - j) + 2) * (4LL * (i - j) + 2) * sum2[j];
            }
        }
        if (tmp < min2)
        {
            min2 = tmp;
            py = i;
        }
    }
    std::cout << min1 + min2 << '\n'
              << px << ' ' << py;
    return 0;
}