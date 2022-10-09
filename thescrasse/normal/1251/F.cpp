// 1251F
// Red-White Fence

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define root 15311432
#define root_inv 469870224
#define root_pw 1 << 23
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[10];
ll q, c[maxn], f[maxn], g[maxn][3], x, y, fc[2 * maxn], nv[2 * maxn];
vector<ll> ff[10], va, vb;

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
    ll r = fc[a];
    r *= nv[b]; r %= mod;
    r *= nv[a - b]; r %= mod;
    return r;
}

void fft(vector<ll> &v, ll invert) {
    ll i, k, n, w, wn;
    n = v.size();
    if (n == 1) return;

    vector<ll> v0(n / 2), v1(n / 2);
    for (i = 0; i < n / 2; i++) {
        v0[i] = v[2 * i]; v1[i] = v[2 * i + 1];
    }

    fft(v0, (invert + 1) / 2); fft(v1, (invert + 1) / 2);

    w = 1;
    if (invert == 0) wn = root;
    else wn = root_inv;
    for (i = n; i < root_pw; i <<= 1) wn = (wn * wn) % mod;
    for (i = 0; i < n / 2; i++) {
        v[i] = (v0[i] + w * v1[i]) % mod;
        v[i + n / 2] = (v0[i] - w * v1[i] + (ll)mod * mod) % mod;
        w = (w * wn) % mod;
    }

    if (invert == 2) {
        ll n_1 = inv(n);
        for (auto &u : v) u = (u * n_1) % mod;
    }
}

vector<ll> multiply(vector<ll> &va, vector<ll> &vb) {
    ll i, k;
    k = 1;
    while (k < va.size() + vb.size()) k <<= 1;

    vector<ll> fa(va.begin(), va.end()), fb(vb.begin(), vb.end());
    fa.resize(k); fb.resize(k);

    fft(fa, 0); fft(fb, 0);
    for (i = 0; i < k; i++) fa[i] = (fa[i] * fb[i]) % mod;
    fft(fa, 2);

    return fa;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1; nv[0] = 1;
    for (i = 1; i < 2 * maxn; i++) {
        fc[i] = (i * fc[i - 1]) % mod; nv[i] = inv(fc[i]);
    }

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; f[a[i]]++;
    }
    for (i = 1; i <= k; i++) {
        cin >> b[i];
    }
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> c[i]; c[i] /= 2;
    }

    for (i = 1; i < maxn; i++) {
        g[i][1] = g[i - 1][1]; g[i][2] = g[i - 1][2];
        g[i][(f[i] >= 1) + (f[i] >= 2)]++;
    }

    for (i = 1; i <= k; i++) {
        x = g[b[i] - 1][1]; y = 2 * g[b[i] - 1][2];
        va.clear(); vb.clear();
        va.resize(x + 1); vb.resize(y + 1);
        for (j = 0; j <= x; j++) va[j] = (fxp(2, j) * bnm(x, j)) % mod;
        for (j = 0; j <= y; j++) vb[j] = bnm(y, j);
        ff[i] = multiply(va, vb);

        /* for (auto u : va) cout << u << ' ';
        cout << nl;
        for (auto u : vb) cout << u << ' ';
        cout << nl;
        for (auto u : ff[i]) cout << u << ' ';
        cout << nl; */
    }

    /* for (i = 1; i <= k; i++) {
        for (auto u : ff[i]) cout << u << ' ';
        cout << nf;
    } */

    for (i = 1; i <= q; i++) {
        res = 0;
        for (j = 1; j <= k; j++) {
            x = c[i] - b[j] - 1;
            if (x >= 0 && x < ff[j].size()) res += ff[j][x];
        }
        res %= mod;
        cout << res << nl;
    }

    return 0;
}