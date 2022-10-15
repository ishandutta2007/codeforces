#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m, r, a[61][61][61], dis[61][61][61];
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
    std::cin >> n >> m >> r;
    for (int id = 1; id <= m; id++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                std::cin >> a[id][i][j];
            }
        }
    }
    for (int id = 1; id <= m; id++)
    {
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    checkmin(a[id][i][j], a[id][i][k] + a[id][k][j]);
                }
            }
        }
    }
    std::memset(dis, 0x3f, sizeof(dis));
    for (int id = 1; id <= m; id++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                checkmin(dis[i][j][0], a[id][i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cerr << dis[i][j][0] << ' ';
        }
        std::cerr << '\n';
    }
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j][l] = dis[i][j][l - 1];
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    checkmin(dis[i][j][l], dis[i][k][l - 1] + dis[k][j][0]);
                }
            }
        }
    }
    int s, t, k;
    for (int i = 1; i <= r; i++)
    {
        std::cin >> s >> t >> k;
        std::cout << dis[s][t][std::min(k, n)] << '\n';
    }
    return 0;
}