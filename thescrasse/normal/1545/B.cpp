#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll sz;
string s;
vector<ll> v;

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> s; s = '#' + s; v.clear(); v.pb(-1);
        for (i = 1; i <= n; i++) {
            if (s[i] == '0') v.pb(i);
        }

        k = n / 2; sz = (ll)v.size() - 1;
        if (sz == 0) {
            cout << 1 << nl; continue;
        }
        if (n % 2 == 1 && v[1] % 2 == 1) k++;

        for (i = 1; i <= sz - 1; i++) {
            if (n % 2 == 1 && v[i] % 2 == 0 && v[i + 1] % 2 == 1) k++;
            if (n % 2 == 0 && v[i] % 2 == 1 && v[i + 1] % 2 == 0) k++;
        }

        // cout << k _ sz << nl;

        res = 1;
        for (i = 1; i <= k; i++) res = (i * res) % mod;
        for (i = 1; i <= sz; i++) res = (inv(i) * res) % mod;
        for (i = 1; i <= k - sz; i++) res = (inv(i) * res) % mod;

        cout << res << nl;
    }

    return 0;
}