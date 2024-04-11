#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
struct Edge
{
    int to, nxt, cost;
} e[200001];
int n, m, s, l, E, head[100001], dis[100001];
bool vis[100001];
void Add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        Add(u, v, c);
        Add(v, u, c);
    }
    std::cin >> l;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    std::memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.emplace(0, s);
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dis[u] + e[i].cost < dis[v])
            {
                dis[v] = dis[u] + e[i].cost;
                q.emplace(dis[v], v);
            }
        }
    }
    double ans = std::count(dis + 1, dis + n + 1, l);
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (dis[i] + e[j].cost == dis[v] && dis[v] == l)
            {
                continue;
            }
            if (dis[i] < l)
            {
                if (dis[i] + dis[v] + e[j].cost == 2 * l)
                {
                    ans += 0.5;
                }
                else if (dis[i] + dis[v] + e[j].cost > 2 * l)
                {
                    ans += 1;
                }
            }
        }
    }
    std::cout << ans;
    return 0;
}