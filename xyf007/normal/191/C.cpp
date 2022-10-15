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
int n, m, E, head[100001], dep[100001], sz[100001], son[100001], fa[100001], top[100001], pe[100001], d[100001], ans[100001];
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
        pe[v] = i >> 1;
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
void Dfs(int u)
{
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa[u])
        {
            continue;
        }
        Dfs(v);
        d[u] += d[v];
    }
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
    std::cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        d[u]++;
        d[v]++;
        d[GetLca(u, v)] -= 2;
    }
    Dfs(1);
    for (int i = 1; i <= n; i++)
    {
        ans[pe[i]] = d[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << ans[i] << ' ';
    }
    return 0;
}