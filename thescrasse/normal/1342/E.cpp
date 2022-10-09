// 1342E
// Placing Rooks

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, fc[maxn], x;

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

ll bnm(ll a, ll b) {
    ll r = fc[a];
    r *= inv(fc[b]); r %= mod;
    r *= inv(fc[a - b]); r %= mod;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    if (k > n) {
        cout << 0; return 0;
    }

    k = n - k;

    fc[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
    }

    res = 0;
    for (i = 0; i < k; i++) {
        x = fxp(k - i, n);
        x *= bnm(k, i); x %= mod;
        if (i % 2 == 0) res += x;
        else res -= x;
        res %= mod; res += mod; res %= mod;
        // cout << i << ' ' << x << ' ' << res << nl;
    }

    res *= bnm(n, k);
    if (k != n) res *= 2;
    res %= mod;

    cout << res;

    return 0;
}