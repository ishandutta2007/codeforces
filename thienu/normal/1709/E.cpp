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

int ans = 0;

void dfs(int u, int last, vvi &adj, vi &a, vi &vxor, vector<map<int, int>> &occ, vi &sz){
    sz[u] = 1;
    int heavy = -1;
    int heavy_sz = 0;
    for(int v : adj[u]){
        if(v == last) continue;
        vxor[v] = vxor[u] ^ a[v];
        dfs(v, u, adj, a, vxor, occ, sz);
        sz[u] += sz[v];
        if(sz[v] > heavy_sz){
            heavy_sz = sz[v];
            heavy = v;
        }
    }
    debug(u, heavy);
    if(heavy == -1){
        occ[u][vxor[u]] = 1;
        return;
    }
    swap(occ[u], occ[heavy]);
    debug(u, occ[u]);
    if(occ[u].find(a[u] ^ vxor[u]) != occ[u].end()){
        debug(u);
        occ[u].clear();
        ans++;
        return;
    }
    occ[u][vxor[u]]++;
    for(int v : adj[u]){
        if(v == last || v == heavy) continue;
        debug(u, v, occ[v], occ[u], a[u]);
        for(pii p : occ[v]){
            if(occ[u].find(a[u] ^ p.first) != occ[u].end()){
                debug(u);
                occ[u].clear();
                ans++;
                return;
            }
        }
        for(pii p : occ[v]){
            occ[u][p.first] += p.second;
        }
    }
    
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vvi adj(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi vxor(n);
    vector<map<int, int>> occ(n);
    vi sz(n);
    dfs(0, -1, adj, a, vxor, occ, sz);
    debug(vxor);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}