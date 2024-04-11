// 1368E
// Ski Accidents

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn];
vector<ll> adj[maxn], r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        r.clear();
        cin >> n >> m;
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < m; i++) {
            cin >> a >> b;
            adj[b].pb(a);
        }

        for (i = 1; i <= n; i++) {
            dp[i] = 0;
            for (auto u : adj[i]) {
                if (dp[u] == 2) continue;
                dp[i] = max(dp[i], dp[u] + 1);
            }
            if (dp[i] == 2) r.pb(i);
        }

        cout << r.size() << nl;
        for (auto u : r) {
            cout << u << ' ';
        }
        cout << nl;
    }

    return 0;
}