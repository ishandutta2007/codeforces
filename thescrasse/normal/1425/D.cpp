#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[1010][1010], ps[1010][1010], r;
ll s, x[maxn], y[maxn], p[maxn], fc[maxn], nv[maxn], cn[4], o;

ll rs(ll a, ll b, ll c, ll d) {
    if (a > c || b > d) return 0;
    // cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << ps[c][d] - ps[a - 1][d] - ps[c][b - 1] + ps[a][b] << nl;
    return ps[c][d] - ps[a - 1][d] - ps[c][b - 1] + ps[a - 1][b - 1];
}

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
    if (a < b) return 0;
    ll r = fc[a];
    r *= nv[a - b]; r %= mod;
    r *= nv[b]; r %= mod;
    // cout << a << ' ' << b << ' ' << r << nl;
    return r;
}

ll wrd(ll a, ll b, ll c, ll d) {
    return rs(max((ll)1, max(a, c) - r),
    max((ll)1, max(b, d) - r),
    min((ll)s, min(a, c) + r),
    min((ll)s, min(b, d) + r));
}

void fx(ll &a) {
    a %= mod; a += mod; a %= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("output.txt");
        ofstream cout("input.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    cin >> n >> m >> r; s = 1000;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> p[i];
        mt[x[i]][y[i]] = 1;
    }

    for (i = 1; i <= s; i++) {
        for (j = 1; j <= s; j++) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + mt[i][j];
            // if (i <= 5 && j <= 5) cout << ps[i][j] << ' ';
        }
        // if (i <= 5) cout << nl;
    }

    res = 0;
    for (i = 0; i < n; i++) {
        k = p[i] * p[i]; fx(k);
        o = bnm(n, m) - bnm(n - wrd(x[i], y[i], x[i], y[i]), m); fx(o);
        k *= (mod + bnm(n, m) - bnm(n - wrd(x[i], y[i], x[i], y[i]), m)); fx(k);
        // cout << wrd(x[i], y[i], x[i], y[i]) << nl;
        res += k; fx(res);
        // cout << i << ' ' << k << nl;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            k = 2 * p[i] * p[j]; k %= mod;
            cn[0] = n - wrd(x[i], y[i], x[i], y[i]); fx(cn[0]);
            cn[1] = n - wrd(x[j], y[j], x[j], y[j]); fx(cn[1]);
            cn[2] = cn[0] + cn[1] - n + wrd(x[i], y[i], x[j], y[j]); fx(cn[2]);
            o = bnm(n, m) - bnm(cn[0], m) - bnm(cn[1], m) + bnm(cn[2], m); fx(o);
            k *= o; fx(k);
            res += k; fx(res);
            // cout << i << ' ' << j << ' ' << k << ' ' << nl;
        }
    }

    cout << res;

    return 0;
}