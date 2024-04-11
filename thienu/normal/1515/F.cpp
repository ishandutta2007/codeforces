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
    int to;
    int idx;
    Edge(int _to, int _idx){
        to = _to;
        idx = _idx;
    }

    Edge(){
        to = -1;
        idx = -1;
    }
};


vector<vector<Edge>> adj;

void dfs(int u, vi &vis, vi &ans, stack<int> &end, vll &a, ll x){
    vis[u] = 1;
    for(Edge e : adj[u]){
        if(vis[e.to]) continue;
        dfs(e.to, vis, ans, end, a, x);
        if(a[e.to] >= x){
            // merge
            ans.push_back(e.idx);
            a[u] += a[e.to] - x;
            a[e.to] = 0;
        }
        else{
            end.push(e.idx);
        }
    }
}

void solve(){
    int n, m;
    ll x;
    cin >> n >> m >> x;
    vll a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    adj.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(Edge(v, i));
        adj[v].push_back(Edge(u, i));
    }

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    if(sum < (ll) (n-1) * x){
        cout << "NO" << endl;
        return;
    }

    vi ans;
    stack<int> end;
    vi vis(n);

    dfs(0, vis, ans, end, a, x);

    while(!end.empty()){
        ans.push_back(end.top());
        end.pop();
    }
    cout << "YES" << endl;
    for(int i : ans){
        cout << i+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}