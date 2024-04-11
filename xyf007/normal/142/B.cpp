#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    if (n > m)
    {
        std::swap(n, m);
    }
    if (n == 1)
    {
        std::cout << m;
    }
    else if (n == 2)
    {
        std::cout << m / 4 * 4 + (m % 4 <= 2 ? m % 4 * 2 : 4);
    }
    else
    {
        std::cout << (n * m + 1) / 2;
    }
    return 0;
}