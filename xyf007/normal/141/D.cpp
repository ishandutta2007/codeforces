#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
struct Ramp
{
    int x, d, t, p;
} a[100001];
struct Edge
{
    int to, nxt, cost, id;
} e[400001];
int n, L, E, head[200005], b[200005], tot, pre[200005], c[200005];
long long dis[200005];
bool vis[200005];
std::vector<int> v;
void Add(int f, int t, int c, int id = 0)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].id = id;
    e[E].nxt = head[f];
    head[f] = E++;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n >> L;
    b[tot = 2] = L;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].x >> a[i].d >> a[i].t >> a[i].p;
        if (a[i].x < a[i].p || a[i].x + a[i].d > L)
        {
            continue;
        }
        b[++tot] = a[i].x - a[i].p;
        b[++tot] = a[i].x + a[i].d;
    }
    std::sort(b + 1, b + tot + 1);
    tot = std::unique(b + 1, b + tot + 1) - b - 1;
    for (int i = 1; i < tot; i++)
    {
        Add(i, i + 1, b[i + 1] - b[i]);
        Add(i + 1, i, b[i + 1] - b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].x < a[i].p || a[i].x + a[i].d > L)
        {
            continue;
        }
        int u = std::lower_bound(b + 1, b + tot + 1, a[i].x - a[i].p) - b, v = std::lower_bound(b + 1, b + tot + 1, a[i].x + a[i].d) - b;
        Add(u, v, a[i].p + a[i].t, i);
    }
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
    std::memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0LL;
    q.emplace(0LL, 1);
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
                pre[v] = u;
                dis[v] = dis[u] + e[i].cost;
                c[v] = e[i].id;
                q.emplace(dis[v], v);
            }
        }
    }
    std::cout << dis[tot] << '\n';
    int p = tot;
    while (p)
    {
        if (c[p])
        {
            v.emplace_back(c[p]);
        }
        p = pre[p];
    }
    std::reverse(v.begin(), v.end());
    std::cout << v.size() << '\n';
    for (auto &&i : v)
    {
        std::cout << i << ' ';
    }
    return 0;
}