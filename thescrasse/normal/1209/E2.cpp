// 1209E2
// Rotate Columns (hard version)

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[15][maxn], dp[4110][15], nw[15][15], mk, sb, vl[4110][15], r, sc;
array<ll, 2> mx[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (i = 0; i < m; i++) mx[i] = {0, i};

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> mt[i][j]; mx[j] = max(mx[j], {mt[i][j], j});
            }
        }

        sort(mx, mx + m); reverse(mx, mx + m);
        m = min(n, m);

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                nw[i][j] = mt[i][mx[j][1]];
            }
        }

        /* for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << nw[i][j] << ' ';
            }
            cout << nl;
        } */

        for (mk = 0; mk < (1 << n); mk++) {
            for (j = 0; j < m; j++) {
                vl[mk][j] = 0;
                for (r = 0; r < n; r++) {
                    sc = 0;
                    for (k = 0; k < n; k++) {
                        if (!((mk >> k) & 1)) continue;
                        sc += nw[(k + r) % n][j];
                    }
                    vl[mk][j] = max(vl[mk][j], sc);
                }
            }
        }

        for (mk = 0; mk < (1 << n); mk++) dp[mk][0] = vl[mk][0];

        for (j = 1; j < m; j++) {
            for (mk = 0; mk < (1 << n); mk++) {
                dp[mk][j] = 0;
                for (sb = mk;; sb = (sb - 1) & mk) {
                    dp[mk][j] = max(dp[mk][j], dp[sb][j - 1] + vl[mk ^ sb][j]);
                    if (sb == 0) break;
                }
            }
        }

        /* for (mk = 0; mk < (1 << n); mk++) {
            for (j = 0; j < m; j++) {
                cout << dp[mk][j] << ' ';
            }
            cout << nl;
        } */

        cout << dp[(1 << n) - 1][m - 1] << nl;
    }

    return 0;
}