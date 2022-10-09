// 1227F2
// Wrong Answer on test 233

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, x, fc[maxn], nv[maxn];

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
    ll x = fc[a];
    x *= nv[a - b]; x %= mod;
    x *= nv[b]; x %= mod;
    return x;
}

void fx(ll &x) {
    x %= mod; x += mod; x %= mod;
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

    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[0];

    m = n;
    for (i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) m--;
    }

    res = 0;
    for (i = 0; i <= m / 2; i++) {
        x = fxp(k - 2, m - 2 * i);
        x *= bnm(m, i); x %= mod;
        x *= bnm(m - i, i); x %= mod;
        res += x; res %= mod;
        // cout << res << nl;
    }

    res *= fxp(k, n - m); res %= mod;
    res = fxp(k, n) - res; fx(res);
    res *= nv[2]; res %= mod;

    cout << res;

    return 0;
}