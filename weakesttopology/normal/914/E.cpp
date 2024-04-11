#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

class CentroidDecomposition
{
private:
    const vector<vector<int>>& E;
    vector<int> par, subsz, level, vis;
    vector<vector<int>> dist;
    int dfs(int u, int p, int h)
    {
        if (h != -1) dist[u][h] = dist[p][h] + 1;
        subsz[u] = 1;
        for (auto v : E[u])
            if (not vis[v] && v != p) subsz[u] += dfs(v, u, h);
        return subsz[u];
    }
    int find_centroid(int u, int p, int sz)
    {
        for (auto v : E[u])
            if (not vis[v] && v != p && subsz[v] > sz / 2)
                return find_centroid(v, u, sz);
        return u;
    }
    void build(int u, int p)
    {
        int sz = dfs(u, p, p == -1 ? -1 : level[p]);
        int centroid = find_centroid(u, p, sz);
        par[centroid] = p, vis[centroid] = 1;
        if (p != -1) level[centroid] = level[p] + 1;
        for (auto v : E[centroid])
            if (not vis[v]) build(v, centroid);
    }
public:
    CentroidDecomposition(const vector<vector<int>>& E) : E(E)
    {
        int n = size(E);
        par.assign(n, -1), subsz.assign(n, 0), vis.assign(n, 0);
        level.assign(n, 0), dist.assign(n, vector(32 - __builtin_clz(n), 0));
        build(0, -1);
    }
    int operator[](int u) const { return par[u]; }
    int getlevel(int u) const { return level[u]; }
    int lca(int u, int v) // centroid lca, not tree lca
    {
        if (level[u] < level[v]) swap(u, v);
        while (level[u] > level[v]) u = par[u];
        while (u != v) u = par[u], v = par[v];
        return u;
    }
    int distance(int u, int v)
    {
        int w = lca(u, v);
        return dist[u][level[w]] + dist[v][level[w]];
    }
};

int main()
{ _
    int n; cin >> n;

    vector<vector<int>> E(n);

    for (int j = 0; j < n - 1; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector a(n, 0);

    for (int i = 0; i < n; ++i)
    {
        char c; cin >> c;
        a[i] = 1 << (c - 'a');
    }

    CentroidDecomposition cd(E);

    vector V(n, 0); iota(all(V), 0);
    sort(all(V), [&](int u, int v){ return cd.getlevel(u) < cd.getlevel(v); });

    vector ans(n, 1LL);

    constexpr int K = 20, N = 1 << K;

    vector cnt(N, 0), cntadd(N, 0), visreset(N, 0), visadd(N, 0), vis(n, 0);

    stack<int> stkreset, stkadd;

    auto reset = [&](int mask) { if (visreset[mask]++ == 0) stkreset.push(mask); };

    auto add = [&](int mask) { ++cntadd[mask]; if (visadd[mask]++ == 0) stkadd.push(mask); };

    function<ll(int, int, int)> dfs = [&](int u, int p, int prefix)
    {
        prefix ^= a[u];

        add(prefix);

        ll num = cnt[prefix];
        for (int j = 0; j < K; ++j)
            num += cnt[prefix ^ (1 << j)];

        for (auto v : E[u]) if (v != p && not vis[v])
            num += dfs(v, u, prefix);

        ans[u] += num;

        return num;
    };

    auto branch = [&](int u, bool sum)
    {
        int children = 0;
        if (sum) cnt[a[u]] = 1;
        for (auto v : E[u]) if (not vis[v])
        {
            ++children;
            ll num = dfs(v, u, 0);
            if (sum) ans[u] += num;
            while (not empty(stkadd))
            {
                int mask = stkadd.top(); stkadd.pop();
                cnt[mask ^ a[u]] += cntadd[mask], cntadd[mask] = visadd[mask] = 0;
                reset(mask ^ a[u]);
            }
        }
        if (sum) cnt[a[u]] = 0;
        while (not empty(stkreset))
        {
            int mask = stkreset.top(); stkreset.pop();
            cnt[mask] = visreset[mask] = 0;
        }
        return children;
    };

    for (auto u : V)
    {
        vis[u] = 1;
        int children = branch(u, true);
        if (children > 1)
        {
            reverse(all(E[u]));
            branch(u, false);
        }
    }

    for (int u = 0; u < n; ++u)
        cout << ans[u] << (u + 1 < n ? " " : "\n");

    exit(0);
}