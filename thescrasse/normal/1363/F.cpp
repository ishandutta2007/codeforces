// 1363F
// Rotating Substrings

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], dp[maxn][maxn];
ll tt[maxn], cn[maxn], x, st[maxn];
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> a >> b; a = '#' + a; b = '#' + b; flag[0] = 1;

        x = 0;
        for (i = 1; i <= 26; i++) tt[i] = 0;

        for (i = 1; i <= n; i++) {
            k = (ll)a[i] - 'a' + 1;
            tt[k]++; x += (tt[k] == 1);

            m = 0;
            for (j = 1; j <= 26; j++) cn[j] = 0;
            for (j = 1; j <= n; j++) {
                k = (ll)b[j] - 'a' + 1;
                cn[k]++; m += (tt[k] == cn[k]);
                if (x == m) break;
                if (j == n) flag[0] = 0;
            }
            st[i] = j;
        }

        if (flag[0] == 0) {
            cout << -1 << nl; continue;
        }

        // for (i = 1; i <= n; i++) cout << i _ st[i] << nl;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (st[i] <= j) * (a[i] == b[j])});
            }
        }

        /* for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << nl;
        } */

        res = n - dp[n][n];
        cout << res << nl;
    }

    return 0;
}