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

vector<set<int>> adj;
vi fib;
vi depth;
vi parent;

const int NUM_FIB = 36;

void dfs(int v, int last, int &node, int fib_num){
    int cnt = 1;
    for(int u : adj[v]){
        if(last == u) continue;
        parent[u] = v;
        dfs(u, v, node, fib_num);
        if(node != -1) return;
        cnt += depth[u];
    }
    depth[v] = cnt;
    if(cnt == fib[fib_num - 1] || cnt == fib[fib_num - 2]){
        node = v;
    }
}

bool split(int root, int fib_num){
    if(fib_num == 0){
        return adj[root].empty();
    }
    if(fib_num == 1){
        return adj[root].size() == 1 && adj[*adj[root].begin()].size() == 1;
    }
    // set<int> vis;
    int node = -1;
    dfs(root, -1, node, fib_num);
    int u = node;
    if(u == -1) return false;
    if(depth[u] == fib[fib_num - 1]){
        adj[u].erase(parent[u]);
        adj[parent[u]].erase(u);
        bool x = split(root, fib_num - 2);
        bool y = split(u, fib_num - 1);
        return x && y;
    }
    else if(depth[u] == fib[fib_num - 2]){
        adj[u].erase(parent[u]);
        adj[parent[u]].erase(u);
        bool x = split(root, fib_num - 1);
        bool y = split(u, fib_num - 2);
        return x && y;
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    depth.resize(n);
    parent.resize(n);
    fib.resize(NUM_FIB);
    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i < NUM_FIB; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    debug(fib);
    
    if(find(fib.begin(), fib.end(), n) == fib.end()){
        cout << "NO" << endl;
        return;
    }
    int x = distance(fib.begin(), lower_bound(fib.begin(), fib.end(), n));
    debug(x);
    bool res = split(0, x);
    if(res){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}