#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, p[maxn], r[maxn];

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
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    p[0] = 0;
    for (i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }

    for (i = 1; i <= n; i++) {
        r[i] = 0;
        for (j = n - i; j >= 0; j -= i) {
            r[i] += p[j]; r[i] %= mod;
        }
    }

    for (i = 1; i <= n; i++) {
        r[i] *= inv(n); r[i] %= mod;
        cout << r[i] << ' ';
    }

    return 0;
}