// 1380E
// Merging Towers

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, tot, sz[maxn], parent[maxn], u, v;
vector<ll> adj[maxn];

ll find(ll x) {
    while (x != parent[x]) x = parent[x];
    return x;
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void merge(ll a, ll b) {
    // cout << a << ' ' << b << nl;
    a = find(a); b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    for (auto u : adj[b]) {
        u = find(u);
        // cout << u << nl;
        if (u == a) tot--;
        else adj[a].pb(u);
    }
    parent[b] = a; sz[a] += sz[b];
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= m; i++) {
        sz[i] = 1; parent[i] = i;
    }

    shuffle(sz + 1, sz + m + 1, rng);

    /* for (i = 1; i <= m; i++) {
        cout << sz[i] << ' ';
    }
    cout << nl; */

    tot = 0;
    for (i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            adj[a[i - 1]].pb(a[i]); adj[a[i]].pb(a[i - 1]);
            tot++;
        }
    }

    cout << tot << nl; m--;
    while (m--) {
        cin >> u >> v;
        merge(u, v);
        /* for (i = 1; i <= 4; i++) {
            cout << "i: ";
            for (auto u : adj[i]) cout << u << ' ';
            cout << nl;
        } */
        cout << tot << nl;
    }

    return 0;
}