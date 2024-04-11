// 1398G
// Running Competition
// trying ntt

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
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, q, x, y;
vector<ll> va, vb, rs;

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

void fft(vector<ll> &v, ll invert) {
    ll i, n, w, wn;
    n = v.size();
    // cout << "fft " << n << nf;
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
        ll n_inv = inv(n);
        for (auto &u : v) u = (u * n_inv) % mod;
    }
}

vector<ll> multiply(vector<ll> &va, vector<ll> &vb) {
    ll i, k;
    vector<ll> rs;
    vector<ll> fa(va.begin(), va.end()), fb(vb.begin(), vb.end());

    k = 1;
    while (k < 2 * maxn + 2) k <<= 1;
    fa.resize(k); fb.resize(k);

    fft(fa, 0); fft(fb, 0);
    for (i = 0; i < k; i++) fa[i] = (fa[i] * fb[i]) % mod;
    fft(fa, 2);

    return fa;
}

void upd(ll a) {
    if (a - y > 0 && a - y <= maxn && rs[a - y + maxn] >= 1) m = max(m, 2 * a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    va.resize(maxn + 1); vb.resize(maxn + 1);
    cin >> n >> x >> y;
    for (i = 0; i <= n; i++) {
        cin >> a[i];
        va[a[i]]++; vb[maxn - a[i]]++;
    }

    rs = multiply(va, vb);

    // for (i = 0; i < rs.size(); i++) cout << i _ rs[i] << nl;

    cin >> q;
    while (q--) {
        cin >> k; k /= 2; m = -1;
        for (i = 1; i * i <= k; i++) {
            if (k % i != 0) continue;
            upd(i); upd(k / i);
        }
        cout << m << ' ';
    }
    cout << nl;

    return 0;
}