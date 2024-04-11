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


const int MAXN = 1e6 + 5;
int min_index[MAXN];
vi adj[MAXN];

void first_dfs(int u, int last){
    if(last != -1){
        min_index[u] = min(u, min_index[last]);
    }
    else{
        min_index[u] = u;
    }
    for(int v : adj[u]){
        if(v == last) continue;
        first_dfs(v, u);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int last = 0;
    int type, x;
    cin >> type >> x;
    int root = x % n;
    // vi black(n);
    // vi parent(n);
    // black[root] = 1;
    first_dfs(root, -1);
    q--;
    int global_min = root;
    while(q--){
        int type, z;
        cin >> type >> z;
        int idx = (z + last) % n;
        if(type == 1){
            // int cur = idx;
            // while(!vis[cur]){
            //     debug(cur);
            //     vis[cur] = 1;
            //     global_min = min(global_min, cur);
            //     cur = parent[cur];
            // }
            global_min = min(global_min, min_index[idx]);
        }
        else{ // type = 2
            int ans = min(global_min, min_index[idx]);
            cout << ans + 1 << '\n';
            last = ans + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}