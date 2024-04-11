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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

bool dfs(int u, vvi &adj, vi &vis, set<int> &stk, vi &order){
    vis[u] = 1;
    stk.insert(u);
    for(int v : adj[u]){
        if(vis[v]){
            if(stk.find(v) != stk.end()){
                return false;
            }
            continue;
        }
        bool res = dfs(v, adj, vis, stk, order);
        if(!res) return false;
    }
    stk.erase(u);
    order.push_back(u);
    return true;
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int y;
            cin >> y;
            y--;
            adj[i].push_back(y);
        }
    }
    debug(adj);

    // check dag
    vi order, vis(n);
    set<int> stk;

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ok = dfs(i, adj, vis, stk, order);
        }
        if(!ok) break;
    }

    if(!ok){
        cout << -1 << endl;
        return;
    }

    debug(order);

    vi dp(n);
    int ans = 0;
    for(int u : order){
        int bst = 1;
        for(int v : adj[u]){
            bst = max(bst, (v < u) ? dp[v] : dp[v]+1);
        }
        dp[u] = bst;
        ans = max(ans, bst);
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