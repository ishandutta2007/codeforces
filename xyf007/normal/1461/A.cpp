#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int t, n, k;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            if (!(i % 3))
            {
                std::cout << 'a';
            }
            else if (i % 3 == 1)
            {
                std::cout << 'c';
            }
            else
            {
                std::cout << 'b';
            }
        }
        std::cout << '\n';
    }
    return 0;
}