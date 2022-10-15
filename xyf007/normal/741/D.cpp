#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
struct Edge
{
    int to, nxt, cost;
} e[1000001];
int n, E, head[500001], dis[500001], dep[500001], sz[500001], son[500001], maxd[4194304], ans[500001], in[500001], out[500001], tot, id[500001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void Add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
void Dfs(int u)
{
    sz[u] = 1;
    id[in[u] = ++tot] = u;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        dep[v] = dep[u] + 1;
        dis[v] = dis[u] ^ e[i].cost;
        Dfs(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]])
        {
            son[u] = v;
        }
    }
    out[u] = tot;
}
void Solve(int u, bool op)
{
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == son[u])
        {
            continue;
        }
        Solve(v, false);
        checkmax(ans[u], ans[v]);
    }
    if (son[u])
    {
        Solve(son[u], true);
        checkmax(ans[u], ans[son[u]]);
    }
    if (maxd[dis[u]])
    {
        checkmax(ans[u], maxd[dis[u]] - dep[u]);
    }
    for (int i = 0; i < 22; i++)
    {
        if (maxd[dis[u] ^ (1 << i)])
        {
            checkmax(ans[u], maxd[dis[u] ^ (1 << i)] - dep[u]);
        }
    }
    checkmax(maxd[dis[u]], dep[u]);
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == son[u])
        {
            continue;
        }
        for (int j = in[v]; j <= out[v]; j++)
        {
            int k = id[j];
            if (maxd[dis[k]])
            {
                checkmax(ans[u], maxd[dis[k]] + dep[k] - 2 * dep[u]);
            }
            for (int l = 0; l < 22; l++)
            {
                if (maxd[dis[k] ^ (1 << l)])
                {
                    checkmax(ans[u], maxd[dis[k] ^ (1 << l)] + dep[k] - 2 * dep[u]);
                }
            }
        }
        for (int j = in[v]; j <= out[v]; j++)
        {
            int k = id[j];
            checkmax(maxd[dis[k]], dep[k]);
        }
    }
    if (!op)
    {
        for (int i = in[u]; i <= out[u]; i++)
        {
            int v = id[i];
            maxd[dis[v]] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int f;
        char c;
        std::cin >> f >> c;
        Add(f, i, 1 << (c - 'a'));
    }
    Dfs(1);
    Solve(1, true);
    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << ' ';
    }
    return 0;
}