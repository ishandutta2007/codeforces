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
template <uint MOD>
struct ModInt{
    uint _v;
    ModInt() : _v(0) {}
    ModInt(int val) {
        int x = val % (int) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(ll val){
        ll x = val % (ll) MOD;
        if(x < 0) x += MOD;
        _v = (uint) x;
    }
    ModInt(uint val) {
        _v = val % MOD;
    }
    ModInt(ull val) {
        _v = (uint) (val % MOD);
    }
    uint val(){ return _v; }
    ModInt& operator++(){
        _v++;
        if(_v == MOD) _v = 0;
        return *this;
    }
    ModInt& operator--(){
        if(_v == 0) _v = MOD;
        _v--;
        return *this;
    }
    ModInt operator++(int){
        ModInt result = *this;
        ++*this;
        return result;
    }
    ModInt& operator--(int){
        ModInt result = *this;
        --*this;
        return result;
    }
    ModInt& operator+=(const ModInt& rhs){
        _v += rhs._v;
        if (_v >= MOD) _v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs){
        _v -= rhs._v;
        if (_v >= MOD) _v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs){
        ull z = _v;
        z *= rhs._v;
        _v = (uint)(z % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs){
        return *this = *this * rhs.inv();
    }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return ModInt() - *this; }
    ModInt pow(ll n) const {
        assert(0 <= n);
        ModInt x = *this, r = 1;
        while(n){
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    ModInt inv() const {
        assert(_v);
        return pow(MOD - 2);
    }
    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
    }
    friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
    }
    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
    }
    friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
    }
    friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
        return lhs._v != rhs._v;
    }

    bool sqrt_exists() const;
    ModInt sqrt() const;
};
template<uint M> ostream& operator<<(ostream &os, ModInt<M> x) { return os << x.val(); }
template<uint M> istream& operator>>(istream &is, ModInt<M> &x) { ll p; is >> p; x = ModInt<M>(p); return is; }


const uint MOD = 1000000007;
using mint = ModInt<MOD>;

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

vvi adj;
vi sz;
vector<mint> trees;
vector<mint> ncrsum;
mint ans = 0;
int n, k;

map<pii, mint> mtrees;
map<pii, int> msz;

void upd(int u, int par){
    if(mtrees.find({u, par}) != mtrees.end()){
        trees[u] = mtrees[{u, par}];
        sz[u] = msz[{u, par}];
        ans += trees[u] * sz[u];
        return;
    }
    mint tsum = 0;
    sz[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        tsum += ncr(sz[v], k);
        sz[u] += sz[v];
    }
    mint total = ncr(sz[u], k);

    trees[u] = total - tsum;
    ans += trees[u] * sz[u];

    mtrees[{u, par}] = trees[u];
    msz[{u, par}] = sz[u];
}

void dfs1(int u, int par){

    for(int v : adj[u]){
        if(v == par) continue;
        dfs1(v, u);
    }
    
    upd(u, par);

    
    for(int v : adj[u]){
        if(v == par) continue;
        ncrsum[u] += ncr(sz[v], k);
    }
    ncrsum[u] += ncr(n - sz[u], k);

}

mint total_ans = 0;

// a -> b, with edge from a to b
void reroot(int a, int b){
    // upd(a, b);
    // but optimized?
    ans -= trees[a] * sz[a];
    sz[a] -= sz[b];
    trees[a] = ncr(sz[a], k) - ncrsum[a] + ncr(sz[b], k);
    ans += trees[a] * sz[a];

    ans -= trees[b] * sz[b];
    upd(b, -1);
}

void dfs2(int u, int par){
    total_ans += ans;
    for(int v : adj[u]){
        if(v == par) continue;
        // mint old_ans = ans;
        // mint treesu = trees[u];
        // mint treesv = trees[v];
        // int szu = sz[u];
        // int szv = sz[v];
        reroot(u, v);
        dfs2(v, u);
        // rollback
        reroot(v, u);
        // debug(ans, old_ans, trees[u], treesu, trees[v], treesv);
        // ans = old_ans;
        // trees[u] = treesu;
        // trees[v] = treesv;
        // sz[u] = szu;
        // sz[v] = szv;
    }
}

void solve(){
    cin >> n >> k;

    adj.resize(n);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    sz.resize(n);
    trees.resize(n);
    ncrsum.resize(n);

    // root = 0
    dfs1(0, -1);

    debug(ans, trees);

    dfs2(0, -1);

    cout << total_ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}