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

const int B = 60;

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
ll inv(ll x){
    return binexp(x, MOD - 2);
}
ll HALF;

struct Edge{
    ll to, w;
    Edge(int _to, ll _w) : to(_to), w(_w) {}
};
void __print(Edge e) {cerr << '{' << e.to << ',' << e.w << '}';}

using ve = vector<Edge>;
using vve = vector<ve>;

void dfs(int u, int last, vve &adj, vve &dfs_adj, vll &cycles, vll &pxor, vi &dfs_vis, vi &bitcnt, int &sz){
    sz++;
    for(int b = 0; b < B; b++){
        if((pxor[u] >> b) & 1){
            bitcnt[b]++;
        }
    }
    for(Edge e : adj[u]){
        if(e.to == last) continue;
        if(dfs_vis[e.to]){
            debug(u, e.to);
            cycles.push_back(pxor[u] ^ pxor[e.to] ^ e.w);
            continue;
        }
        dfs_vis[e.to] = 1;
        pxor[e.to] = pxor[u] ^ e.w;
        dfs_adj[e.to].push_back(Edge(u, e.w));
        dfs_adj[u].push_back(Edge(e.to, e.w));
        dfs(e.to, u, adj, dfs_adj, cycles, pxor, dfs_vis, bitcnt, sz);
    }
}

int log2(ll x){
    assert(x > 0);
    return 8 * sizeof(ll) - __builtin_clzll(x) - 1;
}

ll nc2(ll n){
    return mul(mul(n, n-1), HALF);
}

void solve(){
    HALF = inv(2);
    int n, m;
    cin >> n >> m;
    vve adj(n);
    for(int i = 0; i < m; i++){
        int x, y; ll w;
        cin >> x >> y >> w;
        x--;y--;
        adj[x].push_back(Edge(y, w));
        adj[y].push_back(Edge(x, w));
    }
    debug(adj);
    vve dfs_adj(n);
    vll pxor(n);
    vi vis(n);
    ll ans = 0;
    for(int root = 0; root < n; root++){
        if(vis[root]) continue;
        vis[root] = 1;
        debug(root);
        vll cycles;
        vi bitcnt(B);
        int sz = 0;
        dfs(root, -1, adj, dfs_adj, cycles, pxor, vis, bitcnt, sz);
        debug(cycles);

        // find basis
        vll basis;
        for(int i = 0; i < cycles.size(); i++){
            ll cand = cycles[i];
            if(cand == 0) continue;
            auto it = basis.begin();
            bool ok = false;
            while(cand != 0 && it != basis.end()){
                debug(*it, log2(cand), log2(*it));
                if(log2(cand) > log2(*it)){
                    basis.insert(it, cand);
                    ok = true;
                    break;
                }else if(log2(cand) == log2(*it)){
                    cand ^= *it;
                }
                it++;
            }
            debug(cand);
            if(ok || cand == 0) continue;
            basis.push_back(cand);
        }
        debug(basis);
        ll bor = 0;
        for(ll i : basis){
            bor |= i;
        }
        debug(bitcnt, sz);
        for(int b = 0; b < B; b++){
            if((bor >> b) & 1){
                ans = add(ans, mul(mul(nc2(sz), binexp(2, basis.size() - 1)), normalize(1LL<<b)));
            }else{
                ans = add(ans, mul(mul(mul(bitcnt[b], sz-bitcnt[b]), binexp(2, basis.size())), normalize(1LL<<b)));
            }
        }
    }
    debug(pxor);
    debug(dfs_adj);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}