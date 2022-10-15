#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds; // policy-based

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
    const vector<vector<pair<int, int>>>& E;

    vector<int> parent, weight, vis, level;
    vector<array<int, K + 1>> dist;

    int dfs(int u, int p, int h)
    {
        if (h != -1) dist[u][h] = dist[p][h] + 1;

        weight[u] = 1;

        for (auto [v, dummy] : E[u]) if (not vis[v] && v != p)
            weight[u] += dfs(v, u, h);

        return weight[u];
    }
    int find_centroid(int u, int p, int cut)
    {
        for (auto [v, dummy] : E[u])
            if (not vis[v] && v != p && weight[v] > cut)
                return find_centroid(v, u, cut);

        return u;
    }
    void build(int u, int p)
    {
        int total = dfs(u, p, p == -1 ? -1 : level[p]);
        int centroid = find_centroid(u, p, total / 2);

        if (p != -1) level[centroid] = level[p] + 1;

        parent[centroid] = p, vis[centroid] = 1;
        dist[centroid][level[centroid]] = 0;

        for (auto [v, dummy] : E[centroid]) if (not vis[v]) build(v, centroid);
    }
public:
    CentroidDecomposition(const auto& E) :
        n(size(E)), E(E), parent(n), weight(n), vis(n), level(n), dist(n)
    {
        build(0, -1);
    }
    int operator[](int u) const
    {
        return parent[u];
    }
    int getlevel(int u) const
    {
        return level[u];
    }
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
};

template<typename T>
auto invgcd(T a, T b)
{
    if ((a %= b) == 0) return pair(b, T(0));
    T s = b, t = a, x = 0, y = 1;
    while (t > 0)
    {
        T q = s / t;
        s -= t * q, x -= y * q;
        swap(s, t), swap(x, y);
    }
    if (x < 0) x += b / s;
    return pair(s, x);
}

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

struct custom_hash
{
    ll operator()(ll x) const
    {
        x ^= FIXED_RANDOM;
        return x ^ (x >> 32);
    }
};

template<typename T>
using hash_table = gp_hash_table<ll, T, custom_hash>;

int main()
{ _
    int n; cin >> n;
    ll mod; cin >> mod;

    if (mod == 1)
    {
        cout << 1LL * n * (n - 1) << endl;
        exit(0);
    }

    ll inv = invgcd<ll>(10, mod).second;

    assert((10 * inv) % mod == 1);

    vector<ll> invpow(n, 1LL), pow(n, 1LL);
    for (int x = 1; x < n; ++x)
    {
        pow[x] = pow[x - 1] * 10 % mod;
        invpow[x] = invpow[x - 1] * inv % mod;
    }

    vector<vector<pair<int, int>>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w; cin >> u >> v >> w; w = int(w % mod);
        E[u].emplace_back(v, w), E[v].emplace_back(u, w);
    }

    CentroidDecomposition<16> cd(E);

    vector<int> V(n), rem(n, 0);
    iota(all(V), 0);
    sort(all(V), [&cd](int u, int v){ return cd.getlevel(u) < cd.getlevel(v); });

    hash_table<int> up, down;
    vector<ll> place_up, place_down;

    auto get = [&](const auto& mp, ll key)
    {
        auto iter = mp.find(key);
        return iter == end(mp) ? 0 : iter->second;
    };

    ll ans = 0LL;

    function<void(int, int, ll, ll)> solve = [&](int u, int h, ll prefix_up, ll prefix_down)
    {
        ans += get(down, (mod - prefix_up) % mod);
        ans += get(up, (mod - prefix_down * invpow[h] % mod) % mod);

        place_up.push_back(prefix_up);
        place_down.push_back(prefix_down * invpow[h] % mod);

        rem[u] += 1;

        for (auto [v, w] : E[u]) if (not rem[v])
        {
            solve(v, h + 1, (prefix_up + w * pow[h]) % mod, (prefix_down * 10 + w) % mod);
        }

        rem[u] -= 1;
    };

    for (auto u : V)
    {
        rem[u] = 1;

        up[0] += 1, down[0] += 1;

        for (auto [v, w] : E[u]) if (not rem[v])
        {
            solve(v, 1, w, w);

            for (auto x : place_up) up[x] += 1;
            for (auto x : place_down) down[x] += 1;

            place_up.clear();
            place_down.clear();
        }

        up.clear(), down.clear();
    }

    cout << ans << endl;

    exit(0);
}