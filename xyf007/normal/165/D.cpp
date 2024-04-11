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
int n, m, E, head[100001], dep[100001], fa[100001], sz[100001], son[100001], top[100001], dfn[100001], tot, id[100001], pe[100001], sum[400001];
void Add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void Dfs(int u, int f)
{
    sz[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == f)
        {
            continue;
        }
        pe[i / 2 + 1] = v;
        Dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
        {
            son[u] = v;
        }
    }
}
void Dfs2(int u, int t)
{
    id[dfn[u] = ++tot] = u;
    top[u] = t;
    if (son[u])
    {
        Dfs2(son[u], t);
    }
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa[u] || v == son[u])
        {
            continue;
        }
        Dfs2(v, v);
    }
}
void Pushup(int x)
{
    sum[x] = sum[x + x] + sum[x + x + 1];
}
void Build(int l, int r, int x)
{
    if (l == r)
    {
        sum[x] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x);
    Build(mid + 1, r, x + x + 1);
    Pushup(x);
}
void Modify(int l, int r, int p, int v, int x)
{
    if (l == r)
    {
        sum[x] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        Modify(l, mid, p, v, x + x);
    }
    else
    {
        Modify(mid + 1, r, p, v, x + x + 1);
    }
    Pushup(x);
}
int Query(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        return sum[x];
    }
    int mid = (l + r) >> 1, ret = 0;
    if (L <= mid)
    {
        ret += Query(L, R, l, mid, x + x);
    }
    if (R > mid)
    {
        ret += Query(L, R, mid + 1, r, x + x + 1);
    }
    return ret;
}
int Query(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
        {
            std::swap(u, v);
        }
        ans += Query(dfn[top[u]], dfn[u], 1, n, 1);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
    {
        std::swap(u, v);
    }
    return ans + Query(dfn[u] + 1, dfn[v], 1, n, 1);
}
int GetLca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
        {
            std::swap(u, v);
        }
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        Add(u, v);
        Add(v, u);
    }
    Dfs(1, 0);
    Dfs2(1, 1);
    Build(1, n, 1);
    std::cin >> m;
    int op, x, y;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> op >> x;
        if (op == 1)
        {
            Modify(1, n, dfn[pe[x]], 1, 1);
        }
        else if (op == 2)
        {
            Modify(1, n, dfn[pe[x]], 0, 1);
        }
        else
        {
            std::cin >> y;
            int lca = GetLca(x, y), dis = dep[x] + dep[y] - 2 * dep[lca], cnt = Query(x, y);
            if (cnt == dis)
            {
                std::cout << cnt << '\n';
            }
            else
            {
                std::cout << "-1\n";
            }
        }
    }
    return 0;
}