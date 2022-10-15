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

    ll ans = 0LL;

    vector dp(n, vector(k, 0));
    vector subtree(n, 0);

    function<void(int)> compute = [&](int u)
    {
        dp[u][0] = subtree[u] = 1;

        for (auto v : E[u]) if (subtree[v] == 0)
        {
            compute(v);

            ans += 1LL * (n - subtree[v]) * subtree[v];

            subtree[u] += subtree[v];

            for (int r = 0; r < k; ++r)
                for (int s = 0; s < k; ++s) if (int x = (r + s) % k; x > 0)
                    ans += 1LL * dp[u][r] * dp[v][s] * (k - x);

            for (int r = 0; r < k; ++r) dp[u][r] += dp[v][r];
        }

        rotate(begin(dp[u]), prev(end(dp[u])), end(dp[u]));
    };

    compute(0);

    ans /= k;

    cout << ans << endl;

    exit(0);
}