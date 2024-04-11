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

ll solve()
{
    int n;
    cin >> n;

    vector<vector<int>> E(n);

    for (int u = 1; u < n; ++u)
    {
        int v;
        cin >> v;
        --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<ll> a(n);
    for (int i = 1; i < n; ++i) cin >> a[i];

    vector<int> h(n, 0), p(n, -1);

    auto dfs = [&](auto& self, int u) -> void
    {
        for (auto v : E[u]) if (v != p[u])
        {
            h[v] = h[u] + 1, p[v] = u;
            self(self, v);
        }
    };
    dfs(dfs, 0);

    vector<ll> dp(n, 0LL), amin(n, LINF), amax(n, -LINF);
    vector<vector<int>> H(n);

    for (int u = 0; u < n; ++u)
    {
        int x = h[u];
        amin[x] = min(amin[x], a[u]);
        amax[x] = max(amax[x], a[u]);
        H[x].push_back(u);
    }

    auto cmp = [&](int u, int v){ return a[u] < a[v]; };

    for (int x = 1; x < n && not empty(H[x]); ++x)
    {
        sort(all(H[x]), cmp);

        ll prefix_max = -LINF;
        for (auto u : H[x])
        {
            dp[u] = dp[p[u]] + max(abs(a[u] - amin[x]), abs(a[u] - amax[x]));
            dp[u] = max(dp[u], prefix_max + a[u]);
            prefix_max = max(prefix_max, dp[p[u]] - a[u]);
        }

        reverse(all(H[x]));

        ll suffix_max = -LINF;
        for (auto u : H[x])
        {
            dp[u] = max(dp[u], suffix_max - a[u]);
            suffix_max = max(suffix_max, dp[p[u]] + a[u]);
        }
    }

    ll ans = *max_element(all(dp));

    return ans;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}