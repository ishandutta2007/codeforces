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

void dfs(vvi &adj, vi &mini, vi &maxi, vll &ans_min, vll &ans_max, int u, int last){
    ll total_min = 0, total_max = 0;
    for(int v : adj[u]){
        if(v == last){
            continue;
        }
        dfs(adj, mini, maxi, ans_min, ans_max, v, u);
        total_min += max(abs(mini[u] - mini[v]) + ans_min[v], abs(mini[u] - maxi[v]) + ans_max[v]);
        total_max += max(abs(maxi[u] - mini[v]) + ans_min[v], abs(maxi[u] - maxi[v]) + ans_max[v]);
    }
    ans_max[u] = total_max;
    ans_min[u] = total_min;
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    
    vi mini(n), maxi(n);
    for(int i = 0; i < n; i++){
        cin >> mini[i] >> maxi[i];
    }
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vll ans_min(n), ans_max(n);
    dfs(adj, mini, maxi, ans_min, ans_max, 0, -1);
    cout << max(ans_min[0], ans_max[0]) << endl;
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