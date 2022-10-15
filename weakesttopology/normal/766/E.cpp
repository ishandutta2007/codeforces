#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

const int N = 20;

using Counter = array<array<ll, 2>, N>;

class CentroidDecomposition
{
private:
    const vector<vector<int>>& E;
    vector<int> par, subsz, level, vis;
    vector<ll> ans, a;
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
    Counter compute(int u, int p, int XOR)
    {
        Counter ct;
        for (int b = 0; b < N; ++b)
        {
            int x = XOR >> b & 1;
            ct[b][x] = 1, ct[b][!x] = 0;
        }

        ans[u] = a[u];
        for (auto v : E[u])
            if (not vis[v] && v != p)
            {
                Counter inc = compute(v, u, XOR ^ a[v]);

                for (int b = 0; b < N; ++b)
                {
                    int x = a[u] >> b & 1;
                    for (int t = 0; t < 2; ++t)
                    {
                        ans[u] += ct[b][t] * inc[b][x ^ t ^ 1] * (1LL << b);
                        ct[b][t] += inc[b][t];
                    }
                }
            }

        return ct;
    }
    void build(int u, int p)
    {
        int sz = dfs(u, p, p == -1 ? -1 : level[p]);
        int centroid = find_centroid(u, p, sz);

        compute(centroid, centroid, 0);

        par[centroid] = p, vis[centroid] = 1;
        if (p != -1) level[centroid] = level[p] + 1;
        for (auto v : E[centroid])
            if (not vis[v]) build(v, centroid);
    }
public:
    CentroidDecomposition(const vector<vector<int>>& E, vector<ll>& a) : E(E), a(a)
    {
        int n = sz(E);
        par.assign(n, -1), subsz.assign(n, 0), vis.assign(n, 0);
        level.assign(n, 0), dist.assign(n, vector(32 - __builtin_clz(n), 0));
        ans.assign(n, 0LL);
        build(0, -1);
    }
    int operator[](int u) const { return par[u]; }
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
    ll total() const { return accumulate(all(ans), 0LL); }
};

int main()
{ _
    int n; cin >> n;

    vector a(n, 0LL);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    CentroidDecomposition cd(E, a);

    cout << cd.total() << endl;

    exit(0);
}