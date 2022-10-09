#pragma GCC optimize("Ofast")

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll p1[maxn], p2[maxn], l[maxn], r[maxn], f[maxn], x;
vector<ll> adj[maxn];
queue<ll> q;
set<ll> st;

void upd(ll l, ll r) {
    // cout << "upd" _ l _ r << nl;
    ll i, pv, rr;
    vector<ll> v;
    auto it = st.lower_bound(l);
    assert(it == st.end() || (*it) > l);
    while (true) {
        if (it == st.end()) break;
        if ((*it) > r) break;
        v.pb((*it)); it++;
    }
    for (auto u : v) st.erase(u), q.push(u);
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
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; p1[i] = p1[i - 1] + a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i]; p2[i] = p2[i - 1] + b[i];
        }

        st.clear();
        while (!q.empty()) q.pop();
        for (i = 1; i <= n; i++) st.insert(i);
        for (i = 0; i <= n; i++) {
            if (p1[i] == p2[i]) st.erase(i), q.push(i);
            adj[i].clear();
        }

        for (i = 1; i <= m; i++) {
            cin >> l[i] >> r[i]; l[i]--; f[i] = 0;
            adj[l[i]].pb(i); adj[r[i]].pb(i);
        }

        while (!q.empty()) {
            x = q.front(); q.pop();
            // cout << "x =" _ x << nf;
            for (auto u : adj[x]) {
                f[u]++;
                if (f[u] == 2) upd(l[u], r[u]);
            }
        }

        if (st.size() == 0) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}