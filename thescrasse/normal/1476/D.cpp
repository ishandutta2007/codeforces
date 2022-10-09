#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn][2], b, dp[maxn][2][2];
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
        cin >> n >> s; s = '#' + s;

        for (i = 1; i <= n + 1; i++) {
            for (j = 0; j <= 1; j++) {
                a[i][j] = 0;
                for (k = 0; k <= 1; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }

        for (i = 1; i <= n; i++) {
            if (s[i] == 'L') a[i + 1][0] = 1;
            else a[i][1] = 1;
        }

        for (i = 2; i <= n + 1; i++) {
            dp[i][a[i][0] ^ 1][0] = dp[i - 1][a[i][0]][0] + 1;
        }

        for (i = n; i >= 1; i--) {
            dp[i][a[i][1] ^ 1][1] = dp[i + 1][a[i][1]][1] + 1;
        }

        /* for (i = 1; i <= n + 1; i++) {
            cout << i _ dp[i][0][0] _ dp[i][0][1] << nl;
        } */

        for (i = 1; i <= n + 1; i++) cout << dp[i][0][0] + dp[i][0][1] + 1 << ' ';
        cout << nl;
    }

    return 0;
}