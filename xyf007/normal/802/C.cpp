#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct edge
{
    int to, nxt, cost, flow;
    edge(int to = 0, int nxt = -1, int cost = 0, int flow = 0) : to(to), nxt(nxt), cost(cost), flow(flow) {}
} e[200001];
int n, k, s, t, a[1001], c[1001], E, head[1001], dis[1001], flow[1001], pre[1001], last[1001], Pre[1001];
bool vis[1001];
void add(int u, int v, int w, int c)
{
    e[E].to = v;
    e[E].cost = c;
    e[E].flow = w;
    e[E].nxt = head[u];
    head[u] = E++;
}
bool spfa()
{
    queue<int> q;
    memset(dis, 0x7f, sizeof(dis));
    memset(flow, 0x7f, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    pre[t] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (e[i].flow > 0 && dis[v] > dis[u] + e[i].cost)
            {
                dis[v] = dis[u] + e[i].cost;
                pre[v] = u;
                last[v] = i;
                flow[v] = min(flow[u], e[i].flow);
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return pre[t] != -1;
}
void solve()
{
    int minn = 0;
    while (spfa())
    {
        int now = t;
        minn += flow[t] * dis[t];
        while (now != s)
        {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
    }
    printf("%d", minn);
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &k);
    s = 0;
    t = 2 * n + 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        add(s, i, 1, c[a[i]]);
        add(i, s, 0, -c[a[i]]);
        add(i, i + n, 1, 0);
        add(i + n, i, 0, 0);
        add(i + n, t, 1, 0);
        add(t, i + n, 0, 0);
        if (Pre[a[i]])
        {
            add(i - 1, Pre[a[i]] + n, 1, -c[a[i]]);
            add(Pre[a[i]] + n, i - 1, 0, c[a[i]]);
        }
        Pre[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        add(i, i + 1, k - 1, 0);
        add(i + 1, i, 0, 0);
    }
    solve();
    return 0;
}//