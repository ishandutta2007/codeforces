#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sb[maxn][2];
vector<ll> adj[maxn];
vector<ll> c, r;
bool visited[maxn];

void dfs(ll s) {
    sb[s][0] = 0; sb[s][1] = 0;
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        dfs(u);
        sb[s][0] = max(sb[s][0], sb[u][1] + 1);
        sb[s][1] += sb[u][1] + 1;
    }
    // cout << s << ' ' << sb[s][0] << ' ' << sb[s][1] << nl;
}

void init(ll s, ll x) {
    for (i = 1; i <= n; i++) visited[i] = false;
    if (x != -1) visited[x] = true;
    visited[s] = true; dfs(s);
}

ll fc() {
    ll m, s;
    m = INF; s = 0;
    for (i = 1; i <= n; i++) {
        if (sb[i][0] < m) {
            m = sb[i][0]; s = i;
        }
    }

    return m;
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
        cin >> n; c.clear(); r.clear();
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        init(1, -1);
        for (i = 1; i <= n; i++) sb[i][0] = max(sb[i][0], n - sb[i][1] - 1);
        k = fc();
        for (i = 1; i <= n; i++) {
            if (sb[i][0] == k) c.pb(i);
        }

        // for (auto u : c) cout << u << nl;

        if (c.size() == 1) {
            cout << 1 << ' ' << adj[1][0] << nl;
            cout << 1 << ' ' << adj[1][0] << nl;
        } else {
            if (adj[c[1]].size() == 1) swap(c[0], c[1]);
            if (adj[c[1]][0] == c[0]) swap(adj[c[1]][0], adj[c[1]][1]);
            cout << c[1] << ' ' << adj[c[1]][0] << nl;
            cout << c[0] << ' ' << adj[c[1]][0] << nl;
        }
    }

    return 0;
}