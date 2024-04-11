#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 31607
#define maxn 25

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], mk, d1, d2, d1p, d2p, rp[maxn];
ll nv[31617], rps[maxn], dp[maxn][2], cn;
bool vis[maxn][maxn];

ll fxp(ll b, ll e) {
    ll r = 1, k = b;
    while (e != 0) {
        if (e % 2) r = (r * k) % mod;
        k = (k * k) % mod; e /= 2;
    }
    return r;
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i < mod; i++) nv[i] = inv(i);

    cin >> n;
    d1p = 1; d2p = 1;
    for (i = 1; i <= n; i++) rp[i] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> mt[i][j]; mt[i][j] = (mt[i][j] * nv[10000]) % mod;
            rp[i] = (rp[i] * mt[i][j]) % mod;
            if (i == j) d1p = (d1p * mt[i][j]) % mod;
            if (i + j == n + 1) d2p = (d2p * mt[i][j]) % mod;
            // cout << mt[i][j] << ' ';
        }
        // cout << nl;
    }

    for (i = 1; i <= n; i++) rps[i] = rp[i];

    for (d1 = 0; d1 <= 1; d1++) {
        for (d2 = 0; d2 <= 1; d2++) {
            for (mk = 0; mk < (1 << n); mk++) {
                if (mk == 0) {
                    k = 1; cn = d1 + d2;
                    for (i = 1; i <= n; i++) rp[i] = rps[i];
                    for (i = 1; i <= n; i++) {
                        for (j = 1; j <= n; j++) {
                            vis[i][j] = false;
                        }
                    }
                    if (d1 == 1) {
                        k = (k * d1p) % mod;
                        for (i = 1; i <= n; i++) {
                            vis[i][i] = true;
                            rp[i] = (rp[i] * nv[mt[i][i]]) % mod;
                        }
                    }
                    if (d2 == 1) {
                        k = (k * d2p) % mod;
                        for (i = 1; i <= n; i++) {
                            vis[i][n - i + 1] = true;
                            rp[i] = (rp[i] * nv[mt[i][n - i + 1]]) % mod;
                        }
                    }
                    if (d1 == 1 && d2 == 1 && n % 2 == 1) {
                        k = (k * nv[mt[n / 2 + 1][n / 2 + 1]]) % mod;
                        rp[n / 2 + 1] = (rp[n / 2 + 1] * mt[n / 2 + 1][n / 2 + 1]) % mod;
                    }
                } else {
                    for (i = 1; i <= n; i++) {
                        if ((mk >> (i - 1)) & 1) {
                            cn++;
                            for (j = 1; j <= n; j++) {
                                if (!vis[j][i]) {
                                    k = (k * mt[j][i]) % mod;
                                    rp[j] = (rp[j] * nv[mt[j][i]]) % mod;
                                }
                            }
                            break;
                        } else {
                            cn--;
                            for (j = 1; j <= n; j++) {
                                if (!vis[j][i]) {
                                    k = (k * nv[mt[j][i]]) % mod;
                                    rp[j] = (rp[j] * mt[j][i]) % mod;
                                }
                            }
                        }
                    }
                }
                cn %= 2;
                if (cn < 0) cn += 2;

                dp[0][cn] = k; dp[0][cn ^ 1] = 0;
                for (i = 1; i <= n; i++) {
                    for (j = 0; j <= 1; j++) {
                        dp[i][j] = (rp[i] * dp[i - 1][j ^ 1]) % mod;
                        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    }
                }

                /* cout << "d1, d2, mk, cn, k = " << d1 _ d2 _ mk _ cn _ k << nl;
                for (i = 1; i <= n; i++) cout << rp[i] << ' ';
                cout << nl;
                for (i = 0; i <= n; i++) {
                    cout << dp[i][0] _ dp[i][1] << nl;
                } */

                res = (res + dp[n][1] - dp[n][0] + mod) % mod;
            }
        }
    }

    res = (res + 1) % mod;
    cout << res << nl;

    return 0;
}