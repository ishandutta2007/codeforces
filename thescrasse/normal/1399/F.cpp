// 1399F
// Yet Another Segments Subset

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 6010

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][maxn], l[maxn], r[maxn], f[200010], s;
vector<int> v;
vector<int> adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; v.clear();
        for (i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            v.pb(l[i]); v.pb(r[i]);
        }

        sort(v.begin(), v.end());
        for (i = 0; i < 2 * n; i++) {
            f[v[i]] = i; adj[i].clear();
        }
        for (i = 0; i < n; i++) {
            l[i] = f[l[i]]; r[i] = f[r[i]];
            adj[l[i]].pb(r[i]);
        }

        /* for (i = 0; i < n; i++) {
            cout << l[i] << ' ' << r[i] << nl;
        } */

        n *= 2;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        for (s = 0; s < n; s++) {
            for (i = 0; i < n; i++) {
                j = i + s;
                if (j >= n) continue;
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); flag[0] = 0;
                for (auto u : adj[i]) {
                    if (u > j) continue;
                    if (u == j) flag[0] = 1;
                    else dp[i][j] = max(dp[i][j], dp[i][u] + dp[u + 1][j]);
                }
                if (flag[0] == 1) dp[i][j]++;
                // cout << i << ' ' << j << ' ' << dp[i][j] << nl;
            }
        }

        /* for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << nl;
        } */

        cout << dp[0][n - 1] << nl;
    }

    return 0;
}