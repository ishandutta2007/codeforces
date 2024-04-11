#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cr;
vector<ll> v, w;
vector<array<ll, 2>> vv, ww;

vector<array<ll, 2>> fix(vector<ll> v) {
    ll a;
    vector<array<ll, 2>> vv;
    vv.pb({-1, 1});
    for (auto u : v) {
        a = 1;
        while (u % k == 0) u /= k, a *= k;
        auto [x, y] = vv.back();
        if (x == u) vv.pop_back(), vv.pb({u, y + a});
        else vv.pb({u, a});
    }
    return vv;
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
        cin >> n >> k; v.clear(); w.clear();
        for (i = 1; i <= n; i++) {
            cin >> a; v.pb(a);
        }
        cin >> m;
        for (i = 1; i <= m; i++) {
            cin >> a; w.pb(a);
        }

        vv = fix(v); ww = fix(w);

        /* for (auto [x, y] : vv) cout << x _ y << nl;
        cout << nl;
        for (auto [x, y] : ww) cout << x _ y << nl;
        cout << nl; */

        if (vv == ww) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}