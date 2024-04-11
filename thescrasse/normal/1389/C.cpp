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
        cin >> s; n = s.size();
        for (i = 0; i < n; i++) {
            a[i + 1] = (ll)s[i] - 48;
        }

        res = 0;
        for (i = 0; i <= 9; i++) {
            for (j = 0; j <= 9; j++) {
                dp[0][0] = 0; dp[0][1] = 0;
                for (k = 1; k <= n; k++) {
                    dp[k][0] = dp[k - 1][0]; dp[k][1] = dp[k - 1][1];
                    if (a[k] == i) dp[k][0] = max(dp[k][0], dp[k - 1][1] + 1);
                    if (a[k] == j) dp[k][1] = max(dp[k][1], dp[k - 1][0] + 1);
                }

                // cout << i << ' ' << j << ' ' << dp[n][1] << nl;
                if (i != j && dp[n][1] % 2 == 1) dp[n][1]--;
                res = max(res, dp[n][1]);
            }
        }

        cout << n - res << nl;
    }

    return 0;
}