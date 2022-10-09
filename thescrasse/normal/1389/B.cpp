#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, z, dp[maxn][8];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m >> z;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        dp[0][0] = 0; res = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j <= z; j++) {
                dp[i][j] = 0;
                if (i >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i]);
                if (j >= 1 && i != n) dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i] + a[i + 1]);
                if (i + 2 * j == m) res = max(res, dp[i][j]);
            }
        }

        /* for (i = 0; i < n; i++) {
            for (j = 0; j <= z; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << nl;
        } */

        cout << res + a[0] << nl;
    }

    return 0;
}