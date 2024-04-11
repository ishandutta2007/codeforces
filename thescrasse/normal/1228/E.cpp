// 1228E
// Another Filling the Grid

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 260

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, pk[maxn], pk1[maxn], fc[maxn], nv[maxn], dp[maxn][maxn], x;

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        r = fxp(b, e / 2); return (r * r) % mod;
    } else {
        r = fxp(b, e - 1); return (b * r) % mod;
    }
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

    cin >> n >> k;

    pk[0] = 1; pk1[0] = 1; fc[0] = 1; nv[0] = 1;
    for (i = 1; i <= n; i++) {
        pk[i] = (pk[i - 1] * k) % mod;
        pk1[i] = (pk1[i - 1] * (k - 1)) % mod;
        fc[i] = (fc[i - 1] * i) % mod;
        nv[i] = inv(fc[i]);
    }
    for (j = 0; j <= n; j++) dp[0][j] = (j == 0);
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = 0;
            for (k = 0; k < j; k++) {
                // cout << "i, j, k = " << i << ' ' << j << ' ' << k << nl;
                x = dp[i - 1][k];
                x *= pk[k]; x %= mod;
                x *= fc[n - k]; x %= mod;
                x *= nv[j - k]; x %= mod;
                x *= nv[n - j]; x %= mod;
                dp[i][j] += x;
                // cout << nl;
            }
            dp[i][j] += (pk[j] - pk1[j] + mod) * dp[i - 1][j];
            dp[i][j] %= mod;
            dp[i][j] *= pk1[n - j]; dp[i][j] %= mod;
            // cout << i << ' ' << j << ' ' << dp[i][j] << nl;
        }
    }

    cout << dp[n][n];

    return 0;
}