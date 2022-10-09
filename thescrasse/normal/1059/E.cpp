// 1059E
// Split the Tree

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l, s, w[maxn], dist[maxn], parent[maxn], ps[maxn];
vector<ll> adj[maxn];
bool visited[maxn];
set<array<ll, 2>> ms[maxn];

void merge(ll a, ll b) {
    if (ms[a].size() < ms[b].size()) swap(ms[a], ms[b]);
    for (auto u : ms[b]) ms[a].insert(u);
}

void clean(ll a) {
    vector<array<ll, 2>> v;
    for (auto u : ms[a]) {
        if (u[0] - dist[a] > l || u[1] - ps[parent[a]] > s) v.pb(u);
    }
    for (auto u : v) ms[a].erase(u);
}

void dfs(ll s) {
    // cout << "dfs " << s << nf;
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true; parent[u] = s;
        dist[u] = dist[s] + 1; ps[u] = ps[s] + w[u];
        dfs(u);
        merge(s, u);
    }
    clean(s);
    if (ms[s].empty()) {
        res++; ms[s].insert({dist[s], ps[s]});
    }
    // for (auto u : ms[s]) cout << s << ' ' << u[0] << ' ' << u[1] << nf;
}

void init(ll s) {
    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }
    parent[1] = 0; ps[0] = 0;
    visited[s] = true; dist[s] = 0; ps[s] = w[s]; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> l >> s; l--;
    for (i = 1; i <= n; i++) {
        cin >> w[i];
        if (w[i] > s) {
            cout << -1; return 0;
        }
    }
    for (i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i); adj[i].pb(a);
    }

    init(1);
    cout << res << nl;

    return 0;
}