#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int a, b, c, d, e, f, min, t[8];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> a >> b >> c >> d >> e >> f;
    if (((e + f - a - b) & 1) || ((d + f - a - c) & 1) || ((b + c - f) & 1) || ((d + e - b - c) & 1) || ((a + c - e) & 1) || ((a + b - d) & 1))
    {
        std::cout << -1;
        return 0;
    }
    t[1] = (e + f - a - b) >> 1;
    t[2] = (d + f - a - c) >> 1;
    t[3] = (b + c - f) >> 1;
    t[4] = (d + e - b - c) >> 1;
    t[5] = (a + c - e) >> 1;
    t[6] = (a + b - d) >> 1;
    bool ok = std::all_of(t + 1, t + 7, [](const int &x) -> bool { return x >= 0; });
    for (; !ok && t[7] <= a && t[7] <= b && t[7] <= c; t[7]++)
    {
        t[1]++;
        t[2]++;
        t[3]--;
        t[4]++;
        t[5]--;
        t[6]--;
        ok |= std::all_of(t + 1, t + 7, [](const int &x) -> bool { return x >= 0; });
    }
    if (!ok)
    {
        std::cout << -1;
        return 0;
    }
    std::cout << (min = (d + e + f) / 2 + t[7]) << '\n';
    for (int i = 1; i <= min; i++)
    {
        std::cout << 'a';
    }
    std::cout << '\n';
    for (int i = 1; i <= t[1] + t[2] + t[3]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[4] + t[5] + t[6] + t[7]; i++)
    {
        std::cout << 'b';
    }
    std ::cout << '\n';
    for (int i = 1; i <= t[1]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[2] + t[3]; i++)
    {
        std::cout << 'b';
    }
    for (int i = 1; i <= t[4] + t[5]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[6] + t[7]; i++)
    {
        std::cout << 'b';
    }
    std::cout << '\n';
    for (int i = 1; i <= t[1]; i++)
    {
        std::cout << 'b';
    }
    for (int i = 1; i <= t[2]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[3]; i++)
    {
        std::cout << 'b';
    }
    for (int i = 1; i <= t[4]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[5]; i++)
    {
        std::cout << 'b';
    }
    for (int i = 1; i <= t[6]; i++)
    {
        std::cout << 'a';
    }
    for (int i = 1; i <= t[7]; i++)
    {
        std::cout << 'b';
    }
    return 0;
}