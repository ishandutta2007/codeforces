#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], x, ps[maxn][2];
vector<ll> d;

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

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> x; d.pb(x);
    }
    for (i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    sort(d.begin(), d.end());

    ps[n - 1][1] = d[n - 1];
    for (i = n - 2; i >= 0; i--) ps[i][1] = (ps[i + 1][1] + d[i]) % mod;
    ps[0][0] = d[0];
    for (i = 1; i < n; i++) ps[i][0] = (ps[i - 1][0] + d[i]) % mod;

    for (i = 0; i < m; i++) {
        auto it = lower_bound(d.begin(), d.end(), b[i]);
        k = (it - d.begin());
        res = ps[k][1];
        res *= max((ll)0, n - k - a[i]); res %= mod;
        res *= inv(n - k); res %= mod;

        x = 0;
        if (k > 0) x = ps[k - 1][0];
        x *= (max((ll)0, n - k + 1 - a[i])); x %= mod;
        x *= inv(n - k + 1); x %= mod;

        res += x; res %= mod;
        cout << res << nl;
    }

    return 0;
}