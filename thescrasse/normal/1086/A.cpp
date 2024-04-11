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
vector<ll> x, y;
vector<array<ll, 2>> v;
set<array<ll, 2>> rs;

void cnn(ll x1, ll y1, ll x2, ll y2) {
    ll i;
    for (i = min(x1, x2); i <= max(x1, x2); i++) rs.insert({i, y1});
    for (i = min(y1, y2); i <= max(y1, y2); i++) rs.insert({x2, i});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    n = 3;
    for (i = 1; i <= n; i++) {
        cin >> a >> b; v.pb({a, b}); x.pb(a); y.pb(b);
    }

    sort(x.begin(), x.end()); sort(y.begin(), y.end());

    for (i = 0; i < n; i++) cnn(v[i][0], v[i][1], x[1], y[1]);

    cout << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] << nl;

    return 0;
}