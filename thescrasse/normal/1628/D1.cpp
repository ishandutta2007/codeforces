#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll fc[maxn], nv[maxn], mp, pn[maxn], inv_2;

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

    inv_2 = inv(2);
    pn[0] = 1;
    for (i = 1; i < maxn; i++) pn[i] = (inv_2 * pn[i - 1]) % mod;

    cin >> t;
    while (t--) {
        cin >> n >> m >> mp;
        res = 0;
        for (i = m; i <= n - 1; i++) {
            for (k = 0; k <= m - 1; k++) {
                a = (pn[i] * bnm(i, k)) % mod;
                res = (res + a) % mod;
            }
        }

        res = (m - res + mod) % mod;
        res = (res * mp) % mod;
        cout << res << nl;
    }

    return 0;
}