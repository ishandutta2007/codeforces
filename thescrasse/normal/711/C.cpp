#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, d;
ll mt[maxn][maxn], dp[maxn][maxn][maxn], mn[maxn][maxn][maxn], m1, m2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> d;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
            if (a[i] != 0) mt[i][j] = 0;
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= m; k++) {
                dp[i][j][k] = INF; mn[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (k = 0; k <= m; k++) {
        mn[0][0][k] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= m; k++) {
                if (a[i] != 0 && a[i] != k) continue;
                dp[i][j][k] = min(dp[i - 1][j][k], mn[i - 1][j - 1][k]) + mt[i][k];
            }
            m1 = INF; m2 = INF;
            for (k = 1; k <= m; k++) {
                if (dp[i][j][k] < m1) {
                    m2 = m1; m1 = dp[i][j][k];
                } else if (dp[i][j][k] < m2) {
                    m2 = dp[i][j][k];
                }
            }
            for (k = 1; k <= m; k++) {
                if (dp[i][j][k] == m1) mn[i][j][k] = m2;
                else mn[i][j][k] = m1;
            }
        }
    }

    res = INF;
    for (k = 1; k <= m; k++) {
        res = min(res, dp[n][d][k]);
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 1; k <= m; k++) {
                cout << i _ j _ k _ dp[i][j][k] << nl;
            }
        }
    } */

    if (res >= INF) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}