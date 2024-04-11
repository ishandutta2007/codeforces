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
ll dist[maxn], parent[maxn], jm[21][maxn], sb[maxn];
ll r[maxn], fs[maxn];
bool vis[maxn];
array<ll, 2> o;
vector<ll> adj[maxn];

void dfs(ll s) {
    ll i;
    // cout << "dfs " << s << nl;
    sb[s] = 1;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        vis[u] = true; parent[u] = s;
        dist[u] = dist[s] + 1;
        jm[0][u] = s;
        for (i = 1; i <= 20; i++) {
            jm[i][u] = jm[i - 1][jm[i - 1][u]];
        }
        dfs(u);
        sb[s] += sb[u];
    }
}

void init(ll s) {
    ll i, j;
    for (i = 1; i <= n; i++) vis[i] = false;
    for (i = 0; i <= 20; i++) {
        for (j = 1; j <= n; j++) {
            jm[i][j] = 0;
        }
    }
    vis[s] = true; parent[s] = 0; dfs(s);
}

ll kth(ll x, ll k) {
    ll i;
    for (i = 20; i >= 0; i--) {
        if ((k >> i) & 1) x = jm[i][x];
    }
    return x;
}

ll lca(ll a, ll b) {
    ll i;
    // cout << "lca " << a _ b << nl;
    if (dist[a] < dist[b]) swap(a, b);
    a = kth(a, dist[a] - dist[b]);
    // cout << "a, b = " << a _ b << nl;
    if (a == b) return a;
    for (i = 20; i >= 0; i--) {
        if (jm[i][a] != jm[i][b]) {
            a = jm[i][a]; b = jm[i][b];
        }
    }
    // cout << "a, b, parent[a] = " << a _ b _ parent[a] << nl;
    return parent[a];
}

ll ext_size(array<ll, 2> o) {
    ll a, b, k;
    a = o[0]; b = o[1];
    if (a == b) {
        k = ((sb[a] * (sb[a] - 1)) / 2) + (sb[a] * (n - sb[a]));
        for (auto u : adj[a]) {
            if (u == parent[a]) continue;
            k -= ((sb[u] * (sb[u] - 1)) / 2);
        }
        return k;
    }
    k = lca(a, b);
    if (k == b) swap(a, b);
    if (k == a) return (sb[b] * (n - sb[kth(b, dist[b] - dist[a] - 1)]));
    return sb[a] * sb[b];
}

bool same(ll a, ll b, ll c) {
    ll x, y, z;

    if (dist[a] < dist[b]) swap(a, b);
    if (dist[b] < dist[c]) swap(b, c);
    if (dist[a] < dist[b]) swap(a, b);
    if (dist[b] < dist[c]) swap(b, c);

    x = lca(a, b); y = lca(a, c); z = lca(b, c);
    if (x == b && y == c && z == c) return true;
    if (y == c) {
        swap(b, c);
    } else if (z == c) {
        swap(a, b); swap(b, c);
    } else if (x != b) {
        return false;
    }

    // cout << a _ b _ c _ dist[y] _ dist[b] << nl;
    x = lca(a, b); y = lca(a, c); z = lca(b, c);
    if (z != y) return false;
    return true;
}

array<ll, 2> upd_path(array<ll, 2> o, ll x) {
    ll a, b, c, d, k;
    a = o[0]; b = o[1];
    k = lca(a, b);
    if (k == b) swap(a, b);
    if (!same(a, b, x)) return {-1, -1};
    if (k == a) {
        c = lca(a, x); d = lca(x, b);
        if (c == a && d == x) return {a, b};
        if (c == a && d == b) return {a, x};
        return {b, x};
    } else {
        c = lca(a, x); d = lca(x, b);
        if (c == a) return {b, x};
        if (d == b) return {a, x};
        return {a, b};
    }
}

void slow() {
    ll i, j, k, l, i1, j1;
    bool vis[31];
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            k = lca(i, j);
            for (l = 0; l <= 30; l++) vis[l] = false;
            vis[k - 1] = true; i1 = i; j1 = j;
            while (i1 != k) {
                vis[i1 - 1] = true; i1 = parent[i1];
            }
            while (j1 != k) {
                vis[j1 - 1] = true; j1 = parent[j1];
            }
            for (l = 0; l <= 30; l++) {
                if (!vis[l]) {
                    fs[l]++; break;
                }
            }
        }
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
        cin >> n;
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 1; i <= n - 1; i++) {
            cin >> a >> b; a++; b++;
            adj[a].pb(b); adj[b].pb(a);
        }

        init(1);

        /* for (i = 1; i <= n; i++) cout << sb[i] << ' ';
        cout << nl; */

        r[0] = (n * (n - 1)) / 2;
        for (i = 1; i <= n; i++) {
            if (i == 1) o = {i, i};
            else o = upd_path(o, i);
            if (o[0] == -1) r[i] = 0;
            else r[i] = ext_size(o);

            // cout << i _ o[0] _ o[1] _ ext_size(o) << nl;
        }
        r[n + 1] = 0;

        for (i = 0; i <= n; i++) r[i] -= r[i + 1];

        for (i = 0; i <= n; i++) cout << r[i] << ' ';
        cout << nl;

        /* slow();
        for (i = 0; i <= n; i++) cout << fs[i] << ' ';
        cout << nl; */
    }

    return 0;
}