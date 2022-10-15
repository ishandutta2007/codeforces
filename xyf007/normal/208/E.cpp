#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
struct Edge
{
    int to, nxt;
} e[200001];
struct Node
{
    int ls, rs, sum;
} t[6000001];
int n, m, E, head[100001], fa[100001][18], dep[100001], in[100001], out[100001], tot, lg[100001], a[100001], root[100001], cnt;
void Add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void Dfs(int u)
{
    a[in[u] = ++tot] = dep[u];
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        dep[v] = dep[u] + 1;
        Dfs(v);
    }
    out[u] = tot;
}
void Pushup(int x)
{
    t[x].sum = t[t[x].ls].sum + t[t[x].rs].sum;
}
int Modify(int l, int r, int p, int x)
{
    int xx = ++cnt;
    t[xx].ls = t[x].ls;
    t[xx].rs = t[x].rs;
    t[xx].sum = t[x].sum + 1;
    if (l == r)
    {
        return xx;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        t[xx].ls = Modify(l, mid, p, t[x].ls);
    }
    else
    {
        t[xx].rs = Modify(mid + 1, r, p, t[x].rs);
    }
    Pushup(xx);
    return xx;
}
int Query(int l, int r, int p, int x1, int x2)
{
    if (l == r)
    {
        return t[x2].sum - t[x1].sum;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        return Query(l, mid, p, t[x1].ls, t[x2].ls);
    }
    else
    {
        return Query(mid + 1, r, p, t[x1].rs, t[x2].rs);
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> fa[i][0];
        Add(fa[i][0], i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!fa[i][0])
        {
            dep[i] = 1;
            Dfs(i);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        root[i] = Modify(1, n, a[i], root[i - 1]);
    }
    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, k, f;
        std::cin >> u >> k;
        f = u;
        for (int j = lg[n]; j >= 0; j--)
        {
            if ((k >> j) & 1)
            {
                f = fa[f][j];
            }
        }
        if (!f)
        {
            std::cout << "0 ";
            continue;
        }
        std::cout << Query(1, n, dep[u], root[in[f] - 1], root[out[f]]) - 1 << ' ';
    }
    return 0;
}