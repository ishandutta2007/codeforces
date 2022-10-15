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

int main()
{ _
    int n, m; cin >> n >> m;
    vector E(n, vector<int>());
    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    using ull = unsigned long long;
    uniform_int_distribution<ull> dist(3, 100000);
    ull p = dist(rng) | 1;

    map<ull, ull> H;
    vector<ull> z(n, p), h(n, 0);
    for (int i = 1; i < n; ++i)
        z[i] *= z[i - 1];

    for (int i = 0; i < n; ++i)
    {
        sort(E[i].begin(), E[i].end());
        for (auto j : E[i]) h[i] += z[j];
        H[h[i]] += 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        for (auto j : E[i])
            if (h[i] - z[j] == h[j] - z[i])
                ans += 1;
    ans /= 2;
    for (auto [k, v] : H)
        ans += v * (v - 1) / 2;
    cout << ans << endl;

    exit(0);
}