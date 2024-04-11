#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn][2];

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
        for (i = 2; i <= n + 1; i++) {
            cin >> a[i];
        }

        dp[0][0] = 0; dp[1][0] = INF;
        dp[0][1] = INF; dp[1][1] = INF;

        for (i = 2; i <= n + 2; i++) {
            dp[i][0] = min(dp[i - 2][1] + (a[i - 2] == 1) + (a[i - 1] == 1), dp[i - 1][1] + (a[i - 1] == 1));
            dp[i][1] = min(dp[i - 2][0], dp[i - 1][0]);
        }

        // for (i = 0; i <= n + 2; i++) cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << nl;

        cout << min(dp[n + 2][0], dp[n + 2][1]) << nl;
    }

    return 0;
}