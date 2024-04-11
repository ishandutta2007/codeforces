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

int main()
{ _
    int n, k; cin >> n >> k;

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector h(n, -1), L(n, 0), R(n, 0);

    function<void(int)> dfs = [&](int u)
    {
        static int ct = 0;
        L[u] = ct;
        for (auto v : E[u]) if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            dfs(v);
        }
        R[u] = ct++;
    };

    h[0] = 0; dfs(0);

    vector I(n, 0); iota(all(I), 0);

    auto cmp = [&](int u, int v)
    {
        return h[u] - (R[u] - L[u]) > h[v] - (R[v] - L[v]);
    };
    sort(all(I), cmp);

    ll ans = 0LL;

    vector vis(n, 0);

    for (int j = k - 1; j >= 0; --j)
    {
        int u = I[j];

        if (vis[R[u]]) continue;

        ans += 1LL * h[u] * (R[u] - L[u] + 1);

        for (int x = L[u]; x <= R[u]; ++x) vis[x] = 1;
    }

    cout << ans << endl;

    exit(0);
}