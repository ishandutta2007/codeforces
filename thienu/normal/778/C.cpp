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
    int from, to, val;
    Edge(int f, int t, int v) : from(f), to(t), val(v) {};
};

void dfs_depth(vi &sz, vi &dep, vvi &by_depth, vector<vector<Edge>> &adj, int u, int d){
    dep[u] = d;
    by_depth[d].push_back(u);
    int s = 1;
    for(Edge e : adj[u]){
        int v = e.to;
        dfs_depth(sz, dep, by_depth, adj, v, d+1);
        s += sz[v];
    }
    sz[u] = s;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<Edge>> adj(n);
    vvi adj_letter(n, vi(26, -1));
    for(int i = 0; i < n-1; i++){
        int a, b; char c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back(Edge(a, b, c-'a'));
        adj_letter[a][c-'a'] = b;
    }
    vi sz(n);
    vi dep(n);
    vvi by_depth(n);
    vi depth_pref(n);
    dfs_depth(sz, dep, by_depth, adj, 0, 0);
    depth_pref[0] = by_depth[0].size();
    for(int i = 1; i < n; i++){
        depth_pref[i] = depth_pref[i-1] + by_depth[i].size();
    }
    debug(depth_pref);
    int ans_depth = -1;
    int ans_size = 1e9 + 7;
    debug(sz);
    debug(dep);
    debug(by_depth);
    for(int d = 0; d < n; d++){
        int total = depth_pref[d];
        for(int u : by_depth[d]){
            int heavy_node = -1;
            int max_sz = -1;
            for(Edge e : adj[u]){
                if(sz[e.to] > max_sz){
                    max_sz = sz[e.to];
                    heavy_node = e.to;
                }
            }
            debug(u, heavy_node);
            if(heavy_node != -1) total += sz[heavy_node] - 1;
            map<int, int> m;
            queue<int> q;
            vi added_edges;
            int num_nodes = n;
            int added_nodes = 0;
            for(Edge e : adj[u]){
                int v = e.to;
                if(v == heavy_node) continue;
                m[v] = heavy_node;
                q.push(v);
                while(!q.empty()){
                    int w = q.front();
                    debug(w, m[w], adj_letter[m[w]]);
                    q.pop();
                    for(Edge e : adj[w]){
                        if(adj_letter[m[w]][e.val] != -1){
                            m[e.to] = adj_letter[m[w]][e.val];
                        }else{
                            m[e.to] = num_nodes;
                            adj.push_back({});
                            adj[m[w]].push_back(Edge(m[w], num_nodes, e.val));
                            adj_letter.push_back(vi(26, -1));
                            adj_letter[m[w]][e.val] = num_nodes;
                            num_nodes++;
                            if(m[w] < n) added_edges.push_back(m[w]);
                            added_nodes++;
                        }
                        q.push(e.to);
                    }
                }
            }
            debug(u, added_nodes);
            total += added_nodes;
            adj.resize(n);
            adj_letter.resize(n);
            for(int i : added_edges){
                Edge e = adj[i][adj[i].size() - 1];
                adj_letter[i][e.val] = -1;
                adj[i].pop_back();
            }
        }
        debug(d, total);
        if(total < ans_size){
            ans_depth = d;
            ans_size = total;
        }
    }
    cout << ans_size << endl << ans_depth+1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}