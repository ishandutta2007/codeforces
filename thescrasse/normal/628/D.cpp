// 628D
// Magic Numbers

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], dp[2010][2010][2], c, d, jn;
string a, b, s;

void tr(ll i, ll j, ll d) {
    ll jn;
    jn = (10 * j + d) % m;
    dp[i + 1][jn][0] += dp[i][j][0];
    dp[i + 1][jn][0] %= mod;
    if ((ll)s[i] - 48 == d) {
        dp[i + 1][jn][1] += dp[i][j][1];
        dp[i + 1][jn][1] %= mod;
    } else if ((ll)s[i] - 48 > d) {
        dp[i + 1][jn][0] += dp[i][j][1];
        dp[i + 1][jn][0] %= mod;
    }
}

void upd(ll sgn) {
    ll i, j, k;

    for (i = 0; i <= n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][1] = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i % 2 == 1) {
                tr(i, j, d);
            } else {
                for (k = 0; k <= 9; k++) {
                    if (i + k == 0) continue;
                    if (k == d) continue;
                    tr(i, j, k);
                }
            }
        }
    }

    res += sgn * (dp[n][0][0] + dp[n][0][1]);
    res %= mod; res += mod; res %= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> m >> d >> a >> b;
    n = a.size();

    res = 0;
    s = b; upd(1); // cout << res << nl;

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 2; k++) {
                cout << i << ' ' << j << ' ' << k << ": " << dp[i][j][k] << nl;
            }
        }
    } */

    s = a; upd(-1); // cout << res << nl;
    flag[0] = 1; jn = 0;
    for (i = 0; i < n; i++) {
        jn = (10 * jn + (ll)a[i] - 48) % m;
        // cout << jn << nl;
        if (i % 2 == 1 && (ll)a[i] - 48 != d) flag[0] = 0;
        if (i % 2 == 0 && (ll)a[i] - 48 == d) flag[0] = 0;
    }
    if (jn == 0 && flag[0] == 1) res++;

    cout << res;

    return 0;
}