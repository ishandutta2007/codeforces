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

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};
struct LCA {
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
    void dfs(vector<vi>& C, int v, int par) {
        time[v] = T++;
        for (int y : C[v]) if (y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }

    int lca(int a, int b) {
        if (a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
    //dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a+b; } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

const int A = 20;

struct Query{
    int u, v, lu, lv, lca, idx;
    int ans;
    Query(int u, int v, int lca, int idx) : u(u), v(v), lca(lca), idx(idx) {}
};

struct Node{
    int idx;
    Node* par;
    vector<Node*> children;
    int best_route;
    vector<Node*> lift;
    vector<Node*> edge_lift;
    vector<Query*> queries;
    vector<Node*> route_destinations;
    int depth;
    Node(int idx, Node* par) : idx(idx), par(par) {
        lift.resize(A);
        edge_lift.resize(A);
    }
    
    void add_child(Node* x){
        children.push_back(x);
    }

    void dfs1(){
        for(Node* x : children){
            x->depth = depth+1;
            x->dfs1();
        }
    }

    void dfs2(vi &first, vi &last, int &time){
        first[idx] = time;
        time++;
        for(Node* x : children){
            x->dfs2(first, last, time);
        }
        last[idx] = time;
    }

    void dfs3(vi &first, vi &last, Tree &st){
        debug(idx);
        vi before(queries.size());
        for(int i = 0; i < queries.size(); i++){
            before[i] = st.query(first[queries[i]->lv], last[queries[i]->lv]);
        }
        for(int i = 0; i < route_destinations.size(); i++){
            debug("upd", route_destinations[i]->idx);
            st.update(first[route_destinations[i]->idx], 1);
        }
        for(Node* x : children){
            x->dfs3(first, last, st);
        }
        debug(idx, 2);
        for(int i = 0; i < queries.size(); i++){
            int upd = st.query(first[queries[i]->lv], last[queries[i]->lv]);
            debug(queries[i]->idx, upd, before[i]);
            debug(first[queries[i]->lv], last[queries[i]->lv]);
            if(upd == before[i]){
                queries[i]->ans += 2;
            }else{
                queries[i]->ans += 1;
            }
        }
    }

    // #jumps required to get to x within 1 more jump
    pair<int, Node*> jumps(Node* x){
        debug(lift[A-1]->idx, x->idx);
        if(lift[A-1]->idx > x->idx) return {-1, 0};
        Node* cur = this;
        int ans = 0;
        for(int i = A-1; i >= 0; i--){
            if(cur->lift[i]->idx > x->idx){
                ans += (1<<i);
                cur = cur->lift[i];
            }
        }
        return {ans, cur};
    }

    Node* up(int steps){
        Node* cur = this;
        for(int i = A-1; i >= 0; i--){
            if(steps >= (1<<i)){
                steps -= (1<<i);
                cur = cur->edge_lift[i];
            }
        }
        return cur;
    }

    // returns which child subtree the node is on
    Node* subtree(Node* x){
        return x->up(x->depth-depth-1);
    }
};

struct Route{
    int u, v, lca;
    Route(int u, int v, int lca) : u(u), v(v), lca(lca) {}
};
void __print(Route r) { cerr << '{' << r.u << ',' << r.v << ',' << r.lca << '}'; }


void solve(){
    int n;
    cin >> n;
    vector<Node*> nodes;
    Node* root = new Node(0, 0);
    nodes.push_back(root);
    vvi adji(n);
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        Node* n = new Node(i, nodes[x]);
        adji[i].push_back(x);
        adji[x].push_back(i);
        nodes[x]->add_child(n);
        nodes.push_back(n);
    }

    debug(1);
    root->depth = 0;
    root->dfs1();
    debug(2);

    LCA lca(adji);

    int m;
    cin >> m;
    vector<Route> routes;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        routes.push_back(Route(u, v, lca.lca(u, v)));
        nodes[u]->route_destinations.push_back(nodes[v]);
        nodes[v]->route_destinations.push_back(nodes[u]);
    }
    debug(routes);
    vi best_route(n);
    iota(best_route.begin(), best_route.end(), 0);
    for(Route r : routes){
        best_route[r.u] = min(best_route[r.u], r.lca);
        best_route[r.v] = min(best_route[r.v], r.lca);
    }
    for(int i = n-1; i >= 1; i--){
        best_route[nodes[i]->par->idx] = min(best_route[i], best_route[nodes[i]->par->idx]);
    }
    debug(best_route);
    for(Node* x : nodes){
        x->best_route = best_route[x->idx];
        x->lift[0] = nodes[x->best_route];
        x->edge_lift[0] = (x->idx == 0 ? x : x->par);
    }
    for(int i = 1; i < A; i++){
        for(Node* x : nodes){
            x->lift[i] = x->lift[i-1]->lift[i-1];
            x->edge_lift[i] = x->edge_lift[i-1]->edge_lift[i-1];
        }
    }
    debug(1);

    vi tour(n), first(n), last(n);
    int time = 0;
    root->dfs2(first, last, time);
    debug(time);
    debug(first, last);

    int q;
    cin >> q;
    vector<Query*> queries(q);
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        queries[i] = new Query(u, v, lca.lca(u, v), i);
        auto pa = nodes[u]->jumps(nodes[queries[i]->lca]);
        auto pb = nodes[v]->jumps(nodes[queries[i]->lca]);
        debug(i, pa.first, pb.first);
        if(pa.first == -1 || pb.first == -1){
            queries[i]->ans = -1;
            continue;
        }
        if(queries[i]->u == queries[i]->lca){
            queries[i]->ans = pb.first + 1;
            continue;
        }else if(queries[i]->v == queries[i]->lca){
            queries[i]->ans = pa.first + 1;
            continue;
        }
        queries[i]->ans = pa.first + pb.first;
        queries[i]->lu = pa.second->idx;
        queries[i]->lv = pb.second->idx;
        debug(i, queries[i]->lu, queries[i]->lv);
        nodes[queries[i]->lu]->queries.push_back(queries[i]);
    }

    Tree st(n);
    
    root->dfs3(first, last, st);
    
    vi ans(q);
    for(Query* query : queries){
        ans[query->idx] = query->ans;
    }
    for(int i : ans){
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}