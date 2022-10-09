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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll f[2];

ll solve() {
    ll i, sz, r = 0;
    vector<ll> x, y;
    for (i = 1; i <= n; i++) {
        if (a[i] == 1) x.pb(i);
        if (b[i] == 1) y.pb(i);
    }

    sz = x.size();
    for (i = 0; i < sz; i++) r += abs(x[i] - y[i]);

    return r;
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
        cin >> n; f[0] = 0; f[1] = 0; res = INF;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; a[i] %= 2; f[a[i]]++;
        }

        if (abs(f[0] - f[1]) >= 2) {
            cout << -1 << nl; continue;
        }

        if (f[0] > f[1]) {
            for (i = 1; i <= n; i += 2) b[i] = 0;
            for (i = 2; i <= n; i += 2) b[i] = 1;
            res = min(res, solve());
        } else if (f[0] < f[1]) {
            for (i = 1; i <= n; i += 2) b[i] = 1;
            for (i = 2; i <= n; i += 2) b[i] = 0;
            res = min(res, solve());
        } else {
            for (i = 1; i <= n; i += 2) b[i] = 0;
            for (i = 2; i <= n; i += 2) b[i] = 1;
            res = min(res, solve());
            for (i = 1; i <= n; i += 2) b[i] = 1;
            for (i = 2; i <= n; i += 2) b[i] = 0;
            res = min(res, solve());
        }

        cout << res << nl;
    }

    return 0;
}