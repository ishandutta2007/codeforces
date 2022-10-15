#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
constexpr int kDx[] = {1, 0, -1, 0}, kDy[] = {0, 1, 0, -1};
struct Query
{
    int x, y, c, pre;
} b[2000001];
int n, m, q, fa[4000001], a[305][305], ans[2000001], id[301][301], cnt, tmp;
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
    tmp--;
    fa[fx] = fy;
}
void Check(int x, int y)
{
    if (a[x][y] == a[x][y - 1])
    {
        Merge(id[x][y], id[x][y - 1]);
    }
    if (a[x][y] == a[x][y + 1])
    {
        Merge(id[x][y], id[x][y + 1]);
    }
    if (a[x][y] == a[x - 1][y])
    {
        Merge(id[x][y], id[x - 1][y]);
    }
    if (a[x][y] == a[x + 1][y])
    {
        Merge(id[x][y], id[x + 1][y]);
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
    {
        std::cin >> b[i].x >> b[i].y >> b[i].c;
        b[i].pre = a[b[i].x][b[i].y];
        a[b[i].x][b[i].y] = b[i].c;
    }
    ans[0] = 1;
    std::memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        std::memset(a[i] + 1, 0, 4 * m);
    }
    for (int i = 1; i <= q; i++)
    {
        if (b[i].c == b[i].pre)
        {
            continue;
        }
        tmp = 1;
        a[b[i].x][b[i].y] = b[i].c;
        id[b[i].x][b[i].y] = ++cnt;
        fa[cnt] = cnt;
        Check(b[i].x, b[i].y);
        ans[i] += tmp;
    }
    std::memset(fa, 0, sizeof(fa));
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            id[i][j] = ++cnt;
            fa[cnt] = cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            Check(i, j);
        }
    }
    for (int i = q; i >= 1; i--)
    {
        if (b[i].pre == b[i].c)
        {
            continue;
        }
        tmp = 1;
        a[b[i].x][b[i].y] = b[i].pre;
        id[b[i].x][b[i].y] = ++cnt;
        fa[cnt] = cnt;
        Check(b[i].x, b[i].y);
        ans[i] -= tmp;
    }
    std::partial_sum(ans, ans + q + 1, ans);
    for (int i = 1; i <= q; i++)
    {
        std::cout << ans[i] << '\n';
    }
    return 0;
}