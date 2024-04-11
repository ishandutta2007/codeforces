#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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

int diam(int v, int last, vector<int> &to_leaf, vector<int> &max_length, vector<vector<int>> &adj){
    int tl = 0;
    int tl2 = 0;
    int ans = 0;
    for(int u : adj[v]){
        if(u == last) continue;
        ans = max(ans, diam(u, v, to_leaf, max_length, adj));
        if(tl <= to_leaf[u] + 1){
            tl2 = tl;
            tl = to_leaf[u] + 1;
        }
        else if(tl2 < to_leaf[u] + 1){
            tl2 = to_leaf[u] + 1;
        }
    }
    to_leaf[v] = tl;
    max_length[v] = tl + tl2;
    // debug(v, tl, tl2);
    return max(ans, tl + tl2);
}

int dfs(int v, int last, int b, vector<vector<int>> &adj){
    if(v == b) return 0;
    for(int u : adj[v]){
        if(u == last) continue;
        int x = dfs(u, v, b, adj);
        if(x != -1) return x + 1;
    }
    return -1;
}

void solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--;b--;

    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int dist = dfs(a, -1, b, adj);
    debug(dist);
    if(dist <= da){
        cout << "Alice" << endl;
        return;
    }

    vector<int> to_leaf(n), max_length(n);
    int diameter = diam(0, -1, to_leaf, max_length, adj);
    debug(diameter);
    if(2 * da >= diameter || 2 * da >= db){
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}