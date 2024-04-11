#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
int n, k, q, a[12][100001];
std::bitset<4096> f[100015];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k >> q;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
        }
    }
    for (int S = 0; S < (1 << k); S++)
    {
        for (int i = 0; i < k; i++)
        {
            if ((S >> i) & 1)
            {
                f[i].set(S);
            }
        }
    }
    int cnt = k;
    while (q--)
    {
        int t, x, y;
        std::cin >> t >> x >> y;
        x--;
        y--;
        if (t == 1)
        {
            f[cnt++] = f[x] | f[y];
        }
        else if (t == 2)
        {
            f[cnt++] = f[x] & f[y];
        }
        else
        {
            std::pair<int, int> tmp[12];
            for (int i = 0; i < k; i++)
            {
                tmp[i] = {a[i][y], i};
            }
            std::sort(tmp, tmp + k, std::greater<std::pair<int, int>>());
            int S = 0;
            for (int i = 0; i < k; i++)
            {
                S |= 1 << tmp[i].second;
                if (f[x].test(S))
                {
                    std::cout << tmp[i].first << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}