#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct edge
{
    int from, to, cost;
    bool operator<(const edge a) const
    {
        return cost < a.cost;
    }
} e[1000001];
int n, k, m, fa[500001], dep[500001], val[500001];
bool vis[1000001];
vector<pair<int, int>> g[500001];
namespace disjoint_set
{
    int fa[500001];
    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }
    int find(int x)
    {
        if (x == fa[x])
        {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
} // namespace disjoint_set
void dfs(int u, int f)
{
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (auto &&i : g[u])
    {
        int v = i.first;
        if (v == f)
        {
            continue;
        }
        val[v] = i.second;
        dfs(v, u);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d", &e[i].from, &e[i].to);
    }
    for (int i = k + 1; i <= k + m; i++)
    {
        scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].cost);
    }
    sort(e + 1, e + k + m + 1);
    disjoint_set::init();
    for (int i = 1; i <= k + m; i++)
    {
        int fx = disjoint_set::find(e[i].from), fy = disjoint_set::find(e[i].to);
        if (fx == fy)
        {
            continue;
        }
        vis[i] = 1;
        disjoint_set::fa[fx] = fy;
    }
    for (int i = 1; i <= k + m; i++)
    {
        if (vis[i])
        {
            g[e[i].from].push_back(make_pair(e[i].to, e[i].cost));
            g[e[i].to].push_back(make_pair(e[i].from, e[i].cost));
        }
    }
    dfs(1, 0);
    disjoint_set::init();
    long long ans = 0;
    int cnt = 0;
    for (int i = k + 1; i <= k + m; i++)
    {
        if (vis[i])
        {
            continue;
        }
        int u = disjoint_set::find(e[i].from), v = disjoint_set::find(e[i].to), w = e[i].cost;
        while (u != v)
        {
            if (dep[u] < dep[v])
            {
                swap(u, v);
            }
            if (!val[u])
            {
                val[u] = w;
                ans += w;
                cnt++;
            }
            int f = disjoint_set::find(fa[u]);
            disjoint_set::fa[u] = f;
            u = disjoint_set::find(u);
        }
    }
    if (cnt < k)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", ans);
    }
    return 0;
}