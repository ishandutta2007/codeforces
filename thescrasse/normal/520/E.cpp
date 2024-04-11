// 520E
// Pluses everywhere

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, ph[maxn], ps[maxn], p10[maxn][2], fc[maxn][2], dp[maxn];
string s;

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

ll inv(ll x) {
    return fxp(x, mod - 2);
}

ll hs(ll l, ll r) {
    if (l > r) return 0;
    ll k = ph[r];
    if (l == 0) return k;
    k -= ph[l - 1] * p10[r - l + 1][0];
    k %= mod; k += mod; k %= mod;
    return k;
}

ll rs(ll l, ll r) {
    if (l == 0) return ps[r];
    return ps[r] - ps[l - 1];
}

ll bnm(ll a, ll b) {
    if (b < 0) return 0;
    if (a < b) return 0;
    ll r = fc[a][0];
    r *= fc[b][1]; r %= mod;
    r *= fc[a - b][1]; r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k >> s;
    for (i = 0; i < n; i++) a[i] = (ll)s[i] - 48;

    p10[0][0] = p10[0][1] = fc[0][0] = fc[0][1] = 1;
    for (i = 1; i < n; i++) {
        p10[i][0] = (10 * p10[i - 1][0]) % mod;
        p10[i][1] = inv(p10[i][0]);
        fc[i][0] = (i * fc[i - 1][0]) % mod;
        fc[i][1] = inv(fc[i][0]);
    }

    ph[0] = ps[0] = a[0];
    for (i = 1; i < n; i++) {
        ph[i] = (10 * ph[i - 1] + a[i]) % mod;
        ps[i] = ps[i - 1] + a[i];
    }

    dp[0] = 0;
    for (i = 1; i <= n - 2; i++) {
        dp[i] = (dp[i - 1] - hs(n - i, n - 2) + mod) % mod;
        dp[i] *= 10; dp[i] %= mod;
        dp[i] += rs(i, n - 2); dp[i] %= mod;
    }

    res = 0;
    for (i = 1; i <= n - 2; i++) {
        // cout << i << ' ' << dp[i] << nl;
        res += dp[i] * bnm(n - i - 2, k - 2); res %= mod;
    }

    for (i = 0; i < n; i++) {
        if (i != n - 1) {
            res += hs(0, i) * bnm(n - i - 2, k - 1); res %= mod;
        }
        if (i != 0) {
            res += hs(i, n - 1) * bnm(i - 1, k - 1); res %= mod;
        }
    }

    if (k == 0) {
        res += hs(0, n - 1); res %= mod;
    }

    cout << res;

    return 0;
}