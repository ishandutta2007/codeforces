#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
int n, r, ans = 0x7fffffff;
char tmp[1000001], s[1000001];
bool Solve(int a, int b)
{
    for (int i = n; i >= 1; i--)
    {
        if (a == b)
        {
            if (b != 1 || (b == 1 && i != 1))
            {
                return false;
            }
        }
        if (a < 0 || b < 0)
        {
            return false;
        }
        if (a >= b)
        {
            tmp[i] = 'T';
            a -= b;
        }
        else
        {
            tmp[i] = 'B';
            b -= a;
        }
    }
    return !a && b == 1;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> r;
    int min = 0x7fffffff;
    for (int i = 1; i <= r; i++)
    {
        if (Solve(r, i))
        {
            int cnt = 0;
            for (int i = 1; i < n; i++)
            {
                cnt += tmp[i] == tmp[i + 1];
            }
            if (cnt < min)
            {
                min = cnt;
                std::memcpy(s + 1, tmp + 1, n);
            }
        }
        if (Solve(i, r))
        {
            int cnt = 0;
            for (int i = 1; i < n; i++)
            {
                cnt += tmp[i] == tmp[i + 1];
            }
            if (cnt < min)
            {
                min = cnt;
                std::memcpy(s + 1, tmp + 1, n);
            }
        }
    }
    if (min == 0x7fffffff)
    {
        std::cout << "IMPOSSIBLE";
    }
    else
    {
        std::cout << min << '\n';
        for (int i = 1; i <= n; i++)
        {
            std::cout << s[i];
        }
    }
    return 0;
}