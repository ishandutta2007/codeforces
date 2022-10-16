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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vi v(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            debug(i, j);
            if(j > i){
                v[i]++;
            }
        }
        if(v[i] == 0) ans++;
    }
    debug(v, ans);
    int q;
    cin >> q;
    debug(q);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x, y;
            cin >> x >> y;
            x--;y--;
            debug(x, y);
            if(x > y) swap(x, y);
            adj[x].insert(y);
            adj[y].insert(x);
            v[x]++;
            debug(x, v[x]);
            if(v[x] == 1) ans--;
        }else if(t == 2){
            int x, y;
            cin >> x >> y;
            x--;y--;
            debug(x, y);
            if(x > y) swap(x, y);
            adj[x].erase(y);
            adj[y].erase(x);
            v[x]--;
            debug(v[x]);
            if(v[x] == 0) ans++;
        }else{
            cout << ans << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}