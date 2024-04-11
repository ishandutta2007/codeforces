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


// prime mods only, adapted from ACL
using uint = unsigned int;
using ull = unsigned long long;

uint MOD; // initialise this!
struct ModIntA{
    uint _v;
    ModIntA() : _v(0) {}
    ModIntA(int val) {
        int x = val % (int) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModIntA(ll val){
        ll x = val % (ll) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModIntA(uint val) {
        _v = val % MOD;
    }
    ModIntA(ull val) {
        _v = (uint) (val % MOD);
    }
    uint val(){ return _v; }
    ModIntA& operator++(){
        _v++;
        if(_v == MOD) _v = 0;
        return *this;
    }
    ModIntA& operator--(){
        if(_v == 0) _v = MOD;
        _v--;
        return *this;
    }
    ModIntA operator++(int){
        ModIntA result = *this;
        ++*this;
        return result;
    }
    ModIntA& operator--(int){
        ModIntA result = *this;
        --*this;
        return result;
    }
    ModIntA& operator+=(const ModIntA& rhs){
        _v += rhs._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }
    ModIntA& operator-=(const ModIntA& rhs){
        _v -= rhs._v;
        if (_v >= MOD) _v += MOD;
        return *this;
    }
    ModIntA& operator*=(const ModIntA& rhs){
        ull z = _v;
        z *= rhs._v;
        _v = (uint)(z % MOD);
        return *this;
    }
    ModIntA& operator/=(const ModIntA& rhs){
        return *this = *this * rhs.inv();
    }
    ModIntA operator+() const { return *this; }
    ModIntA operator-() const { return ModIntA() - *this; }
    ModIntA pow(ll n) const {
        assert(0 <= n);
        ModIntA x = *this, r = 1;
        while(n){
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    ModIntA inv() const {
        assert(_v);
        return pow(MOD - 2);
    }
    friend ModIntA operator+(const ModIntA& lhs, const ModIntA& rhs) {
        return ModIntA(lhs) += rhs;
    }
    friend ModIntA operator-(const ModIntA& lhs, const ModIntA& rhs) {
        return ModIntA(lhs) -= rhs;
    }
    friend ModIntA operator*(const ModIntA& lhs, const ModIntA& rhs) {
        return ModIntA(lhs) *= rhs;
    }
    friend ModIntA operator/(const ModIntA& lhs, const ModIntA& rhs) {
        return ModIntA(lhs) /= rhs;
    }
    friend bool operator==(const ModIntA& lhs, const ModIntA& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const ModIntA& lhs, const ModIntA& rhs) {
        return lhs._v != rhs._v;
    }
};
ostream& operator<<(ostream &os, ModIntA x) { return os << x.val(); }
istream& operator>>(istream &is, ModIntA &x) { ll p; is >> p; x = ModIntA(p); return is; }

using mint = ModIntA;

using vm = vector<mint>;
using vvm = vector<vm>;

using cnum = mint;
const int N = 2e5 + 20;
cnum fact[N];
cnum inv_fact[N];
void precomp(){ // don't forget to call precomp()!
    fact[0] = mint(1);
    for(int i = 1; i < N; i++){
        fact[i] = fact[i-1] * i;
    }
    for(int i = 0; i < N; i++){
        inv_fact[i] = fact[i].inv();
    }
}

cnum ncr(ll n, ll r){
    assert(n >= 0);
    if(r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] * inv_fact[n-r];
}

void dfs(vvi &adj, vvi &child, vi &order, vi &vis, int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v]) continue;
        child[u].push_back(v);
        dfs(adj, child, order, vis, v);
    }
    order.push_back(u);
}

void solve(){
    int n;
    cin >> n >> MOD;
    precomp();
    vvi adj(n);
    for(int i = 0; i + 1 < n; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vvi child(n);
    vi order;
    vi vis(n);
    dfs(adj, child, order, vis, 0);
    debug(child, order);

    vvm p(n, vm(n));
    vvm d(n, vm(n, 1));
    vvm dp(n, vm(n));

    for(int u : order){
        for(int i = 1; i < n; i++){
            for(int v : child[u]){
                d[u][i] *= p[v][i];
            }
        }

        for(int i = 1; i < n; i++){
            dp[u][i] = d[u][i];
        }


        int m = child[u].size();
        vm vsum(m);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[u][i] += dp[child[u][j]][i] * vsum[j];
            }
            vm ppref(m+1), psuf(m+1);
            ppref[0] = 1;
            for(int j = 0; j < m; j++){
                ppref[j+1] = ppref[j] * p[child[u][j]][i];
            }
            psuf[m] = 1;
            for(int j = m-1; j >= 0; j--){
                psuf[j] = psuf[j+1] * p[child[u][j]][i];
            }
            for(int j = 0; j < m; j++){
                // assert(ppref[j] * psuf[j+1] == d[u][i] / p[child[u][j]][i]);
                vsum[j] += ppref[j] * psuf[j+1];
            }
        }

        for(int i = 1; i < n; i++){
            p[u][i] = p[u][i-1] + dp[u][i];
        }
    }

    debug(dp);
    debug(d);

    vm ans(n);
    for(int i = 1; i < n; i++){
        ans[i] = d[0][i];
        for(int j = 0; j < i; j++){
            ans[i] -= ncr(i, j) * ans[j];
        }
    }
    debug(ans);

    for(int i = 1; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}