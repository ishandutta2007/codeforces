#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int n, m; cin >> n >> m;

    vector E(n, vector(0, pair(0, 0)));

    for (int j = 0; j < m; ++j)
    {
        int u, v, t; cin >> u >> v >> t; --u, --v;
        E[v].push_back(pair(u, t));
    }

    vector dist(2, vector(n, INF)); dist[0][n - 1] = dist[1][n - 1] = 0;
    vector c(n, 0), dp(n, INF); dp[n - 1] = 0;

    using ii = pair<int, int>;
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(pair(0, n - 1));

    auto chmin = [](int& x, int y) { return x > y ? x = y, true : false; };
    // auto chmax = [](int& x, int y) { return x < y ? x = y, true : false; };

    while (not pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();

        if (d < dp[u]) continue;

        c[u] = dist[0][u] >= dist[1][u] ? 0 : 1;

        for (auto [v, t] : E[u])
            if (chmin(dist[t][v], dp[u] + 1))
            {
                dp[v] = max(dist[t][v], dist[t ^ 1][v]);
                pq.push(pair(dp[v], v));
            }
    }

    int ans = dp[0] == INF ? -1 : dp[0];

    cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << c[i];
    cout << endl;

    exit(0);
}