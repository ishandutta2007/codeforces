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

const ll MOD = 1e9 + 7;

ll solve()
{
    int n; cin >> n;
    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    int m; cin >> m;
    vector p(m, 0LL);
    for (int i = 0; i < m; ++i) cin >> p[i];

    while (m < n - 1) p.push_back(1LL), ++m;
    sort(all(p));
    while (m > n - 1)
    {
        ll x = p.back();
        p.pop_back();
        p.back() = (p.back() * x) % MOD;
        --m;
    }

    vector weight(0, 0LL), subtree(n, 0LL);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        subtree[u] = 1;
        for (auto v : E[u])
            if (v != p)
            {
                dfs(v, u);
                subtree[u] += subtree[v];
                weight.push_back(subtree[v] * (n - subtree[v]));
            }
    };
    dfs(0, 0);

    sort(all(weight));

    ll ans = 0;
    for (int j = 0; j < m; ++j)
        ans = (ans + weight[j] * p[j]) % MOD;
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}