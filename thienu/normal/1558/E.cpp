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

bool dfs(int u, int last, vvi &adj, vi &strength, vi &buff, vi &par, ll cur_pow, vi &vis, vi &done, bool nonvis){
    vis[u] = 1;
    if(!done[u]) nonvis = true;
    for(int v : adj[u]){
        if(v == last) continue;
        if(vis[v] && nonvis){
            // reconstruct
            int cur = u;
            while(cur != -1){
                done[cur] = 1;
                cur = par[cur];
            }
            return true;
        }else if(vis[v]) continue;

        // can enter?
        if(cur_pow <= (ll) strength[v]) continue;
        par[v] = u;
        bool res = dfs(v, u, adj, strength, buff, par, cur_pow + (!done[v]) * buff[v], vis, done, nonvis);
        if(res) return true;
    }
    return false;
}

bool check(int n, int m, vvi &adj, vi &strength, vi &buff, ll pow){
    vi done(n);
    done[0] = 1;

    while(true){
        bool fin = true;
        for(int i = 0; i < n; i++){
            if(done[i] == 0){
                fin = false;
                break;
            }
        }
        if(fin) return true;

        vi vis(n), par(n, -1);
        vis[0] = 1;
        ll cur_pow = pow;
        for(int i = 1; i < n; i++){
            if(done[i]) cur_pow += buff[i];
        }
        // debug(cur_pow);
        bool res = dfs(0, -1, adj, strength, buff, par, cur_pow, vis, done, false);
        // debug(res, done);
        if(res == false) return false;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    vi strength(n);
    for(int i = 1; i < n; i++) cin >> strength[i];
    vi buff(n);
    for(int i = 1; i < n; i++) cin >> buff[i];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // bool res = check(n, m, adj, strength, buff, 14);
    // debug(res);

    int ans = (1<<30)-1;
    for(int x = 1<<29; x; x>>=1){
        ll cand = ans-x;
        if(check(n, m, adj, strength, buff, cand)){
            ans = cand;
        }
    }
    cout << ans << endl;
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