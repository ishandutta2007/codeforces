#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 3000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cn[maxn][3], q, fc[maxn], nv[maxn], dp[maxn][3];
ll nv3;

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

ll bnm(ll a, ll b) {
    if (a < b || b < 0) return 0;
    ll r = (fc[a] * nv[b]) % mod;
    r = (r * nv[a - b]) % mod;
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
        fc[i] = (i * fc[i - 1]) % mod; nv[i] = inv(fc[i]);
    }
    nv3 = inv(3);

    cin >> n >> q; n *= 3;

    dp[0][0] = n / 3 + 1; dp[0][1] = n / 3; dp[0][2] = n / 3;
    for (i = 1; i <= n; i++) {
        dp[i][1] = (bnm(n + 1, i + 1) - 2 * dp[i - 1][1] - dp[i - 1][2]) % mod;
        if (dp[i][1] < 0) dp[i][1] += mod;
        dp[i][1] = (dp[i][1] * nv3) % mod;
        dp[i][2] = (dp[i - 1][1] + dp[i][1]) % mod;
        dp[i][0] = (dp[i - 1][2] + dp[i][2]) % mod;
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= 2; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    while (q--) {
        cin >> k;
        cout << dp[k][0] << nl;
    }

    return 0;
}