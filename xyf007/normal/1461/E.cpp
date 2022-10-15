#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
long long k, l, r, t, x, y;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> k >> l >> r >> t >> x >> y;
    if (x == y)
    {
        if (k - x < l && k + y > r)
        {
            std::cout << "No\n";
        }
        else
        {
            std::cout << "Yes\n";
        }
        return 0;
    }
    if (x > y)
    {
        long long tmp = (k - l) / x;
        if (k - tmp * x + y > r)
        {
            if (tmp >= t)
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
            return 0;
        }
        long long tot = (k + x + y - r - 1) / x;
        k -= tot * x;
        tot += (k - l) / (x - y);
        if (tot >= t)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
        return 0;
    }
    long long tmp = (k - l) / x, div = y / x, mod = y % x;
    k -= tmp * x;
    for (int i = 1; i <= x; i++)
    {
        if (k + y > r)
        {
            if (tmp >= t)
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
            return 0;
        }
        tmp += div;
        k += mod;
        if (k - l >= x)
        {
            tmp++;
            k -= x;
        }
    }
    std::cout << "Yes\n";
    return 0;
}