// 1237F
// Balanced Domino Placements

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 3610

ll i, i1, j, k, k1, t, n, m[2], res, flag[10], a, b, x, y;
ll mk[2][maxn], dp[2][maxn][maxn], ty, tt[2], fc[maxn], nv[maxn];

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2) {
        r = fxp(b, e - 1); return (b * r) % mod;
    } else {
        r = fxp(b, e / 2); return (r * r) % mod;
    }
}

ll inv(ll x) {
    return fxp(x, mod - 2);
}

ll bnm(ll a, ll b) {
    if (a < b) return 0;
    ll r = fc[a];
    r *= nv[a - b]; r %= mod;
    r *= nv[b]; r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    cin >> m[0] >> m[1] >> n;
    for (i = 1; i <= 2 * n; i++) {
        cin >> x >> y; mk[0][x] = 1; mk[1][y] = 1;
    }

    for (ty = 0; ty < 2; ty++) {
        dp[ty][0][0] = 1;
        for (i = 1; i <= m[ty]; i++) {
            tt[ty] += 1 - mk[ty][i];
            for (j = 0; j <= m[ty]; j++) {
                dp[ty][i][j] = dp[ty][i - 1][j];
                if (i >= 2 && j >= 1 && mk[ty][i] == 0 && mk[ty][i - 1] == 0) {
                    dp[ty][i][j] += dp[ty][i - 2][j - 1];
                }
                dp[ty][i][j] %= mod;
            }
        }
    }

    /* for (ty = 0; ty < 2; ty++) {
        for (i = 0; i <= m[ty]; i++) {
            for (j = 0; j <= m[ty]; j++) {
                cout << ty _ i _ j _ dp[ty][i][j] << nl;
            }
        }
    } */

    for (i = 0; i <= m[0]; i++) {
        for (j = 0; j <= m[1]; j++) {
            k = dp[0][m[0]][i] * dp[1][m[1]][j]; k %= mod;
            k *= bnm(tt[0] - 2 * i, j); k %= mod;
            k *= bnm(tt[1] - 2 * j, i); k %= mod;
            k *= fc[i]; k %= mod;
            k *= fc[j]; k %= mod;
            // if (k != 0) cout << i _ j _ k << nl;
            res += k; res %= mod;
        }
    }

    cout << res << nl;

    return 0;
}