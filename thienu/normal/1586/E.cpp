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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, madd = 0, nzero = 1, none = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            nzero = l->nzero + r->nzero;
            none = l->none + r->none;
        }else{
            nzero = (v[lo] == 0);
            none = (v[lo] == 1);
        }
    }
    int get_value(int idx){
        push();
        if(lo == idx && hi == idx+1) return none;
        if(r->lo <= idx) return r->get_value(idx);
        else return l->get_value(idx);
    }
    // int query(int L, int R) {
    //     if (R <= lo || hi <= L) return -inf;
    //     if (L <= lo && hi <= R) return val;
    //     push();
    //     return max(l->query(L, R), r->query(L, R));
    // }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            madd ^= x;
            if(x){
                swap(nzero, none);
            }
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            nzero = l->nzero + r->nzero;
            none = l->none + r->none;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
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
        process(u, v, [&](int l, int r) { tree->add(l, r, val); });
    }
    // int queryPath(int u, int v) { // Modify depending on problem
    //     int res = -1e9;
    //     process(u, v, [&](int l, int r) {
    //             res = max(res, tree->query(l, r));
    //     });
    //     return res;
    // }
    // int querySubtree(int v) { // modifySubtree is similar
    //     return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    // }
};

vi par;

void dfs(int u, vvi &adj, vvi &tadj, vi &vis){
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v]) continue;
        tadj[u].push_back(v);
        tadj[v].push_back(u);
        par[v] = u;
        dfs(v, adj, tadj, vis);
    }
}

bool getPath(int u, int e, int last, vector<int> &path, vvi &adj){
    path.push_back(u);
    if(u == e) return true;
    for(int v : adj[u]){
        if(v == last) continue;
        bool success = getPath(v, e, u, path, adj);
        if(success) return true;
    }
    path.pop_back();
    return false;
}

void dfs2(int u, int last, vi &bad, vvi &adj, int &ans, vi &vis, bool start = true){
    debug(u, last);
    vis[u] = 1;
    int tot = !start;
    for(int v : adj[u]){
        if(v == last) continue;
        dfs2(v, u, bad, adj, ans, vis, false);
        if(bad[v]) tot++;
    }
    ans += tot / 2;
    bad[u] = tot & 1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    par.resize(n);

    vvi tadj(n);
    vi vis(n);
    dfs(0, adj, tadj, vis);
    debug(tadj);
    
    HLD<true> hld(tadj);
    int q;
    cin >> q;
    vector<pii> queries;
    vi cnt(n);
    while(q--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        queries.push_back({x, y});
        hld.modifyPath(x, y, 1);
        cnt[x] ^= 1;
        cnt[y] ^= 1;
    }
    int tot = 0;
    for(int i = 0; i < n; i++) tot += cnt[i];
    debug(hld.tree->none);

    if(hld.tree->none == 0){
        cout << "YES" << endl;
        for(int i = 0; i < queries.size(); i++){
            vi path;
            getPath(queries[i].first, queries[i].second, -1, path, tadj);
            cout << path.size() << endl;
            for(int j : path) cout << j+1 << ' ';
            cout << endl;
        }
        return;
    }

    cout << "NO" << endl;
    cout << tot/2 << endl;

    // vvi radj(n);
    // for(int i = 1; i < n; i++){
    //     debug(i, hld.tree->get_value(hld.pos[i]));
    //     if(hld.tree->get_value(hld.pos[i])){
    //         radj[i].push_back(par[i]);
    //         radj[par[i]].push_back(i);
    //     }
    // }
    // debug(radj);
    // int ans = 0;
    // // for(int i = 0; i < n; i++){
    // //     if(radj[i].size() <= 1) ans++;
    // // }
    // debug(radj);
    // debug(ans);

    // fill(vis.begin(), vis.end(), 0);
    // for(int i = 0; i < n; i++){
    //     if(vis[i]) continue;
    //     vi bad(n);
    //     dfs2(i, -1, bad, radj, ans, vis);
    //     if(bad[i]) ans++; // after contest: not needed?
    //     // debug(i);
    //     // ans--;
    //     // queue<int> qq;
    //     // qq.push(i);
    //     // vis[i] = 1;
    //     // while(!qq.empty()){
    //     //     int u = qq.front();
    //     //     qq.pop();
    //     //     for(int v : radj[u]){
    //     //         if(vis[v]) continue;
    //     //         vis[v] = 1;
    //     //         qq.push(v);
    //     //     }
    //     // }
    //     // debug(vis);
    // }
    // cout << "NO" << endl;
    // cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}