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

void dfs_depth(int u, int last, vi &depth, vvi &adj){
    for(int v : adj[u]){
        if(v == last) continue;
        depth[v] = depth[u] + 1;
        dfs_depth(v, u, depth, adj);
    }
}

void traverse(int u, int last, vi &traversal, vi &first_occ, vi &last_occ, vvi &adj){
    first_occ[u] = traversal.size();
    last_occ[u] = traversal.size();
    traversal.push_back(u);
    for(int v : adj[u]){
        if(v == last) continue;
        traverse(v, u, traversal, first_occ, last_occ, adj);
        last_occ[u] = traversal.size();
        traversal.push_back(u);
    }
}


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int INF = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    int mxor = 0;
    int d0 = 0, d1 = 0;
    Node(vi &depth, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(depth, lo, mid); r = new Node(depth, mid, hi);
            d0 = max(l->d0, r->d0);
        }
        else d0 = depth[lo], d1 = -INF;
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return -INF;
        if (L <= lo && hi <= R) return d0;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void toggle(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R){
            mxor ^= 1;
            swap(d0, d1);
        }
        else {
            push(), l->toggle(L, R), r->toggle(L, R);
            d0 = max(l->d0, r->d0);
            d1 = max(l->d1, r->d1);
        }
    }
    void push() {
        if (mxor != 0){
            l->toggle(lo,hi), r->toggle(lo,hi), mxor = 0;
        }
    }
};

struct Dist{
    vi tr, fi, la, dep;
    int n, m;
    Node* st;
    Dist(vvi &adj, int u, int n) : n(n) {
        fi.resize(n);
        la.resize(n);
        traverse(u, -1, tr, fi, la, adj);
        debug(tr, fi, la);
        dep.resize(n);
        dfs_depth(u, -1, dep, adj);
        debug(dep);
        m = tr.size();
        vi trav_depth(m);
        for(int i = 0; i < m; i++){
            trav_depth[i] = dep[tr[i]];
        }
        debug(u, trav_depth);
        st = new Node(trav_depth, 0, m);
    }

    void toggle(int u){
        debug(u);
        st->toggle(fi[u], la[u]+1);
    }

    void toggle(int u, int v){
        if(dep[u] > dep[v]) swap(u, v);
        toggle(v);
    }

    int query(){
        return st->query(0, m);
    }
};

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    vpii roads;
    vi edge_values;
    for(int i = 0; i+1 < n; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        roads.push_back({x, y});
        edge_values.push_back(w);
    }

    vi depth1(n);
    dfs_depth(0, -1, depth1, adj);
    int d1 = max_element(depth1.begin(), depth1.end()) - depth1.begin();
    vi depth2(n);
    dfs_depth(d1, -1, depth2, adj);
    int d2 = max_element(depth2.begin(), depth2.end()) - depth2.begin();

    debug(d1, d2);

    Dist dist1 = Dist(adj, d1, n);
    Dist dist2 = Dist(adj, d2, n);

    for(int i = 0; i < n-1; i++){
        if(edge_values[i] == 1){
            dist1.toggle(roads[i].first, roads[i].second);
            dist2.toggle(roads[i].first, roads[i].second);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int e;
        cin >> e;
        e--;
        dist1.toggle(roads[e].first, roads[e].second);
        dist2.toggle(roads[e].first, roads[e].second);

        cout << max(dist1.query(), dist2.query()) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}