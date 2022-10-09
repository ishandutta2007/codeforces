// 1036F
// Relatively Prime Powers

#pragma GCC optimize("O3")
#pragma GCC option("arch=native")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 70
#define eps (long double)1e-9

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, er[maxn], f[maxn], bsl, bsm, bsu, mz[maxn][10010];

void sqf(ll x) {
    ll i, k;
    k = 0;
    for (i = 2; i <= x; i++) {
        if (er[i] != i) continue;
        if (x % i != 0) continue;
        if (x % (i * i) == 0) {
            f[x] = 0; return;
        }
        k++;
    }

    f[x] = 1 - 2 * (k % 2);
}

void sv(ll b, ll e, ll x) {
    if (b > 10000) return;
    mz[e][b] = x;
}

ll fxp(ll b, ll e) {
    ll r;
    if (b <= 10000 && mz[e][b] != 0) return mz[e][b];
    if (e == 0) return 1;
    if (e % 2 == 0) {
        r = fxp(b, e / 2);
        if (r > 1e9) {
            sv(b, e, (ll)1e18 + 1);
            return (ll)1e18 + 1;
        } else {
            sv(b, e, r * r);
            return r * r;
        }
    } else {
        r = fxp(b, e - 1);
        if ((ll)9e18 / r <= b) {
            sv(b, e, (ll)1e18 + 1);
            return (ll)1e18 + 1;
        } else {
            sv(b, e, min((ll)1e18 + 1, b * r));
            return min((ll)1e18 + 1, b * r);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 2; i < maxn; i++) er[i] = i;
    for (i = 2; i < maxn; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j < maxn; j += i) er[j] = i;
        }
    }

    for (i = 1; i < maxn; i++) sqf(i);

    cin >> t;
    while (t--) {
        cin >> n; res = n - 1;
        for (i = 2; i < maxn; i++) {
            bsl = 1; bsu = pow(n, (long double)1 / i) + 10;
            while (bsl < bsu) {
                bsm = (bsl + bsu) / 2 + 1;
                if (fxp(bsm, i) <= n) bsl = bsm;
                else bsu = bsm - 1;
            }
            // cout << i << ' ' << f[i] << ' ' << bsl << nl;
            res += f[i] * (bsl - 1);
        }

        cout << res << nl;
    }

    return 0;
}