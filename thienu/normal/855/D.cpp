#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vvi adj;
vi traversal;
vi depth;
vi occ;
vi root;
vi roots;
int INF = 1e9 + 7;

void traverse(int u, int last, int d = 0){
    occ[u] = traversal.size();
    traversal.push_back(u);
    depth.push_back(d);
    for(int v : adj[u]){
        if(v == last) continue;
        traverse(v, u, d+1);
        traversal.push_back(u);
        depth.push_back(d);
    }
}

// min segtree
void st_build(vi &st, vi &stpos, int tl, int tr, int pos, vi &v){
    if(tl == tr){
        st[pos] = v[tl];
        stpos[pos] = tl;
        return;
    }
    st_build(st, stpos, tl, tl + (tr - tl) / 2, pos * 2, v);
    st_build(st, stpos, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, v);
    st[pos] = min(st[2 * pos], st[2 * pos + 1]);
    if(st[2 * pos] < st[2 * pos + 1]){
        stpos[pos] = stpos[2 * pos];
    }
    else{
        stpos[pos] = stpos[2 * pos + 1];
    }
}

// (val, pos)
pii st_minpos(vi &st, vi &stpos, int tl, int tr, int pos, int left, int right){
    if(right < tl || tr < left){
        return {INF, -1};
    }
    if(left <= tl && tr <= right){
        return {st[pos], stpos[pos]};
    }
    int v1, p1, v2, p2;
    tie(v1, p1) = st_minpos(st, stpos, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    tie(v2, p2) = st_minpos(st, stpos, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    if(v1 < v2){
        return {v1, p1};
    }
    else{
        return {v2, p2};
    }
}

int lca(vi &st, vi &stpos, int length, int u, int v){
    int x = min(occ[u], occ[v]);
    int y = max(occ[u], occ[v]);
    int value, pos;
    tie(value, pos) = st_minpos(st, stpos, 0, length - 1, 1, x, y);
    debug(x, y, value, pos);
    // debug(x, y, value, pos);
    return traversal[pos];
}

void solve(){
    int n;
    cin >> n;
    adj.resize(n);
    occ.resize(n);
    root.resize(n);

    vi parent(n);
    vi type(n);

    debug(parent);
    for(int i = 0; i < n; i++){
        cin >> parent[i] >> type[i];
        if(parent[i] != -1) parent[i]--;
    }
    
    vi ps(n), scs(n);
    for(int i = 0; i < n; i++){
        if(parent[i] != -1){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
            root[i] = root[parent[i]];
            if(type[i] == 0){
                scs[i] = scs[parent[i]] + 1;
                ps[i] = 0;
            }
            else{
                ps[i] = ps[parent[i]] + 1;
                scs[i] = 0;
            }
        }
        else{
            ps[i] = 0;
            scs[i] = 0;
            root[i] = i;
            roots.push_back(i);
        }
    }

    for(int i : roots){
        traverse(i, -1);
    }

    debug(traversal, depth, occ, root, scs, ps);

    vi st(traversal.size() * 4);
    vi stpos(traversal.size() * 4);
    
    st_build(st, stpos, 0, traversal.size() - 1, 1, depth);
    debug(st, stpos);
    debug(lca(st, stpos, traversal.size(), 2, 3));

    int q;
    cin >> q;
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        u--;
        v--;
        if(root[u] != root[v]){
            cout << "NO" << endl;
            continue;
        }
        int ca = lca(st, stpos, traversal.size(), u, v);
        debug(ca);
        if(t == 1){
            // is v a sc of u?
            debug(scs[v], depth[occ[v]], depth[occ[u]]);
            if(u == ca && v != u && scs[v] >= depth[occ[v]] - depth[occ[u]]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            // is v a part of u?
            debug(scs[u], ps[v], depth[occ[u]], depth[occ[v]], depth[occ[ca]]);
            if(ca != v && scs[u] >= -depth[occ[ca]] + depth[occ[u]] && ps[v] >= -depth[occ[ca]] + depth[occ[v]]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}