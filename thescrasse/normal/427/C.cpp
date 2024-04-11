#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c[maxn], rs[2];
array<ll, 2> o;
bool vis[maxn];
vector<ll> adj[maxn], adjr[maxn], ts;

void dfs1(ll s) {
    if (vis[s]) return;
    vis[s] = true;
    for (auto u : adj[s]) dfs1(u);
    ts.pb(s);
}

void dfs2(ll s) {
    if (vis[s]) return;
    vis[s] = true;
    if (c[s] < o[0]) o = {c[s], 1};
    else if (c[s] == o[0]) o[1]++;
    for (auto u : adjr[s]) dfs2(u);
}

void init() {
    ll i;
    for (i = 1; i <= n; i++) vis[i] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> c[i];
    }
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].pb(b); adjr[b].pb(a);
    }

    for (i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs1(i);
    }

    init(); reverse(ts.begin(), ts.end()); rs[1] = 1;
    for (auto u : ts) {
        if (vis[u]) continue;
        // cout << "dfs2 " << u << nl;
        o = {INF, 0}; dfs2(u);
        rs[0] += o[0]; rs[1] *= o[1]; rs[1] %= mod;
    }

    cout << rs[0] _ rs[1] << nl;

    return 0;
}