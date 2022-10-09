#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, n, m, res, flag[10], a, b, dp[maxn][maxn];
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> s >> t; s = '#' + s; t = '#' + t;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (min(i, j) == 0) continue;

            dp[i][j] = max({dp[i][j], dp[i - 1][j] - 1, dp[i][j - 1] - 1});
            if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);

            res = max(res, dp[i][j]);
        }
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    cout << res;

    return 0;
}