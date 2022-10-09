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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dp[maxn][2][2];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> s; n = s.size(); s = '#' + s;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= 1; j++) {
                for (k = 0; k <= 1; k++) {
                    dp[i][j][k] = (i == 0);
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 0; j <= 1; j++) {
                dp[i][1][j] = dp[i - 1][0][j];
            }
            k = (ll)s[i] - '0';
            if (k == 0) {
                dp[i][0][0] = max(dp[i - 1][0][k], dp[i - 1][1][k]);
            } else {
                dp[i][0][1] = max({dp[i - 1][0][0], dp[i - 1][1][0], dp[i - 1][0][1], dp[i - 1][1][1]});
            }
        }

        /* for (i = 1; i <= n; i++) {
            cout << dp[i][0][0] _ dp[i][0][1] _ dp[i][1][0] _ dp[i][1][1] << nl;
        } */

        if (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1] > 0) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}