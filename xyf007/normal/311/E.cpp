#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
constexpr int kInf = 2000000000;
struct Edge
{
    int to, nxt, cost;
} e[100001];
int n, m, g, a[10001], E, head[20001], s, t, cur[20001], dep[20001];
void Add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
bool Bfs()
{
    std::queue<int> q;
    memcpy(cur + 1, head + 1, 4 * (n + m + 2));
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.emplace(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dep[v] == -1 && e[i].cost)
            {
                dep[v] = dep[u] + 1;
                q.emplace(v);
            }
        }
    }
    return dep[t] != -1;
}
int Dfs(int u, int sum)
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
            int min = Dfs(v, std::min(sum, e[i].cost));
            if (min)
            {
                e[i].cost -= min;
                e[i ^ 1].cost += min;
                ans += min;
                sum -= min;
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
int Dinic()
{
    int ans = 0;
    while (Bfs())
    {
        ans += Dfs(s, kInf);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m >> g;
    s = n + m + 1;
    t = n + m + 2;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        if (!a[i])
        {
            Add(s, i, x);
            Add(i, s, 0);
        }
        else
        {
            Add(i, t, x);
            Add(t, i, 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int c, w, k, op, x;
        std::cin >> c >> w >> k;
        ans += w;
        for (int j = 1; j <= k; j++)
        {
            std::cin >> x;
            if (!c)
            {
                Add(n + i, x, kInf);
                Add(x, n + i, 0);
            }
            else
            {
                Add(x, n + i, kInf);
                Add(n + i, x, 0);
            }
        }
        std::cin >> op;
        if (!c)
        {
            Add(s, n + i, w + op * g);
            Add(n + i, s, 0);
        }
        else
        {
            Add(n + i, t, w + op * g);
            Add(t, n + i, 0);
        }
    }
    std::cout << ans - Dinic();
    return 0;
}