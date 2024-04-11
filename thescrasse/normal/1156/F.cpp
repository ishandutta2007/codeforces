// 1156F
// Card Bag

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn][maxn];
ll s, fc[maxn], nv[maxn], tt, sf[maxn];
vector<ll> v;

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
    r *= nv[b]; r %= mod;
    r *= nv[a - b]; r %= mod;
    return r;
}

ll bnmv(ll a, ll b) {
    if (a < b) return 0;
    ll r = nv[a];
    r *= fc[b]; r %= mod;
    r *= fc[a - b]; r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    sort(a, a + n);
    k = 1;
    for (i = 1; i <= n; i++) {
        if (i == n || a[i] != a[i - 1]) {
            v.pb(k); k = 1;
        } else {
            k++;
        }
    }

    s = v.size(); dp[0][0] = 1;
    for (i = 1; i <= s; i++) {
        k = v[i - 1]; tt += k;
        for (j = 0; j <= s; j++) {
            dp[i][j] = dp[i - 1][j] * bnm(tt - j, k);
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * bnm(tt - j, k - 1);
            dp[i][j] %= mod;
        }
    }

    sf[s + 1] = 1; tt = 0;
    for (i = s; i >= 1; i--) {
        k = v[i - 1]; tt += k;
        sf[i] = sf[i + 1] * bnm(tt, k); sf[i] %= mod;
    }

    tt = 0;
    for (i = 1; i <= s; i++) {
        k = v[i - 1];
        if (v[i - 1] >= 2) {
            for (j = 0; j <= s; j++) {
                m = dp[i - 1][j] * sf[i + 1]; m %= mod;
                m *= bnm(n - tt - 2, v[i - 1] - 2); m %= mod;
                m *= bnm(n - j - 2, n - tt - 2); m %= mod;
                res += m; res %= mod;
                // cout << i << ' ' << j << ' ' << tt << ' ' << dp[i - 1][j] << ' ' << sf[i + 1] << nl;
                // cout << res << nl;
            }
        }
        tt += k;
    }

    /* for (i = 0; i <= s; i++) {
        cout << i << ' ' << sf[i] << nl;
        for (j = 0; j <= s; j++) {
            cout << i << ' ' << j << ' ' << dp[i][j] << nl;
        }
    } */

    res *= inv(sf[1]); res %= mod;
    cout << res;

    return 0;
}