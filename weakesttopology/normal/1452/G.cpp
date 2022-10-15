#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<int K>
class CentroidDecomposition
{
private:
    const int n;
    const vector<vector<int>>& E;

    vector<int> parent, weight, vis, level;
    vector<array<int, K>> dist;

    int dfs(int u, int p, int h)
    {
        if (h != -1) dist[u][h] = dist[p][h] + 1;

        weight[u] = 1;

        for (auto v : E[u]) if (not vis[v] && v != p)
            weight[u] += dfs(v, u, h);

        return weight[u];
    }
    int find_centroid(int u, int p, int cut)
    {
        for (auto v : E[u])
            if (not vis[v] && v != p && weight[v] > cut)
                return find_centroid(v, u, cut);
        return u;
    }
    void build(int u, int p)
    {
        int total = dfs(u, p, p == -1 ? -1 : level[p]);
        int centroid = find_centroid(u, p, total / 2);

        parent[centroid] = p, vis[centroid] = 1;

        if (p != -1) level[centroid] = level[p] + 1;

        dist[centroid][level[centroid]] = 0;

        for (auto v : E[centroid]) if (not vis[v])
            build(v, centroid);
    }
public:
    CentroidDecomposition(const vector<vector<int>>& E) :
        n(size(E)), E(E), parent(n, -1), weight(n, 0), vis(n, 0), level(n, 0), dist(n)
    {
        build(0, -1);
    }
    int operator[](int u) const { return parent[u]; }
    int getlevel(int u) const { return level[u]; }
    int lca(int u, int v) const // centroid lca, not tree lca
    {
        if (level[u] < level[v]) swap(u, v);
        while (level[u] > level[v]) u = parent[u];
        while (u != v) u = parent[u], v = parent[v];
        return u;
    }
    int distance(int u, int v) const
    {
        int w = lca(u, v);
        return dist[u][level[w]] + dist[v][level[w]];
    }
    int distance_level(int u, int k)
    {
        return dist[u][k];
    }
};

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector dist(n, -1);

    queue<int> q;

    int k; cin >> k;

    for (int j = 0; j < k; ++j)
    {
        int v; cin >> v; --v;
        q.push(v);
        dist[v] = 0;
    }

    while (not empty(q))
    {
        int u = q.front(); q.pop();
        for (auto v : E[u]) if (dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    CentroidDecomposition<18> cd(E);

    vector I(n, 0); iota(all(I), 0);

    sort(all(I), [&cd](int u, int v){ return cd.getlevel(u) < cd.getlevel(v); });

    vector vis(n, 0), val(n, -1);

    int hmax = -1;

    function<void(int, int, int)> build = [&](int u, int p, int h)
    {
        val[h] = max(val[h], dist[u]), hmax = max(hmax, h);

        for (auto v : E[u]) if (v != p && not vis[v])
            build(v, u, h + 1);
    };

    vector best(n, vector(0, 0));

    for (auto u : I)
    {
        build(u, u, 0);

        vis[u] = 1;

        best[u].resize(hmax + 1);

        for (int x = 0; x <= hmax; ++x)
            best[u][x] = val[x], val[x] = -1;

        for (int x = 1; x <= hmax; ++x)
            best[u][x] = max(best[u][x], best[u][x - 1]);

        hmax = -1;
    }

    auto check = [&](int u, int x)
    {
        for (int v = u, k = cd.getlevel(u); v != -1; v = cd[v], --k)
        {
            int cost = cd.distance_level(u, k);

            if (cost > x) continue;

            int y = min(size(best[v]) - 1, x - cost);

            if (best[v][y] > x) return true;
        }
        return false;
    };

    vector ans(n, 0);

    for (int u = 0; u < n; ++u) if (dist[u] != 0)
    {
        for (int z = n; z > 0; z >>= 1)
            while (check(u, ans[u] + z)) ans[u] += z;
        ans[u] += 1;
    }

    for (int u = 0; u < n; ++u)
        cout << ans[u] << (u + 1 < n ? " " : "\n");

    exit(0);
}