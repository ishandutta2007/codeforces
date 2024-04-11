#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kFull = 4194303;
int n, a[1000001], f[4194304];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        f[a[i]] = a[i];
    }
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < (1 << 22); j++)
        {
            if ((j >> i) & 1 && f[j ^ (1 << i)])
            {
                f[j] = f[j ^ (1 << i)];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[kFull ^ a[i]])
        {
            std::cout << f[kFull ^ a[i]] << ' ';
        }
        else
        {
            std::cout << "-1 ";
        }
    }
    return 0;
}