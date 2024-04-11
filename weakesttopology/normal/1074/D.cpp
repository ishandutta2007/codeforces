#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; // policy-based

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

struct custom_hash
{
    int operator()(int x) const
    {
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

template<typename T>
using hash_table = gp_hash_table<int, T, custom_hash>;

struct DSU
{
    hash_table<int> p, rk;
    int find(int u)
    {
        if (p.find(u) == end(p)) return p[u] = u;
        while (u != p[u]) u = p[u];
        return u;
    }
    int unite(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v) return -1;
        if (rk[u] < rk[v]) swap(u, v);
        p[v] = u, rk[u] += rk[u] == rk[v];
        return v;
    }
};

int main()
{ _
    DSU dsu;
    hash_table<int> a;

    int q, last = 0;
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        int t, u, v;
        cin >> t >> u >> v;
        u ^= last, v ^= last;
        if (u > v) swap(u, v);
        v += 1;

        if (t == 1)
        {
            int x;
            cin >> x;
            x ^= last;
            if (dsu.find(u) == dsu.find(v)) continue;

            for (int w : {u, v})
            {
                while (w != dsu.p[w]) x ^= a[w], w = dsu.p[w];
            }
            a[dsu.unite(u, v)] = x;
        }
        else
        {
            int res = 0;
            if (dsu.find(u) != dsu.find(v)) res = -1, last = 1;
            else
            {
                while (u != v)
                {
                    if (dsu.rk[u] < dsu.rk[v]) swap(u, v);
                    res ^= a[v], v = dsu.p[v];
                }
                last = res;
            }
            cout << res << endl;
        }
    }

    exit(0);
}