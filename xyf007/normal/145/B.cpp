#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int a1, a2, a3, a4;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> a1 >> a2 >> a3 >> a4;
    if (std::abs(a3 - a4) > 1 || a3 > a1 || a3 > a2 || a4 > a1 || a4 > a2)
    {
        std::cout << -1;
        return 0;
    }
    if (a3 == a4)
    {
        if (a1 == a3 && a2 == a3)
        {
            std::cout << -1;
            return 0;
        }
        if (a1 > a3)
        {
            for (int i = 1; i <= a1 - a3; i++)
            {
                std::cout << 4;
            }
            for (int i = 1; i < a3; i++)
            {
                std::cout << 74;
            }
            for (int i = 1; i <= a2 - a4 + 1; i++)
            {
                std::cout << 7;
            }
            std::cout << 4;
        }
        else
        {
            std::cout << 7;
            for (int i = 1; i <= a1 - a3 + 1; i++)
            {
                std::cout << 4;
            }
            for (int i = 1; i < a3; i++)
            {
                std::cout << 74;
            }
            for (int i = 1; i <= a2 - a3; i++)
            {
                std::cout << 7;
            }
        }
    }
    else if (a3 > a4)
    {
        for (int i = 1; i <= a1 - a3; i++)
        {
            std::cout << 4;
        }
        for (int i = 1; i <= a3; i++)
        {
            std::cout << 47;
        }
        for (int i = 1; i <= a2 - a3; i++)
        {
            std::cout << 7;
        }
    }
    else
    {
        std::cout << 74;
        for (int i = 1; i <= a1 - a4; i++)
        {
            std::cout << 4;
        }
        for (int i = 1; i <= a4 - 2; i++)
        {
            std::cout << 74;
        }
        for (int i = 1; i <= a2 - a4; i++)
        {
            std::cout << 7;
        }
        std::cout << 74;
    }
    return 0;
}