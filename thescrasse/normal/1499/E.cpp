#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], dp[maxn][maxn][3][2][2], l, v0, v1;
string a, b;
char c1, c2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> a >> b; n = a.size(); m = b.size(); a = '#' + a; b = '#' + b;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j][2][0][0] = 1;
        }
    }

    /* for (j = 1; j <= m; j++) dp[0][j][1] = 1;
    for (i = 1; i <= n; i++) dp[i][0][0] = 1; */

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = 0; k <= 1; k++) {
                if (i + k == 0) continue;
                if (j - k + 1 == 0) continue;
                // cout << i _ j _ k _ dp[i][j][k] << nl;
                for (l = 0; l <= 2; l++) {
                    for (v0 = 0; v0 <= 1; v0++) {
                        for (v1 = 0; v1 <= 1; v1++) {
                            if (l == 0 && v0 == 0) continue;
                            if (l == 1 && v1 == 0) continue;
                            if (l != 2) {
                                if (k == 0) c1 = a[i];
                                else c1 = b[j];
                                if (l == 0) c2 = a[i - (k == 0)];
                                else c2 = b[j - (k == 1)];
                                // cout << c1 _ c2 << nl;
                                if (c1 == c2) continue;
                            }
                            dp[i][j][k][max(v0, (ll)(k == 0))][max(v1, (ll)(k == 1))] += dp[i - (ll)(k == 0)][j - (ll)(k == 1)][l][v0][v1];
                            dp[i][j][k][max(v0, (ll)(k == 0))][max(v1, (ll)(k == 1))] %= mod;
                            if (min(max(v0, (ll)(k == 0)), max(v1, (ll)(k == 1))) > 0) {
                                // cout << dp[i - (k == 0)][j - (k == 1)][l] << nl;
                                res += dp[i - (k == 0)][j - (k == 1)][l][v0][v1];
                                res %= mod;
                            }
                        }
                    }
                }
                // cout << i _ j _ k _ dp[i][j][k] << nl;
                // cout << nl;
            }
        }
    }

    cout << res << nl;

    return 0;
}