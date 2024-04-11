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


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct Query{
    int u, v, x;
    Query(int _u, int _v, int _x) : u(_u), v(_v), x(_x) {};
};

int find_parent(vi &par, int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = find_parent(par, par[u]);
}

bool merge(vi &par, int a, int b){
    a = find_parent(par, a);
    b = find_parent(par, b);
    debug(a, b);
    if(a == b) return false;
    par[a] = b;
    return true;
}

// hld, source: kactl
const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){val = 0;} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};

template <bool VALS_EDGES> struct HLD {
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node *tree;
    HLD(vector<vi> adj_)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
    void dfsSz(int v) {
        if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
        for (int& u : adj[v]) {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v) {
        pos[v] = tim++;
        for (int u : adj[v]) {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template <class B> void process(int u, int v, B op) {
        for (; rt[u] != rt[v]; v = par[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, int val) {
        process(u, v, [&](int l, int r) { tree->set(l, r, val); });
    }
    int queryPath(int u, int v) { // Modify depending on problem
        int res = -1e9;
        process(u, v, [&](int l, int r) {
                res = max(res, tree->query(l, r));
        });
        return res;
    }
    int querySubtree(int v) { // modifySubtree is similar
        return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};

void dfs(vector<vpii> &adjw, int u, int last, vi &xor_sum){
    for(pii p : adjw[u]){
        if(p.first == last) continue;
        xor_sum[p.first] = xor_sum[u] ^ p.second;
        dfs(adjw, p.first, u, xor_sum);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<Query> queries;
    vi par(n);
    vvi adj(n);
    vector<vector<pii>> adjw(n);
    vi process(q);
    for(int i = 0; i < n; i++) par[i] = i;
    for(int i = 0; i < q; i++){
        int u, v, x;
        cin >> u >> v >> x;
        u--;v--;
        queries.push_back(Query(u, v, x));
        if(merge(par, u, v)){
            adj[u].push_back(v);
            adjw[u].push_back({v, x});
            adj[v].push_back(u);
            adjw[v].push_back({u, x});
            process[i] = 1;
        }
    }

    vi roots;
    for(int i = 0; i < n; i++){
        if(find_parent(par, i) == i) roots.push_back(i);
    }
    for(int i = 0; i < (int) roots.size() - 1; i++){
        adj[roots[i]].push_back(roots[i+1]);
        adj[roots[i+1]].push_back(roots[i]);
        adjw[roots[i]].push_back({roots[i+1], 0});
        adjw[roots[i+1]].push_back({roots[i], 0});
    }
    debug(process, adj);

    HLD<true> hld = HLD<true>(adj);
    vi xor_sum(n);
    dfs(adjw, 0, -1, xor_sum);
    
    for(int i = 0; i < q; i++){
        debug(i, queries[i].u, queries[i].v);
        if(process[i]){
            cout << "YES\n";
            continue;
        }
        int mark = hld.queryPath(queries[i].u, queries[i].v);
        int x = xor_sum[queries[i].u] ^ xor_sum[queries[i].v] ^ queries[i].x;
        debug(mark, x);
        if(mark || x == 0){
            cout << "NO\n";
            continue;
        }
        hld.modifyPath(queries[i].u, queries[i].v, 1);
        cout << "YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}