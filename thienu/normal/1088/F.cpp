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

void dfs1(vvi &adj, vi &parent, int u, int last){
    for(int v : adj[u]){
        if(v == last) continue;
        dfs1(adj, parent, v, u);
        parent[v] = u;
    }
}

const int L = 20;
const ll INF = (ll) 2e18 + 69;

void solve(){
    int n;
    cin >> n;
    vpii weight(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        weight[i] = {x, i};
    }
    sort(weight.begin(), weight.end());
    vi lookup(n), w(n);
    for(int i = 0; i < n; i++){
        w[i] = weight[i].first;
        lookup[weight[i].second] = i;
    }
    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        x = lookup[x], y = lookup[y];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    debug(lookup, adj);
    vi parent(n);
    dfs1(adj, parent, 0, -1);
    debug(parent);
    vvi lift(L, vi(n));
    for(int i = 0; i < n; i++){
        lift[0][i] = parent[i];
    }
    for(int i = 1; i < L; i++){
        for(int j = 0; j < n; j++){
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    debug(lift);
    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll best = INF;
        for(int j = 0; j < L; j++){
            // if(lift[j][i] == -1) continue;
            ll cand = (ll)(1+j) * w[lift[j][i]];
            best = min(best, cand);
        }
        ans += best;
        ans += w[i];
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}