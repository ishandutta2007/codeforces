// 1140E
// Palindrome-less Arrays

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, r[2], dp[maxn][2], l;

ll fxp(ll b, ll e) {
    ll r;
    if (e == 0) return 1;
    if (e % 2 == 0) {
        r = fxp(b, e / 2); return (r * r) % mod;
    } else {
        r = fxp(b, e - 1); return (b * r) % mod;
    }

    return r;
}

void df(ll x) {
    l = 0; flag[0] = -2; flag[1] = 0;
    for (i = x; i < n; i += 2) {
        if (a[i] == -1) {
            l++;
        } else {
            // cout << "found " << l << ' ' << flag[0] << nl;
            if (flag[0] == -2) {
                r[x] *= fxp(k - 1, l); r[x] %= mod;
            } else if (flag[0] == a[i]) {
                r[x] *= dp[l][0]; r[x] %= mod;
            } else {
                r[x] *= dp[l][1]; r[x] %= mod;
            }
            l = 0; flag[0] = a[i]; flag[1] = 1;
        }
    }
    if (flag[1] == 0) r[x] *= k * fxp(k - 1, l - 1);
    else r[x] *= fxp(k - 1, l);
    r[x] %= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k; r[0] = 1; r[1] = 1;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0][0] = 0; dp[0][1] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 2; j++) {
            dp[i][j] = (fxp(k - 1, i) - dp[i - 1][j] + mod) % mod;
            // cout << i << ' ' << j << ' ' << dp[i][j] << nl;
        }
    }

    df(0); df(1);

    // cout << r[0] << ' ' << r[1] << nl;
    cout << (r[0] * r[1]) % mod;

    return 0;
}