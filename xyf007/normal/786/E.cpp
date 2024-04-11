#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int inf = 2e9;
struct edge
{
    int to, nxt;
} e[200001];
int n, m, E, head[20001], dep[20001], f[20001], lg[20001], fa[20001][17], id[20001][17], tot;
vector<int> a, b;
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
namespace maxflow
{
    int s, t, E, head[1000001], dep[1000001], cur[1000001];
    bool vis[1000001];
    struct edge
    {
        int to, nxt, cost;
    } e[5000001];
    void init()
    {
        memset(head, -1, sizeof(head));
        s = 0;
        t = 99999;
        tot = m + n - 1;
    }
    void add(int u, int v, int c)
    {
        e[E].to = v;
        e[E].cost = c;
        e[E].nxt = head[u];
        head[u] = E++;
    }
    bool bfs()
    {
        queue<int> q;
        memset(dep, 0, sizeof(dep));
        for (int i = 0; i <= tot; i++)
        {
            cur[i] = head[i];
        }
        cur[99999] = head[99999];
        q.push(s);
        dep[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i != -1; i = e[i].nxt)
            {
                int v = e[i].to;
                if (e[i].cost && !dep[v])
                {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t];
    }
    int dfs(int u, int sum)
    {
        if (u == t || !sum)
        {
            return sum;
        }
        int ans = 0;
        for (int i = cur[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dep[v] == dep[u] + 1 && e[i].cost)
            {
                int minn = dfs(v, min(sum, e[i].cost));
                if (minn)
                {
                    e[i].cost -= minn;
                    e[i ^ 1].cost += minn;
                    ans += minn;
                    sum -= minn;
                    if (!sum)
                    {
                        break;
                    }
                }
            }
            cur[u] = e[i].nxt;
        }
        if (!ans)
        {
            dep[u] = -1;
        }
        return ans;
    }
    void dinic()
    {
        int ans = 0;
        while (bfs())
        {
            ans += dfs(s, 2e9);
        }
        printf("%d\n", ans);
    }
    void calc()
    {
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i != -1; i = e[i].nxt)
            {
                int v = e[i].to;
                if (vis[v] || !e[i].cost)
                {
                    continue;
                }
                q.push(v);
                vis[v] = 1;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (!vis[i])
            {
                a.push_back(i);
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (vis[m + i])
            {
                b.push_back(i);
            }
        }
    }
} // namespace maxflow
void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; (1 << i) <= dep[u]; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        id[u][i] = ++tot;
        maxflow::add(id[u][i], id[u][i - 1], inf);
        maxflow::add(id[u][i - 1], id[u][i], 0);
        maxflow::add(id[u][i], id[fa[u][i - 1]][i - 1], inf);
        maxflow::add(id[fa[u][i - 1]][i - 1], id[u][i], 0);
    }
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == f)
        {
            continue;
        }
        id[v][0] = m + i / 2 + 1;
        maxflow::add(id[v][0], maxflow::t, 1);
        maxflow::add(maxflow::t, id[v][0], 0);
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
    for (int i = lg[dep[u]] - 1; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void add_link(int u, int v, int p)
{
    while (dep[u] > dep[v])
    {
        maxflow::add(p, id[u][lg[dep[u] - dep[v]]], inf);
        maxflow::add(id[u][lg[dep[u] - dep[v]]], p, 0);
        u = fa[u][lg[dep[u] - dep[v]]];
    }
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    maxflow::init();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        maxflow::add(0, i, 1);
        maxflow::add(i, 0, 0);
        int u, v, LCA;
        scanf("%d%d", &u, &v);
        LCA = lca(u, v);
        add_link(u, LCA, i);
        add_link(v, LCA, i);
    }
    maxflow::dinic();
    maxflow::calc();
    printf("%d ", (int)a.size());
    for (auto &&i : a)
    {
        printf("%d ", i);
    }
    printf("\n%d ", (int)b.size());
    for (auto &&i : b)
    {
        printf("%d ", i);
    }
    return 0;
}