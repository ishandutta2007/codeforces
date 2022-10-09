// 1139D
// Steps to One

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, er[maxn], s, p;
vector<ll> fc;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;

    for (i = 0; i <= n; i++) er[i] = i;
    for (i = 2; i <= n; i++) {
        if (er[i] == i) {
            for (j = 2 * i; j <= n; j += i) er[j] = i;
        }
    }

    res = inv(n);
    for (i = 2; i <= n; i++) {
        fc.clear();
        k = i; flag[0] = 1;
        while (k != 1) {
            m = er[k];
            if (k != i && m == fc.back()) {
                flag[0] = 0; break;
            }
            fc.pb(m); k /= m;
        }

        if (flag[0] == 0) continue;
        s = fc.size(); s %= 2; s = 2 * s - 1;
        k = n / i;
        p = k * (2 * n - k); p %= mod;
        p *= inv(n); p %= mod; p *= inv(n - k); p %= mod;
        res += (s * p); res %= mod; res += mod; res %= mod;
    }

    cout << res;

    return 0;
}