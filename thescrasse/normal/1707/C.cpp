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
ll pr[maxn], s_up[maxn], s_down[maxn], t_in[maxn], t_out[maxn];
ll t_cr, x, y, z, root;
bool used[maxn], vis[maxn];
vector<ll> adj[maxn];

ll find(ll x) {
    if (x == pr[x]) return x;
    return pr[x] = find(pr[x]);
}

bool same(ll a, ll b) {
    return (find(a) == find(b));
}

void onion(ll a, ll b) {
    a = find(a); b = find(b);
    if (a == b) return;
    pr[b] = a;
}

void dfs(ll s) {
    vis[s] = true;
    t_in[s] = t_cr; t_cr++;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        adj[u].erase(find(adj[u].begin(), adj[u].end(), s));
        // cout << "found" _ s _ u << nl;
        dfs(u);
    }
    t_out[s] = t_cr; t_cr++;
}

ll search(ll s, ll tm) {
    ll bsl, bsm, bsu;
    bsl = 0; bsu = (ll)adj[s].size();
    while (bsl != bsu) {
        bsm = (bsl + bsu) / 2;
        if (t_out[adj[s][bsm]] >= tm) bsu = bsm;
        else bsl = bsm + 1;
    }
    assert(bsl != (ll)adj[s].size());
    return adj[s][bsl];
}

void dfs_sum(ll s) {
    vis[s] = true;
    // cout << "dfs_sum" _ s _ s_up[s] << nl;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        s_up[u] += s_up[s];
        dfs_sum(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m; root = 1;
    for (i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }

    for (i = 1; i <= n; i++) pr[i] = i;

    for (i = 1; i <= m; i++) {
        if (!same(a[i], b[i])) {
            used[i] = true; onion(a[i], b[i]);
            adj[a[i]].pb(b[i]); adj[b[i]].pb(a[i]);
        }
    }

    dfs(root); // FIX

    for (i = 1; i <= m; i++) {
        if (used[i]) continue;
        x = a[i]; y = b[i];
        // cout << x _ y << nl;
        if (t_in[x] > t_in[y]) swap(x, y);
        if (t_out[x] < t_out[y]) {
            s_up[x]++; s_up[y]++;
            // cout << "different" _ x _ y << nl;
        } else {
            s_up[root]++; s_up[y]++;
            z = search(x, t_out[y]);
            s_up[z]--;
            // cout << "same" _ root _ z _ y << nl;
        }
    }

    for (i = 1; i <= n; i++) vis[i] = false;
    dfs_sum(root); // FIX

    for (i = 1; i <= n; i++) {
        if (s_up[i] == m - (n - 1)) cout << 1;
        else cout << 0;
    }
    cout << nl;

    return 0;
}