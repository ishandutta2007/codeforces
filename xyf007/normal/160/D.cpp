#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
struct Edge
{
    int u, v, cost, id;
} e[100001];
struct E2
{
    int to, cost, id;
    E2(int to = 0, int cost = 0, int id = 0) : to(to), cost(cost), id(id) {}
};
int n, m, fa[100001], sz[100001], son[100001], dep[100001], Fa[100001], top[100001], dfn[100001], tot, id[100001], tag[400001], ans[100001];
bool vis[100001];
std::vector<E2> g[100001];
std::pair<int, int> a[100001], max[400001];
template <typename T>
void checkmax(T &x, T y)
{
    if (x < y)
    {
        x = y;
    }
}
int Find(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    return fa[x] = Find(fa[x]);
}
void Dfs(int u, int f)
{
    sz[u] = 1;
    Fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto &&i : g[u])
    {
        int v = i.to;
        if (v == f)
        {
            continue;
        }
        a[v] = {i.cost, i.id};
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
    for (auto &&i : g[u])
    {
        int v = i.to;
        if (v == Fa[u] || v == son[u])
        {
            continue;
        }
        Dfs2(v, v);
    }
}
void Pushup(int x)
{
    max[x] = std::max(max[x + x], max[x + x + 1]);
}
void Build(int l, int r, int x)
{
    if (l == r)
    {
        max[x] = a[id[l]];
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x);
    Build(mid + 1, r, x + x + 1);
    Pushup(x);
}
std::pair<int, int> Query(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        return max[x];
    }
    int mid = (l + r) >> 1;
    std::pair<int, int> ret;
    if (L <= mid)
    {
        checkmax(ret, Query(L, R, l, mid, x + x));
    }
    if (R > mid)
    {
        checkmax(ret, Query(L, R, mid + 1, r, x + x + 1));
    }
    return ret;
}
int Query(int u, int v)
{
    int max = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
        {
            std::swap(u, v);
        }
        checkmax(max, Query(dfn[top[u]], dfn[u], 1, n, 1).first);
        u = Fa[top[u]];
    }
    if (dep[u] > dep[v])
    {
        std::swap(u, v);
    }
    return std::max(max, Query(dfn[u] + 1, dfn[v], 1, n, 1).first);
}
void Modify(int L, int R, int l, int r, int v, int x)
{
    if (max[x].first < v)
    {
        return;
    }
    if (L <= l && r <= R)
    {
        tag[x] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
    {
        Modify(L, R, l, mid, v, x + x);
    }
    if (R > mid)
    {
        Modify(L, R, mid + 1, r, v, x + x + 1);
    }
}
void Modify(int u, int v, int x)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
        {
            std::swap(u, v);
        }
        Modify(dfn[top[u]], dfn[u], 1, n, x, 1);
        u = Fa[top[u]];
    }
    if (dep[u] > dep[v])
    {
        std::swap(u, v);
    }
    Modify(dfn[u] + 1, dfn[v], 1, n, x, 1);
}
void Dfs(int l, int r, int x)
{
    if (l == r)
    {
        if (tag[x])
        {
            ans[max[x].second] = 2;
        }
        return;
    }
    if (tag[x])
    {
        if (max[x + x].first == max[x].first)
        {
            tag[x + x] = 1;
        }
        if (max[x + x + 1].first == max[x].first)
        {
            tag[x + x + 1] = 1;
        }
        tag[x] = 0;
    }
    int mid = (l + r) >> 1;
    Dfs(l, mid, x + x);
    Dfs(mid + 1, r, x + x + 1);
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    std::iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        std::cin >> e[i].u >> e[i].v >> e[i].cost;
        e[i].id = i;
    }
    std::sort(e + 1, e + m + 1, [](const Edge &x, const Edge &y) -> bool { return x.cost < y.cost; });
    for (int i = 1; i <= m; i++)
    {
        int fu = Find(e[i].u), fv = Find(e[i].v);
        if (fu == fv)
        {
            continue;
        }
        vis[i] = true;
        fa[fu] = fv;
        g[e[i].u].emplace_back(e[i].v, e[i].cost, e[i].id);
        g[e[i].v].emplace_back(e[i].u, e[i].cost, e[i].id);
    }
    Dfs(1, 0);
    Dfs2(1, 1);
    Build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        ans[e[i].id] = 1;
        if (vis[i])
        {
            continue;
        }
        int max = Query(e[i].u, e[i].v);
        if (max < e[i].cost)
        {
            ans[e[i].id] = 3;
        }
        else
        {
            ans[e[i].id] = 2;
            Modify(e[i].u, e[i].v, max);
        }
    }
    Dfs(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] == 1)
        {
            std::cout << "any\n";
        }
        else if (ans[i] == 2)
        {
            std::cout << "at least one\n";
        }
        else
        {
            std::cout << "none\n";
        }
    }
    return 0;
}