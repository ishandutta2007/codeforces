// 1453F
// Even Harder

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 3010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == 1) dp[i][j] = 0;
                else dp[i][j] = INF;
            }
        }

        for (i = 2; i <= n; i++) {
            m = 0;
            for (j = i - 1; j >= 1; j--) {
                k = j + a[j];
                if (k >= i) {
                    dp[i][k] = min(dp[i][k], dp[j][i - 1] + m); m++;
                }
            }
            for (j = 2; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }

        cout << dp[n][n] << nl;
    }

    return 0;
}