// 1327F
// AND Segments

#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

int i, i1, j, k, k1, t, n, m, flag[10], a, b, l, r, x, s, sz, d[maxn], e[maxn], f[maxn];
ll res, dp[maxn];
int mk[maxn];
vector<array<int, 2>> adj[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> m;
    for (i = 0; i < m; i++) {
        cin >> d[i] >> e[i] >> f[i];
    }

    res = 1;
    for (b = 0; b < k; b++) {
        adj[0].clear(); adj[1].clear();

        for (i = 0; i < m; i++) adj[(f[i] >> b) & 1].pb({e[i], d[i]});

        sort(adj[0].begin(), adj[0].end());

        for (i = 1; i <= n + 1; i++) mk[i] = 0;

        for (auto u : adj[1]) {
            mk[u[1]]++; mk[u[0] + 1]--;
        }

        for (i = 1; i <= n + 1; i++) mk[i] += mk[i - 1];

        s = adj[0].size(); x = 0; l = 0; dp[0] = 1;

        /* cout << "b = " << b << nl;
        for (auto u : adj[b][0]) {
            cout << u[0] << ' ' << u[1] << nl;
        } */

        /* for (i = 1; i <= n; i++) cout << mk[i] << ' ';
        cout << nl; */

        for (i = 1; i <= n + 1; i++) {
            if (mk[i]) {
                // cout << "i, x, dp = " << i << ' ' << x << ' ' << dp[i - 1] << nl;
                dp[i] = dp[i - 1]; continue;
            }

            while (l < s && adj[0][l][0] < i) {
                x = max(x, adj[0][l][1]); l++;
            }
            dp[i] = (2 * dp[i - 1] - dp[x - 1] + mod) % mod;
            // cout << "i, x, dp = " << i << ' ' << x << ' ' << dp[i] << nl;
        }

        res *= (dp[n + 1] - dp[n] + mod); res %= mod;
    }

    cout << res << nl;

    return 0;
}