#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
struct Edge
{
    int to, nxt, cost;
} e[400001];
int n, E, head[200001], dp[200001], ans = 0x7fffffff;
std::vector<int> v;
void Add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
void Dfs(int u, int fa)
{
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        Dfs(v, u);
        dp[u] += dp[v] + e[i].cost;
    }
}
void Dfs2(int u, int fa)
{
    if (dp[u] < ans)
    {
        ans = dp[u];
        std::vector<int>().swap(v);
        v.emplace_back(u);
    }
    else if (dp[u] == ans)
    {
        v.emplace_back(u);
    }
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dp[v] += dp[u] - dp[v];
        if (e[i].cost)
        {
            dp[v]--;
        }
        else
        {
            dp[v]++;
        }
        Dfs2(v, u);
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
        Add(u, v, 0);
        Add(v, u, 1);
    }
    Dfs(1, 0);
    Dfs2(1, 0);
    std::sort(v.begin(), v.end());
    std::cout << ans << '\n';
    for (auto &&i : v)
    {
        std::cout << i << ' ';
    }
    return 0;
}