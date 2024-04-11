// 520E
// Pluses everywhere

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, fc[maxn], nv[maxn];

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
    r *= nv[b]; r %= mod;
    r *= nv[a - b]; r %= mod;
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
        fc[i] = (i * fc[i - 1]) % mod;
        nv[i] = inv(fc[i]);
    }

    cin >> n >> m >> a >> b;

    res = 0;
    for (i = 0; i <= n - 2; i++) {
        k = bnm(m - 1, i);
        k *= fc[i]; k %= mod;
        k *= fxp(m, n - i - 2); k %= mod;
        k *= bnm(n - 2, i); k %= mod;
        if (i != n - 2) {
            k *= (i + 2); k %= mod;
            k *= fxp(n, n - i - 3); k %= mod;
        }

        res += k; res %= mod;
    }

    cout << res;

    return 0;
}