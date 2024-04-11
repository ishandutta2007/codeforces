#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

struct dsu {
    vector<ll> pr;

    dsu(): pr({}) {
        ll i;
        pr.resize(maxn);
        for (i = 0; i < maxn; i++) pr[i] = i;
    }

    ll find(ll x) {
        if (pr[x] == x) return x;
        return pr[x] = find(pr[x]);
    }

    bool same(ll a, ll b) {
        return (find(a) == find(b));
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        pr[b] = a;
    }
};

ll i, i1, j, k, k1, t, n, m[2], res, flag[10], a, b;
ll pr[maxn];
vector<array<ll, 2>> el[2], rs;
dsu ds[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m[0] >> m[1];
    for (i = 1; i <= m[0]; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        el[0].pb({a, b});
    }
    for (i = 1; i <= m[1]; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        el[1].pb({a, b});
    }

    if (m[0] < m[1]) {
        swap(m[0], m[1]); swap(el[0], el[1]);
    }

    sort(el[0].begin(), el[0].end()); sort(el[1].begin(), el[1].end());

    for (i = 1; i <= n; i++) pr[i] = i;

    for (auto u : el[0]) {
        if (ds[0].same(u[0], u[1])) continue;
        ds[0].merge(u[0], u[1]);
    }

    for (auto u : el[1]) {
        if (ds[1].same(u[0], u[1])) continue;
        ds[1].merge(u[0], u[1]);
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (ds[0].same(i, j)) continue;
            if (ds[1].same(i, j)) continue;
            ds[0].merge(i, j); ds[1].merge(i, j); rs.pb({i, j});
        }
    }

    cout << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] << nl;

    return 0;
}