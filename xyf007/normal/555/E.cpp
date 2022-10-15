#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
struct edge
{
    int to, nxt;
} e[400001];
int n, m, E, head[200001], q, dfn[200001], low[200001], dfs_clock, col[200001], color, dep[200001], fa[200001][21], lg[200001], tag[200001], tot, s1[200001], s2[200001];
bool vis[400001];
vector<int> g[200001];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void tarjan(int u, int f)
{
    dfn[u] = low[u] = ++dfs_clock;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        if (i == f)
        {
            continue;
        }
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v, i ^ 1);
            checkmin(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                vis[i] = vis[i ^ 1] = 1;
            }
        }
        else
        {
            checkmin(low[u], dfn[v]);
        }
    }
}
void dfs1(int u, int c)
{
    col[u] = c;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        if (vis[i])
        {
            continue;
        }
        int v = e[i].to;
        if (col[v])
        {
            continue;
        }
        dfs1(v, c);
    }
}
void dfs(int u, int f)
{
    tag[u] = tot;
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto &&v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    while (dep[u] > dep[v])
    {
        u = fa[u][lg[dep[u] - dep[v]]];
    }
    if (u == v)
    {
        return u;
    }
    for (int i = lg[dep[u]]; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
bool check(int u, int f)
{
    for (auto &&v : g[u])
    {
        if (v == f)
        {
            continue;
        }
        if (!check(v, u) || (s1[v] && s2[v]))
        {
            return 0;
        }
        s1[u] += s1[v];
        s2[u] += s2[v];
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            dfs1(i, ++color);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (col[i] < col[v])
            {
                g[col[i]].push_back(col[v]);
                g[col[v]].push_back(col[i]);
            }
        }
    }
    for (int i = 1; i <= color; i++)
    {
        if (!tag[i])
        {
            tot++;
            dfs(i, 0);
        }
    }
    for (int i = 2; i <= 200000; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    while (q--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u = col[u];
        v = col[v];
        if (u == v)
        {
            continue;
        }
        if (tag[u] != tag[v])
        {
            printf("No");
            return 0;
        }
        int LCA = lca(u, v);
        s1[u]++;
        s1[LCA]--;
        s2[v]++;
        s2[LCA]--;
    }
    for (int i = 1; i <= color; i++)
    {
        if (dep[i] == 1 && !check(i, 0))
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}