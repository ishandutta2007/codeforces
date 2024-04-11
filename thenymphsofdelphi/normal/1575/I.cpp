#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

template <typename T>
struct Segment_Tree{
    const T unit = 0;

    inline T f(T x, T y){
        return x + y;
    }

    int n;
    vector <T> seg;

    Segment_Tree(int n): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n);
    }

    void Build(int id, int l, int r){
        if (l == r){
            seg[id] = unit;
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid);
        Build(id << 1 | 1, mid + 1, r);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    Segment_Tree(int n, vector <T>& a): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n, a);
    }

    void Build(int id, int l, int r, vector <T>& a){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid, a);
        Build(id << 1 | 1, mid + 1, r, a);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void Update(int i, T val){
        Update(1, 1, n, i, val);
    }

    void Update(int id, int l, int r, int i, T val){
        if (i < l || r < i){
            return;
        }
        if (i <= l && r <= i){
            seg[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        Update(id << 1, l, mid, i, val);
        Update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    T Get(int u, int v){
        return Get(1, 1, n, u, v);
    }

    T Get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return unit;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return f(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
    }
};

int n, q;
int a[N];
vi adj[N];

int par[N], h[N];
int sz[N];
int ctrtour, tour[N], tin[N], tout[N], nxt[N];

void dfs_par(int u){
    Fora(v, adj[u]){
        if (v == par[u]){
            continue;
        }
        par[v] = u;
        h[v] = h[u] + 1;
        dfs_par(v);
    }
    For(i, 0, isz(adj[u])){
        if (adj[u][i] == par[u]){
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
}

void dfs_sz(int u){
    sz[u] = 1;
    Fora(&v, adj[u]){
        dfs_sz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]]){
            swap(v, adj[u][0]);
        }
    }
}

void dfs_tour(int u){
    tour[++ctrtour] = u;
    tin[u] = ctrtour;
    Fora(v, adj[u]){
        nxt[v] = (v == adj[u][0] ? nxt[u] : v);
        dfs_tour(v);
    }
    tout[u] = ctrtour;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(u, 1, n){
        cin >> a[u]; a[u] = abs(a[u]);
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs_par(1);
    dfs_sz(1);
    nxt[1] = 1;
    dfs_tour(1);
    Segment_Tree <ll> cac(n);
    ForE(u, 1, n){
        cac.Update(tin[u], a[u]);
    }
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int u, val; cin >> u >> val; val = abs(val);
            cac.Update(tin[u], val);
        }
        else{
            int u, v; cin >> u >> v;
            ll sum = 0;
            sum -= cac.Get(tin[u], tin[u]) + cac.Get(tin[v], tin[v]);
            while (nxt[u] != nxt[v]){
                if (h[nxt[u]] < h[nxt[v]]){
                    swap(u, v);
                }
                sum += cac.Get(tin[nxt[u]], tin[u]) * 2;
                u = par[nxt[u]];
            }
            if (h[u] > h[v]){
                swap(u, v);
            }
            sum += cac.Get(tin[u], tin[v]) * 2;
            cout << sum << endl;
        }
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/