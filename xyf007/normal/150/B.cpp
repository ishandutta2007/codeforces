#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int n, m, k, fa[2001], sz[2001];
int Find(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    return fa[x] = Find(fa[x]);
}
void Merge(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if (fx == fy)
    {
        return;
    }
    fa[fx] = fy;
    sz[fy] += sz[fx];
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> k;
    std::iota(fa + 1, fa + n + 1, 1);
    std::fill(sz + 1, sz + n + 1, 1);
    for (int l = 1, r = k; r <= n; l++, r++)
    {
        int tl = l, tr = r;
        while (tl < tr)
        {
            Merge(tl++, tr--);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (Find(i) == i)
        {
            ans = ans * static_cast<long long>(m) % kMod;
        }
    }
    std::cout << ans;
    return 0;
}