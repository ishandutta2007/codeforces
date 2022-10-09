#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x, tt, avg[maxn], sm[maxn], rs[maxn];
vector<array<ll, 2>> adj[maxn], rsd;
multiset<ll> tc;

void fix(ll tl, ll tr) {
    ll i;
    for (i = tl; i <= tr; i++) {
        auto it = tc.lower_bound(avg[i]);
        if (it == tc.end()) {
            flag[0] = 0; continue;
        }
        rsd.pb({(*it), i}); tc.erase(it);
    }
}

void check(ll p) {
    ll i, mx, sz;
    auto it = tc.end(); it--; mx = (*it);
    sz = (ll)adj[p].size() - 1;
    for (auto [u, id] : adj[p]) {
        if (flag[0] == 1 && (sm[p] - u + sz - 1) / sz <= mx) rs[id] = 1;
        else rs[id] = 0;
    }
}

void rb(ll tl, ll tm) {
    while (!rsd.empty() && rsd.back()[1] >= tl && rsd.back()[1] <= tm) {
        tc.insert(rsd.back()[0]); rsd.pop_back();
    }
}

void solve(ll tl, ll tr, ll f) {
    if (tl > tr) return;
    if (tl == tr) {
        check(tl); return;
    }

    ll tm = (tl + tr) / 2;

    fix(tm + 1, tr);
    solve(tl, tm, flag[0]);
    rb(tm + 1, tr); flag[0] = f;

    fix(tl, tm);
    solve(tm + 1, tr, flag[0]);
    rb(tl, tm); flag[0] = f;
}

void rst() {
    flag[0] = 1; tt = 0;
    tc.clear();
    for (i = 1; i <= m; i++) {
        adj[i].clear(); avg[i] = 0; sm[i] = 0;
    }
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
        cin >> n >> m; rst();
        for (i = 1; i <= n; i++) {
            cin >> a; tc.insert(a);
        }
        for (i = 1; i <= m; i++) {
            cin >> k;
            for (j = 1; j <= k; j++) {
                cin >> x; adj[i].pb({x, tt + j});
                avg[i] += x; sm[i] += x;
            }
            tt += k; avg[i] = (avg[i] + k - 1) / k;
            sort(adj[i].begin(), adj[i].end());
        }

        solve(1, m, flag[0]);

        for (i = 1; i <= tt; i++) cout << rs[i];
        cout << nl;
    }

    return 0;
}