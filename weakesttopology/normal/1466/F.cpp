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

template<typename T, bool memory_optimized = false>
struct DSU
{
private:
    vector<int> p, rk;
    vector<T> aggregate;
    const function<void(T&, T&)> merger;
    int components;
public:
    DSU(int n, T value, auto merger) : DSU(n, vector<T>(n, value), merger) { }
    DSU(int n, const vector<T>& aggregate, auto merger) :
        p(n), rk(n, 0), aggregate(aggregate), merger(merger), components(n)
    {
        iota(all(p), 0);
    }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    T& query(int u) { return aggregate[find(u)]; }
    int (size)() const { return components; }
    bool unite(int u, int v)
    {
        u = find(u), v = find(v);
        if (rk[u] < rk[v]) swap(u, v);
        if (u != v)
        {
            rk[u] += (rk[u] == rk[v]), p[v] = p[u];
            merger(aggregate[u], aggregate[v]);
            if (memory_optimized) aggregate[v].~T();
            return true;
        }
        return false;
    }
};

ll modpow(ll x, ll p, ll mod)
{
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

int main()
{ _
    int n, m; cin >> n >> m;

    DSU<int> dsu(m, 0, [](int& x, int y){ return x += y; });

    vector<int> basis;

    for (int i = 0; i < n; ++i)
    {
        int k; cin >> k;

        if (k == 1)
        {
            int u; cin >> u; --u;
            if (dsu.query(u)++ == 0) basis.push_back(i);
        }
        else
        {
            int u, v; cin >> u >> v; --u, --v;

            int su = dsu.query(u);
            int sv = dsu.query(v);

            if (dsu.unite(u, v) && min(su, sv) == 0) basis.push_back(i);
        }
    }

    int rk = size(basis);

    ll sz = modpow(2, rk, 1e9 + 7);

    cout << sz << " " << rk << endl;

    for (int j = 0; j < rk; ++j) cout << basis[j] + 1 << "\n "[j + 1 < rk];

    exit(0);
}