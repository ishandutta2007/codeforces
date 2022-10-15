#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int t, n, m, sum[201];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> t;
    while (t--)
    {
        std::memset(sum, 0, sizeof(sum));
        std::cin >> n >> m;
        int x;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                std::cin >> x;
                sum[i + j] ^= x;
            }
        }
        bool f = false;
        for (int i = 2; i <= n + m && !f; i++)
        {
            f |= sum[i];
        }
        if (f)
        {
            std::cout << "Ashish\n";
        }
        else
        {
            std::cout << "Jeel\n";
        }
    }
    return 0;
}