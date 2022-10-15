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

class DSU
{
private:
    vector<int> p, rk;
    int components;
public:
    DSU(int n) : p(n, 0), rk(n, 0), components(n)
    {
        for (int i = 0; i < n; ++i) p[i] = -1;
    }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    int find_size(int i) { return -p[find(i)]; }
    int (size)() const { return components; }
    void unite(int i, int j)
    {
        int x = find(i), y = find(j);
        if (rk[x] < rk[y]) swap(x, y);
        if (x != y)
        {
            --components;
            p[x] += p[y], p[y] = x;
            rk[x] += (rk[x] == rk[y]);
        }
    }
};

void fail(string s = "")
{
    debug(s);
    cout << 0 << endl;
    exit(0);
}

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

int main()
{ _
    int n, m; cin >> n >> m;

    DSU dsu(n);

    enum Relation { hate = 0, love = 1};

    vector<tuple<int, int, Relation>> edges(m);

    for (auto& [u, v, r] : edges)
    {
        cin >> u >> v; --u, --v;
        int rint; cin >> rint;

        r = rint ? love : hate;

        if (r == love) dsu.unite(u, v);
    }

    vector<vector<int>> E(n);

    for (auto [u, v, r] : edges) if (r == hate)
    {
        u = dsu.find(u), v = dsu.find(v);

        if (u == v) fail("hate from same component");

        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> color(n, -1);

    function<void(int)> paint = [&](int u)
    {
        for (auto v : E[u])
        {
            if (color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                paint(v);
            }
            else if (color[v] == color[u]) fail("not bipartite");
        }
    };

    int components = 0;

    for (int u = 0; u < n; ++u)
    {
        if (dsu.find(u) == u && color[u] == -1)
        {
            color[u] = 0;
            paint(u);
            components += 1;
        }
    }

    constexpr ll mod = 1e9 + 7;

    ll ans = modpow(2, components - 1, mod);

    cout << ans << endl;

    exit(0);
}