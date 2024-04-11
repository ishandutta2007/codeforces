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

const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
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

void st_init(vi &st, vi &midx, int tl, int tr, int pos, vi &v){
    if(tl == tr){
        st[pos] = v[tl];
        midx[pos] = tl;
        return;
    }
    st_init(st, midx, tl, tl + (tr - tl) / 2, pos * 2, v);
    st_init(st, midx, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, v);
    st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
    if(st[pos * 2] < st[pos * 2 + 1]){
        st[pos] = st[pos * 2];
        midx[pos] = midx[pos * 2];
    }
    else{
        st[pos] = st[pos * 2 + 1];
        midx[pos] = midx[pos * 2 + 1];
    }
}

pii st_min(vi &st, vi &midx, int tl, int tr, int pos, int left, int right){
    if(tr < left || right < tl){
        return {MOD, -1};
    }
    if(left <= tl && tr <= right){
        return {st[pos], midx[pos]};
    }
    pii x = st_min(st, midx, tl, tl + (tr - tl) / 2, pos * 2, left, right);
    pii y = st_min(st, midx, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
    return min(x, y);
}

void dfs(vvi &adj, vi &traversal, vi &dt, vi &occ, vi &depth, int u, int last){
    occ[u] = traversal.size();
    traversal.push_back(u);
    if(last != -1) depth[u] = depth[last] + 1;
    dt.push_back(depth[u]);
    for(int v : adj[u]){
        if(v == last) continue;
        dfs(adj, traversal, dt, occ, depth, v, u);
        traversal.push_back(u);
        dt.push_back(depth[u]);
    }
}

void solve(){
    int n;
    cin >> n;

    int ninv = inv(n);

    // depth i before depth j
    vvll f(n+1, vll(n+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0){
                f[i][j] = 1;
            }
            else if(j == 0){
                f[i][j] = 0;
            }
            else{
                f[i][j] = mul(add(f[i-1][j], f[i][j-1]), inv(2));
            }
        }
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
    ll ans = 0;
    for(int s = 0; s < n; s++){
        vi traversal;
        vi depth(n);
        vi dt, occ(n);
        dfs(adj, traversal, dt, occ, depth, s, -1);
        // debug(parent, depth, s);
        int ts = traversal.size();
        vi st(4 * ts);
        vi midx(4 * ts);
        st_init(st, midx, 0, ts-1, 1, dt);
        debug(traversal);
        for(int t = 0; t < n; t++){
            for(int i = t+1; i < n; i++){
                debug(s, t, i);
                debug(occ[t], occ[i]);
                int a = min(occ[t], occ[i]);
                int b = max(occ[t], occ[i]);
                debug(a, b);
                debug(st_min(st, midx, 0, ts-1, 1, a, b));
                int lca = traversal[st_min(st, midx, 0, ts-1, 1, a, b).second];
                debug(lca);
                int id = depth[i];
                int td = depth[t];
                int lcad = depth[lca];
                // debug(s, t, i, id, td, lcad);
                // (td-lcad) / ((td-lcad) + (id-lcad))
                // ll prob = mul(td-lcad, inv(td+id-2*lcad));
                ll prob = f[id-lcad][td-lcad];
                // debug(prob);
                ans = add(ans, mul(prob, ninv));
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}