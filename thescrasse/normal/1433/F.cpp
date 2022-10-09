#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF 1e9
#define mod 998244353
#define maxn 71

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], r, l, x;
int dp[maxn][maxn][maxn][maxn], ps[maxn][maxn];

ll fx(ll x) {
    x %= r; x += r; x %= r;
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> r;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> mt[i][j];
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = m; k >= 0; k--) {
                for (l = 0; l < r; l++) {
                    dp[i][j][k][l] = -INF;
                    if (j == 0 && k == 0 && l == 0) dp[i][j][k][l] = 0;
                    if (j == 0) continue;
                    x = fx(l - mt[i][j]);
                    if (k > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k - 1][x] + (mt[i][j] / r) + (x > l));
                    dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l]);
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = 0; k <= m; k++) {
                for (l = 0; l < r; l++) {
                    if (dp[i][j][k][l] < 0) continue;
                    // cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << nl;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = 0; k <= m / 2; k++) {
                for (l = 0; l < r; l++) {
                    dp[i][j][0][l] = max(dp[i][j][0][l], dp[i][j][k][l]);
                }
            }
        }
    }

    /* cout << nl;
    for (i = 1; i <= n; i++) {
        for (l = 0; l < r; l++) {
            if (dp[i][m][0][l] < 0) continue;
            cout << i << ' ' << l << ' ' << dp[i][m][0][l] << nl;
        }
    }
    cout << nl; */

    for (i = 0; i <= n; i++) {
        for (j = 0; j < r; j++) {
            if (i + j != 0) ps[i][j] = -INF;
        }
    }

    for (j = 1; j <= n; j++) {
        for (k = 0; k < r; k++) {
            for (l = 0; l < r; l++) {
                x = fx(k + l);
                ps[j][x] = max(ps[j][x], ps[j - 1][k] + dp[j][m][0][l] + (k + l >= r));
            }
        }
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            if (ps[i][j] < 0) continue;
            cout << i << ' ' << j << ' ' << ps[i][j] << nl;
        }
    } */

    cout << r * ps[n][0] << nl;

    return 0;
}