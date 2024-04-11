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

struct Edge{
    int u, v, c, idx;
    Edge(int u, int v, int c, int idx) : u(u), v(v), c(c), idx(idx) {}
};

using ve = vector<Edge>;
using vve = vector<ve>;

int n, m;

void dfs1(int u, vve &adj, vi &vis, vi &order){
    for(Edge e : adj[u]){
        if(vis[e.v]) continue;
        vis[e.v] = 1;
        dfs1(e.v, adj, vis, order);
    }
    order.push_back(u);
}

bool good(int thres, ve edges, vi &rev){
    ve extra;
    vve adj(n), radj(n);
    for(Edge e : edges){
        if(e.c <= thres){
            extra.push_back(e);
        }else{
            adj[e.u].push_back(e);
            radj[e.v].push_back(Edge(e.v, e.u, e.c, e.idx));
        }
    }
    debug(thres, extra.size());
    vi vis(n), order;
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        dfs1(i, adj, vis, order);
    }
    reverse(order.begin(), order.end());
    debug(order);

    fill(vis.begin(), vis.end(), 0);
    for(int i : order){
        vis[i] = 1;
        for(Edge e : radj[i]){
            debug(i, e.v);
            if(!vis[e.v]) return false;
        }
    }

    fill(rev.begin(), rev.end(), 0);

    vi val(n);
    for(int i = 0; i < n; i++){
        val[order[i]] = i;
    }
    for(Edge e : extra){
        if(val[e.u] > val[e.v]){
            rev[e.idx] = 1;
        }
    }

    return true;
}

void solve(){
    cin >> n >> m;
    ve edges;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        edges.push_back(Edge(u, v, c, i));
    }

    vi rev(m);
    // bool res = good(0, edges, rev);
    // debug(res);
    int ans = (1<<30)-1;
    for(int x = (1<<29);x;x>>=1){
        int cand = ans - x;
        bool res = good(cand, edges, rev);
        debug(cand, res);
        if(res){
            ans = cand;
        }
    }
    debug(ans, rev);
    vi tor;
    for(int i = 0; i < m; i++){
        if(rev[i]) tor.push_back(i);
    }
    cout << ans << ' ' << tor.size() << endl;
    for(int i : tor){
        cout << i+1 << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}