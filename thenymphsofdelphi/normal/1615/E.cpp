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

const int N = 2e5 + 5;

struct lazy_segment_tree{
    pii seg[4 * N]; int lazy[4 * N];
    
    void down(int id){
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1].fi += lazy[id];
        seg[id << 1 | 1].fi += lazy[id];
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = make_pair(0, l);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id].fi += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }
    
    pii get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return make_pair(INT_MIN, 0);
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

int n, k;
vi adj[N];

int par[N], h[N], sz[N], cntchild[N]; set <int> sttchild[N];
int ctrtour, tour[N], tin[N], tout[N];

void dfs(int u){
    tour[++ctrtour] = u;
    tin[u] = ctrtour;
    sz[u] = 1;
    Fora(v, adj[u]){
        if (v == par[u]){
            continue;
        }
        par[v] = u; h[v] = h[u] + 1; cntchild[u]++; sttchild[u].insert(v);
        dfs(v);
        sz[u] += sz[v];
    }
    tout[u] = ctrtour;
}

bool mark[N];
int r, b; ll ans = LLONG_MIN;

ll calans(int r, int b){
    return (ll)r * (n - r) - (ll)b * (n - b);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    h[1] = 1;
    dfs(1);
    int leaf = 0;
    ForE(i, 1, n){
        leaf += (sz[i] == 1);
    }
    it.build(1, 1, n);
    r = 0; b = n;
    ForE(i, 1, n){
        if (sz[i] == 1){
            it.update(1, 1, n, tin[i], tout[i], h[i]);
        }
    }
    ForE(turn, 1, min(leaf, k)){
        auto cac = it.get(1, 1, n, 1, n);
        r++; b -= cac.fi; ans = max(ans, calans(r, min(b, n / 2))); int u = tour[cac.se];
        {
            vi path;
            int tu = u;
            while (tu != 0 and mark[tu] == 0){
                path.emplace_back(tu);
                tu = par[tu];
            }
            reverse(bend(path));
            Fora(tu, path){
                it.update(1, 1, n, tin[tu], tout[tu], -1);
                mark[tu] = 1;
            }
        }
    }
    if (k > leaf){
        ForE(r, leaf + 1, k){
            ans = max(ans, calans(r, 0));
        }
    }
    cout << ans << endl;
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