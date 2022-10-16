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

void dfs1(vvi &adj, vi &centroid, vi &sz, int u, int last, int n){
    int max_sz = -1;
    int size = 1;
    for(int v : adj[u]){
        if(v == last) continue;
        dfs1(adj, centroid, sz, v, u, n);
        max_sz = max(max_sz, sz[v]);
        size += sz[v];
    }
    sz[u] = size;
    int par_sz = n - size;
    max_sz = max(max_sz, par_sz);
    if(max_sz <= n/2){
        centroid.push_back(u);
    }
}

void dfs2(vvi &adj, int u, int last, vector<tuple<int, int, int>> &ops, int c, int r, int &cur){
    for(int v : adj[u]){
        if(v == last) continue;
        dfs2(adj, v, u, ops, c, r, cur);
    }
    if(u != r){
        ops.push_back({c, cur, u});
        ops.push_back({u, last, r});
        cur = u;
    }else{
        ops.push_back({c, cur, r});
    }
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<tuple<int, int, int>> ops;
    vi centroid;
    vi sz(n);
    dfs1(adj, centroid, sz, 0, -1, n);
    debug(centroid);

    for(int c : centroid){
        for(int u : adj[c]){
            if(find(centroid.begin(), centroid.end(), u) != centroid.end()) continue;
            int x = u;
            dfs2(adj, u, c, ops, c, u, x);
        }
    }
    cout << ops.size() << endl;
    for(auto a : ops){
        cout << get<0>(a)+1 << ' ' << get<1>(a)+1 << ' ' << get<2>(a)+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}