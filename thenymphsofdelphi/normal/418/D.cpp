#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

const int N = 1e5 + 5, LN = 17;

struct segment_tree{
    int seg[1 << 18], lazy[1 << 18];

    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            lazy[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        seg[id] = 0;
        lazy[id] = 0;
    }

    void down(int id){
        if (lazy[id] == 0){
            return;
        }
        seg[id * 2] += lazy[id];
        seg[id * 2 + 1] += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (v < l or r < u){
            return;
        }
        if (u <= l and r <= v){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return -1;
        }
        if (u <= l and r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
} it;

int n;
vi adj[N];
int q;
pii a[N];

int par[N][LN], h[N];
int ctrtime, tin[N], tout[N];

void dfs_par(int u, int p){
    ctrtime++; tin[u] = tout[u] = ctrtime;
    For(j, 1, LN){
        par[u][j] = par[par[u][j - 1]][j - 1];
    }
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        par[v][0] = u;
        h[v] = h[u] + 1;
        dfs_par(v, u);
    }
    tout[u] = ctrtime;
}

bool is_ancestor(int u, int v){
    if (u == 0){
        return 1;
    }
    return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v){
    if (h[u] > h[v]){
        swap(u, v);
    }
    if (is_ancestor(u, v)){
        return u;
    }
    FordE(i, LN - 1, 0){
        if (!is_ancestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}

pii middle(int u, int v){
    int w = lca(u, v);
    int d = h[u] + h[v] - 2 * h[w];
    int ud = (d - 1) / 2;
    FordE(i, LN - 1, 0){
        if (ud & (1 << i)){
            u = par[u][i];
        }
    }
    return make_pair(u, par[u][0]);
}



int ans[N];
vpii vquery[N];

void dfs_reroot(int u, int p){
    Fora(&query, vquery[u]){
        int v, idx; tie(v, idx) = query;
        if (is_ancestor(v, u)){
            int wv = u;
            FordE(i, LN - 1, 0){
                if (h[wv] - (1 << i) > h[v]){
                    wv = par[wv][i];
                }
            }
            ans[idx] = max(ans[idx], it.get(1, 1, n, tin[wv], tout[wv]));
        }
        else{
            ans[idx] = max({ans[idx], it.get(1, 1, n, 1, tin[v] - 1), it.get(1, 1, n, tout[v] + 1, n)});
        }
    }

    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        it.update(1, 1, n, 1, n, 1);
        it.update(1, 1, n, tin[v], tout[v], -2);
        dfs_reroot(v, u);
        it.update(1, 1, n, 1, n, -1);
        it.update(1, 1, n, tin[v], tout[v], 2);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs_par(1, 1);
    cin >> q;
    ForE(i, 1, q){
        int u, v; cin >> u >> v;
        if (h[u] < h[v]){
            swap(u, v);
        }
        a[i] = make_pair(u, v);
        int wu, wv; tie(wu, wv) = middle(u, v);
        vquery[u].emplace_back(wv, i);
        vquery[v].emplace_back(wu, i);
    }

    ForE(u, 1, n){
        it.update(1, 1, n, tin[u], tin[u], h[u]);
    }
    dfs_reroot(1, 1);
    ForE(i, 1, q){
        cout << ans[i] << endl;
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