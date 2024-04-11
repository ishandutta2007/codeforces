#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <cassert>
int n, a[53], dp[53][53][53][53];
bool check(int x, int y)
{
    return (x - 1) % 13 == (y - 1) % 13 || (x - 1) / 13 == (y - 1) / 13;
}
int Dfs(int now, int x1, int x2, int x3)
{
    if (dp[now][x1][x2][x3] != -1)
    {
        return dp[now][x1][x2][x3];
    }
    if (now == 1)
    {
        return 1;
    }
    if (check(x2, x3) && Dfs(now - 1, a[now - 3], x1, x3))
    {
        return dp[now][x1][x2][x3] = 1;
    }
    if (now > 3 && check(a[now - 3], x3) && Dfs(now - 1, x3, x1, x2))
    {
        return dp[now][x1][x2][x3] = 1;
    }
    return dp[now][x1][x2][x3] = 0;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    char card[10];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> card;
        int c, v;
        switch (card[0])
        {
        case 'T':
            v = 10;
            break;
        case 'J':
            v = 11;
            break;
        case 'Q':
            v = 12;
            break;
        case 'K':
            v = 13;
            break;
        case 'A':
            v = 1;
            break;
        default:
            v = card[0] - '0';
            break;
        }
        switch (card[1])
        {
        case 'S':
            c = 0;
            break;
        case 'D':
            c = 1;
            break;
        case 'H':
            c = 2;
            break;
        case 'C':
            c = 3;
            break;
        default:
            assert(false);
            break;
        }
        a[i] = 13 * c + v;
    }
    std::memset(dp, -1, sizeof(dp));
    if (Dfs(n, a[n - 2], a[n - 1], a[n]))
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}