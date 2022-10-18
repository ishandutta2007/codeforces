#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5, M = log2(N) + 1;

int n, q;
int a[N];
int tim, euler[N], in[N], ou[N];

struct lazy_segment_tree{
    int seg[4 * N], lazy[4 * N];
    
    void down(int id, int l, int r){
        if (!lazy[id]) return;
        int mid = (l + r) >> 1;
        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = a[euler[l]];
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

vector <int> adj[N];
int memo[N][M + 1], h[N];

void dfs(int u, int p){
    tim++;
    euler[tim] = u;
    in[u] = tim;
    memo[u][0] = p;
    for (int i = 1; i <= M; i++){
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    h[u] = h[p] + 1;
    for (auto &v: adj[u]){
        if (v == p) continue;
        dfs(v, u);
    }
    ou[u] = tim;
}

int lca(int u, int v){
    // cout << "LCA " << u << ' ' << v << ' ';
    if (h[u] < h[v]){
        swap(u, v);
    }
    for (int i = M; i >= 0; i--){
        if (h[u] - (1 << i) >= h[v]){
            u = memo[u][i];
        }
    }
    // cout << u << ' ' << v << ' ';
    if (u == v){
        // cout << "FIN " << u << endl;
        return u;
    }
    for (int i = M; i >= 0; i--){
        if (memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    // cout << u << ' ' << v << ' ';
    // cout << "FIN " << memo[u][0] << endl;
    return memo[u][0];
}

int nearlca(int u, int v){
    // cout << "NEARLCA " << u << ' ' << v << ' ';
    if (u == v){
        // cout << "FIN -1" << endl;
        return -1;
    }
    if (h[u] < h[v]){
        swap(u, v);
    }
    for (int i = M; i >= 0; i--){
        if (h[u] - (1 << i) > h[v]){
            u = memo[u][i];
        }
    }
    // cout << u << ' ' << v << ' ';
    // cout << "FIN " << u << endl;
    return u;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    it.build(1, 1, n);
    int root = 1;
    while (q--){
        int que; cin >> que;
        if (que == 1){
            cin >> root;
        }
        if (que == 2){
            int u, v, w, val; cin >> u >> v >> val;
            int x = lca(u, v), y = lca(v, root), z = lca(root, u);
            if (x == y) w = z;
            if (y == z) w = x;
            if (z == x) w = y;
            // cout << "B " << u << ' ' << v << ' ' << x << ' ' << y << ' ' << z << ' ' << w << endl;
            if (in[w] <= in[root] && ou[root] <= ou[w]){ // root is in w
                // cout << "#1" << endl;
                it.update(1, 1, n, 1, n, val);
                if (root != w){
                    int nw = nearlca(w, root);
                    it.update(1, 1, n, in[nw], ou[nw], -val);
                }
            }
            else{
                // cout << "#2" << endl;
                it.update(1, 1, n, in[w], ou[w], val);
            }
        }
        if (que == 3){
            int v, ans = 0; cin >> v;
            if (in[v] <= in[root] && ou[root] <= ou[v]){ // root is in w
                ans = it.get(1, 1, n, 1, n);
                if (in[v] != ou[v]){
                    int nv = nearlca(v, root);
                    ans -= it.get(1, 1, n, in[nv], ou[nv]);
                }
            }
            else{
                ans = it.get(1, 1, n, in[v], ou[v]);
            }
            cout << ans << endl;
        }
        // for (int i = 1; i <= n; i++){
        //     cout << it.get(1, 1, n, in[i], in[i]) << ' ';
        // } cout << endl;
    }
}