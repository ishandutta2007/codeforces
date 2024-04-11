// 839D
// Winter is here

// #pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010
#define maxp 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, er[maxp], cn[maxp], s, f[maxp], l, kf[maxn];
vector<ll> dv, cf;
vector<array<ll, 2>> fc;

void f_fc(ll k) {
    ll i, j;
    fc.clear();
    while (k != 1) {
        m = er[k]; k /= m;
        flag[0] = 0;
        if (!fc.empty() && fc.back()[0] == m) {
            flag[0] = 1; fc.back()[1]++;
        }
        if (flag[0] == 0) fc.pb({m, 1});
    }

    // for (auto u : fc) cout << u[0] << ' ' << u[1] << nf;
}

void f_dv() {
    ll i, j, k;
    dv.clear(); cf.clear(); k = 1;
    for (auto u : fc) cf.pb(0);
    s = fc.size();
    while (true) {
        // for (auto u : cf) cout << u << ' ';
        // cout << nf;
        dv.pb(k); // cout << k << nf;
        l = s - 1;
        // cout << "cf, fc = " << cf[l] << ' ' << fc[l][1] << nl;
        while (cf[l] == fc[l][1]) {
            for (i = 0; i < cf[l]; i++) k /= fc[l][0];
            cf[l] = 0; l--;
            if (l == -1) break;
        }
        if (l == -1) break;
        cf[l]++; k *= fc[l][0];
        // cout << "l = " << l << nf;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    kf[0] = 0; kf[1] = 1;
    for (i = 2; i < maxn; i++) kf[i] = (2 * kf[i - 1]) % mod;
    for (i = 2; i < maxn; i++) kf[i] = (i * kf[i]) % mod;
    for (i = 0; i < maxp; i++) er[i] = i;
    for (i = 2; i < maxp; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j < maxp; j += i) er[j] = i;
        }
    }

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cn[1] = 0;
    for (i = 2; i < maxp; i++) {
        f_fc(i); f_dv();
        cn[i] = i;
        for (auto u : dv) {
            if (u != i) cn[i] -= cn[u];
        }
    }

    for (i = 1; i < maxp; i++) f[i] = 0;

    for (i = 0; i < n; i++) {
        f_fc(a[i]); f_dv();
        for (auto u : dv) f[u]++;
    }

    res = 0;
    for (i = 2; i < maxp; i++) {
        // cout << i << ' ' << f[i] << ' ' << cn[i] << nl;
        res += kf[f[i]] * cn[i]; res %= mod;
    }

    cout << res;

    return 0;
}