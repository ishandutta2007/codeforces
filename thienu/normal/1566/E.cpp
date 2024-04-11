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

void dfs(int u, int last, vvi &adj, vi &color, vi &leaf, vi &bud, int &ans, bool &nonbud_leaf){
    int num_odd = 0;
    int num_even = 0;
    int num_bad = 0;
    int num_leaf = 0;
    int deg = 0;
    bool isbud = true;
    for(int v : adj[u]){
        if(v == last) continue;
        dfs(v, u, adj, color, leaf, bud, ans, nonbud_leaf);
        if(leaf[v]) num_leaf++;
        if(color[v] == 0) num_even++;
        if(color[v] == 1) num_odd++;
        if(color[v] == 2) num_bad++;
        deg++;
        if(!leaf[v]) isbud = false;
    }
    if(!deg) leaf[u] = 1;
    else if(isbud && u != 0) bud[u] = 1;
    if(!bud[u] && !nonbud_leaf && num_leaf) nonbud_leaf = 1;
    if(num_bad) color[u] = 2;
    else if(num_odd) color[u] = 0;
    else color[u] = 1;
    if(u == 0) color[u] = 2;

    // if(color[u] == 2){
    //     ans += num_odd;
    //     if(bud[u]) ans--;
    // }
    ans += max(0, num_odd - 1);
}

void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vi color(n);
    int ans = 0;
    vi bud(n), leaf(n);
    bool nonbud_leaf = false;
    dfs(0, -1, adj, color, leaf, bud, ans, nonbud_leaf);
    debug(bud, nonbud_leaf, color);
    // if(!nonbud_leaf) ans++;
    ans++;
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