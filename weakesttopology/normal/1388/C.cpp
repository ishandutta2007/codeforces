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
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

typedef complex<ll> cp;

bool fail = false;
vll h, p;
cp dfs(const vector<vi>& E, int u, int r)
{
    cp a = 0;
    for (auto v : E[u])
        if (v != r)
            a += dfs(E, v, u);

    ll T = a.imag() + p[u];
    ll G = (h[u] + T) / 2;

    if (a.real() > G || G > T || G < 0 || 2 * G != h[u] + T)
        fail = true;

    return cp(G, T);
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        p.assign(n, 0); read(p);
        h.assign(n, 0); read(h);
        fail = false;

        vector<vi> E(n);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v; cin >> u >> v; --u, --v;
            E[u].push_back(v), E[v].push_back(u);
        }

        dfs(E, 0, 0);
        if (fail) cout << "NO\n";
        else cout << "YES\n";
    }
    exit(0);
}