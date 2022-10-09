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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll fc[maxn], nv[maxn];

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

    cin >> n; n++;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 0;
    /* for (i = 1;; i++) {
        if (a[i] == 0) {
            n = i - 1; break;
        }
    } */

    if (a[1] == 0) {
        cout << 0 << nl; return 0;
    }

    for (i = 1; i <= n; i++) res = (res + bnm(i + a[i] - 2, i - 1)) % mod; //, cout << res << nl;

    j = 1;
    for (i = a[1]; i >= 1; i--) {
        while (a[j + 1] >= i) j++;
        res = (res + bnm(i + j - 2, i - 1)) % mod; //, cout << res << nl;
    }

    res = (res - 1 + mod) % mod;
    cout << res << nl;

    return 0;
}