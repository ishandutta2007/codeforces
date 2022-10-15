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
} e[10001];
int n, m, E, head[101], dis[101];
long long dp[101], dp2[101], cnt[5001];
bool vis[101];
std::vector<int> ve;
void checkmax(long long &x, long long y)
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
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        Add(u, v);
        Add(v, u);
    }
    std::memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    dp[1] = 1;
    std::queue<int> q;
    q.emplace(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                dp[v] = dp[u];
                q.emplace(v);
            }
            else if (dis[u] + 1 == dis[v])
            {
                dp[v] += dp[u];
            }
        }
    }
    dp2[n] = 1;
    q.emplace(n);
    vis[n] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (dis[v] == dis[u] - 1)
            {
                dp2[v] += dp2[u];
                if (!vis[v])
                {
                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (dis[v] == dis[i] + 1)
            {
                cnt[j >> 1] = dp[i] * dp2[v];
            }
        }
    }
    long long max = 0LL;
    for (int i = 1; i <= n; i++)
    {
        long long tmp = 0LL;
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            tmp += cnt[j >> 1];
        }
        checkmax(max, tmp);
    }
    std::cout << std::setprecision(8) << std::fixed << max / static_cast<double>(dp[n]);
    return 0;
}