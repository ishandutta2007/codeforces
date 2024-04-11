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

bool bipartite;

void dfs(vvi &adj, vi &color, int u){
    for(int v : adj[u]){
        if(color[v] == -1){
            color[v] = !color[u];
            dfs(adj, color, v);
        }
        else{
            if(color[v] == color[u]){
                bipartite = false;
            }
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] += x;
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] -= x;
    }
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if(sum & 1){
        cout << "NO" << endl;
        return;
    }
    vi color(n, -1);
    vi vis(n);
    bipartite = true;
    color[0] = 0;
    dfs(adj, color, 0);
    debug(bipartite, color);
    if(bipartite){
        vll s(2);
        for(int i = 0; i < n; i++){
            s[color[i]] += a[i];
        }
        cout << (s[0] == s[1] ? "YES" : "NO") << endl;
    }else{
        cout << "YES" << endl;
    }
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