// 837D
// Round Subset

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 210

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[2][210][5210], p[maxn][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k1;
    for (i = 1; i <= n; i++) cin >> a[i];

    for (i = 1; i <= n; i++) {
        p[i][0] = 0; p[i][1] = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2; p[i][0]++;
        }
        while (a[i] % 5 == 0) {
            a[i] /= 5; p[i][1]++;
        }
    }

    res = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k < 5210; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            for (k = 0; k < 5210; k++) {
                dp[1][j][k] = max(dp[1][j][k], dp[0][j][k]);
                if (k >= p[i][1] && j >= 1) {
                    dp[1][j][k] = max(dp[1][j][k], dp[0][j - 1][k - p[i][1]] + p[i][0]);
                }
                if (j == k1) res = max(res, min(dp[1][j][k], k));
            }
        }
        for (j = 0; j <= n; j++) {
            for (k = 0; k < 5210; k++) {
                dp[0][j][k] = dp[1][j][k];
                /* if (dp[0][j][k] > 0) {
                    cout << j << ' ' << k << ' ' << dp[0][j][k] << endl;
                } */
            }
        }
    }

    cout << res;

    return 0;
}