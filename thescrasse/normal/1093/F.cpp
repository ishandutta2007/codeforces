// 1439B
// Vasya and Array

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn][110], x;
ll dp[maxn][110], sm[maxn];

ll rs(ll l, ll r, ll ty) {
    // cout << l _ r _ ty _ f[r][ty] - f[l - 1][ty] << nl;
    return f[r][ty] - f[l - 1][ty];
}

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> x;
    if (x == 1) {
        cout << 0; return 0;
    }
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) a[i] = 0;
        for (j = 0; j <= 100; j++) f[i][j] = f[i - 1][j];
        f[i][a[i]]++;
    }

    sm[0] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (a[i] != 0 && a[i] != j) {
                dp[i][j] = 0; continue;
            }
            dp[i][j] = sm[i - 1];
            if (i >= x && rs(i - x + 1, i, 0) + rs(i - x + 1, i, j) == x) {
                dp[i][j] = (dp[i][j] - sm[i - x] + dp[i - x][j] + mod) % mod;
            }
            sm[i] += dp[i][j]; sm[i] %= mod;
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            cout << i _ j _ dp[i][j] << nl;
        }
    } */

    cout << sm[n];

    return 0;
}