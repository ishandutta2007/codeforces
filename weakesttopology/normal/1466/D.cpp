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

void solve()
{
    int n; cin >> n;

    vector<ll> w(n);

    for (auto& x : w) cin >> x;

    vector<int> deg(n, -1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        deg[u] += 1, deg[v] += 1;
    }

    vector<int> V(n); iota(all(V), 0);
    sort(all(V), [&](int u, int v){ return pair(w[u], deg[u]) > pair(w[v], deg[v]); });

    vector<ll> ans(1, accumulate(all(w), 0LL));

    for (int i = 0, k = 1; k < n - 1; ++k)
    {
        while (i < n && deg[V[i]] == 0) ++i;
        if (i == n) break;

        ans.push_back(ans.back() + w[V[i]]);
        deg[V[i]] -= 1;
    }

    for (int k = 0; k < size(ans); ++k) cout << ans[k] << "\n "[k + 1 < n - 1];

    for (int k = size(ans); k < n - 1; ++k) cout << ans.back() << "\n "[k + 1 < n - 1];
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}