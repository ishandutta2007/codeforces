#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 400010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll sl, sr, kl, cl, cr, nw;
ll fc[maxn], nv[maxn];

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
    if (a < b || b < 0) return 0;
    ll r = (fc[a] * nv[b]) % mod;
    r = (r * nv[a - b]) % mod;
    return r;
}

ll cnt(ll l, ll r) {
    ll x, y, rs = 0;
    if (n % 2) {
        x = n / 2 - l;
        y = (n + 1) / 2 - (n - r + 1);
        rs = bnm(x + y + 2, x + 1);
        x = (n + 1) / 2 - l;
        y = n / 2 - (n - r + 1);
        rs += bnm(x + y + 2, x + 1); rs %= mod;
        return rs;
    } else {
        ll x, y;
        x = n / 2 - l;
        y = n / 2 - (n - r + 1);
        return bnm(x + y + 2, x + 1);
    }
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

    cin >> t;
    while (t--) {
        cin >> n >> sl >> sr; res = 0;
        kl = max((ll)1, min(1 - sl, sr - n));
        res = ((kl - 1) * cnt(1, n)) % mod;
        for (k = kl; k <= kl + 2 * n; k++) {
            cl = max((ll)1, sl + k);
            cr = min((ll)n, sr - k);
            res += cnt(cl, cr); res %= mod;
            // cout << "k, cl, cr, cnt = " << k _ cl _ cr _ cnt(cl, cr) << nl;
        }

        cout << res << nl;
    }

    return 0;
}