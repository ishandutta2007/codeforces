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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 3e5 + 5, M = 20;

int n;
vi adj[N];
int m;
pii paths[N];

void readTest(){
    cin >> n;
    ForE(i, 1, n){
        adj[i].clear();
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    ForE(i, 1, m){
        cin >> paths[i].fi >> paths[i].se;
    }
}

int height[N], par[N];
int ctr_eulertour; int lrmq[N], rrmq[N]; pii rmq[M][2 * N];
vi children[N]; int idxchild[N];
int cntpathvertex[N], cntpathvertexpar[N]; vi cntpathedge[N], cntpathedgepar[N];
vpii pathlca[N];
ll ans;

void dfs1(int u, int p){
    height[u] = height[p] + 1; par[u] = p;
    ctr_eulertour++; lrmq[u] = ctr_eulertour; rrmq[u] = ctr_eulertour; rmq[0][ctr_eulertour] = make_pair(height[u], u);
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs1(v, u);
        ctr_eulertour++; rrmq[u] = ctr_eulertour; rmq[0][ctr_eulertour] = make_pair(height[u], u);
        children[u].push_back(v); idxchild[v] = isz(children[u]) - 1;
    }
}

int lca(int u, int v){
    int l = min(lrmq[u], lrmq[v]), r = max(rrmq[u], rrmq[v]);
    int lg = __builtin_clz(r - l + 1) ^ 31;
    return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]).se;
}

struct lazy_segment_tree{
    int seg[4 * N], lazy[4 * N];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it;

int head[N], curpos, pos[N], invpos[N], heavy[N];

int dfs_hld(int u){
    int sz = 1, mxsz = -1;
    Fora(&v, adj[u]){
        if (v == par[u]) continue;
        int szv = dfs_hld(v);
        sz += szv;
        if (mxsz < szv){
            mxsz = szv;
            heavy[u] = v;
        }
    }
    return sz;
}

void decompose_hld(int u, int h){
    head[u] = h; pos[u] = ++curpos; invpos[curpos] = u;
    if (heavy[u]){
        decompose_hld(heavy[u], h);
    }
    Fora(v, adj[u]){
        if (v == par[u]) continue;
        if (v == heavy[u]) continue;
        decompose_hld(v, v);
    }
}

int nearlca(int u, int v){
    int ans = -1;
    while (head[u] != head[v]){
        ans = head[u];
        u = par[head[u]];
    }
    if (u == v){
        return ans;
    }
    return invpos[pos[v] + 1];
}

void update_hld(int u, int v, int val){
    while (head[u] != head[v]){
        if (height[head[u]] < height[head[v]]){
            swap(u, v);
        }
        it.update(1, 1, n, pos[head[u]], pos[u], val);
        u = par[head[u]];
    }
    if (height[u] < height[v]){
        swap(u, v);
    }
    it.update(1, 1, n, pos[v], pos[u], val);
}

int get_hld(int u, int v){
    int ans = 0;
    while (head[u] != head[v]){
        if (height[head[u]] < height[head[v]]){
            swap(u, v);
        }
        ans += it.get(1, 1, n, pos[head[u]], pos[u]);
        u = par[head[u]];
    }
    if (height[u] < height[v]){
        swap(u, v);
    }
    ans += it.get(1, 1, n, pos[v], pos[u]);
    return ans;
}

void dfs2(int u){
    ll tans = 0;
    map <pii, int> mpp;
    Fora(&v, pathlca[u]){
        int x = v.fi, y = v.se;
        if (x != u){
            x = idxchild[nearlca(x, u)];
            cntpathedge[u][x]++;
        }
        else{
            x = -1;
        }
        if (y != u){
            y = idxchild[nearlca(y, u)];
            cntpathedge[u][y]++;
        }
        else{
            y = -1;
        }
        if (x == -1 || y == -1){
            continue;
        }
        if (x > y){
            swap(x, y);
        }
        mpp[make_pair(x, y)]++;
    }
    tans += (ll)cntpathvertex[u] * (cntpathvertex[u] - 1) / 2;
    tans -= (ll)cntpathvertexpar[u] * (cntpathvertexpar[u] - 1) / 2;
    Fora(&v, cntpathedge[u]){
        tans -= (ll)v * (v - 1) / 2;
    }
    int tsum = 0;
    For(i, 0, isz(children[u])){
        tans -= (ll)cntpathedgepar[u][i] * (cntpathedgepar[u][i] - 1) / 2;
        tans -= (ll)cntpathedgepar[u][i] * (cntpathvertexpar[u] + cntpathedge[u][i] + tsum);
        tsum += cntpathedgepar[u][i];
    }
    Fora(&v, mpp){
        tans += (ll)v.se * (v.se - 1) / 2;
    }
    ans += tans;
    Fora(&v, adj[u]){
        if (v == par[u]){
            continue;
        }
        dfs2(v);
    }
}

void resetTest(){
    height[1] = -1;
    dfs1(1, 1);
    ForE(i, 1, n){
        cntpathedge[i].assign(isz(children[i]), 0);
        cntpathedgepar[i].assign(isz(children[i]), 0);
    }
    For(j, 1, M){
        ForE(i, 1, (2 * n - 1) - (1 << j) + 1){
            rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }
    dfs_hld(1);
    decompose_hld(1, 1);
    it.build(1, 1, n);
}

void solveTest(){
    ForE(i, 1, m){
        int u = paths[i].fi, v = paths[i].se;
        update_hld(u, v, 1);
    }
    ForE(i, 1, n){
        cntpathvertex[i] = get_hld(i, i);
    }
    ForE(i, 1, m){
        int u = paths[i].fi, v = paths[i].se, w = lca(u, v);
        pathlca[w].emplace_back(paths[i]);
        update_hld(w, w, -1);
        if (u != w){
            cntpathvertexpar[u]++;
            int x = (height[u] == height[w] + 1 ? u : nearlca(u, w));
            update_hld(x, x, -1);
        }
        if (v != w){
            cntpathvertexpar[v]++;
            int y = (height[v] == height[w] + 1 ? v : nearlca(v, w));
            update_hld(y, y, -1);
        }
    }
    ForE(i, 2, n){
        cntpathedgepar[par[i]][idxchild[i]] = get_hld(i, i);
    }
    dfs2(1);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readTest();
    resetTest();
    solveTest();
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