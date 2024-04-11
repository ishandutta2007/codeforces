#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <queue>
struct Edge
{
    int to, nxt;
} e[400001];
int n, m, k, E, head[100001], a[100001], s, t, dis[100001];
bool f[100001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void Add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
bool Check(int x)
{
    std::memset(dis, 0, sizeof(dis));
    dis[s] = x;
    std::priority_queue<std::pair<int, int>> q;
    q.emplace(x, s);
    while (!q.empty())
    {
        int w = q.top().first, u = q.top().second;
        q.pop();
        if (!w)
        {
            continue;
        }
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to, nw = w - 1;
            if (v == t)
            {
                return true;
            }
            if (f[v])
            {
                nw = x;
            }
            if (dis[v] < nw)
            {
                dis[v] = nw;
                q.emplace(nw, v);
            }
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        std::cin >> a[i];
        f[a[i]] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        Add(u, v);
        Add(v, u);
    }
    std::cin >> s >> t;
    int l = 1, r = n, best = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << best;
    return 0;
}