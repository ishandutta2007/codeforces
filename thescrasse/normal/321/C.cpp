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
ll sz[maxn];
bool vis[maxn];
char rs[maxn];
vector<ll> adj[maxn];

void dfs1(ll s, ll p) {
    sz[s] = 1;
    for (auto u : adj[s]) {
        if (u == p) continue;
        if (vis[u]) continue;
        dfs1(u, s);
        sz[s] += sz[u];
    }
}

ll dfs2(ll s, ll p, ll csz) {
    /* cout << "dfs2 start " << s << nl;
    for (ll i = 1; i <= n; i++) cout << sz[i] << ' ';
    cout << nl; */

    for (auto u : adj[s]) {
        if (u == p) continue;
        if (vis[u]) continue;
        if (sz[u] > csz / 2) return dfs2(u, s, csz);
    }
    // cout << "dfs2 found " << s << nl;
    return s;
}

void dfs3(ll s, char ch) {
    dfs1(s, -1);
    ll c = dfs2(s, -1, sz[s]);
    vis[c] = true; rs[c] = ch;
    for (auto u : adj[c]) {
        if (vis[u]) continue;
        dfs3(u, ch + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs3(1, 'A');

    for (i = 1; i <= n; i++) cout << rs[i] << ' ';
    cout << nl;

    return 0;
}