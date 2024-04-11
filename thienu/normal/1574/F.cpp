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

// prime mods only, source: ACL
using uint = unsigned int;
using ull = unsigned long long;
template <uint MOD>
struct ModInt{
    uint _v;
    ModInt() : _v(0) {}
    ModInt(int val) {
        int x = val % MOD;
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
};
template<uint M> ostream& operator<<(ostream &os, ModInt<M> x) { return os << x.val(); }
template<uint M> istream& operator>>(istream &is, ModInt<M> &x) { ll p; is >> p; x = ModInt<M>(p); return is; }

const uint MOD = 998244353;
using mint = ModInt<MOD>;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vvi words(n);
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            x--;
            words[i].push_back(x);
        }
    }
    vector<set<int>> adj(k);
    vector<set<int>> radj(k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j+1 < words[i].size(); j++){
            adj[words[i][j]].insert(words[i][j+1]);
            radj[words[i][j+1]].insert(words[i][j]);
        }
    }
    debug(adj, radj);
    vi bad(k);
    queue<int> q;
    for(int i = 0; i < k; i++){
        if(adj[i].size() > 1 || radj[i].size() > 1){
            bad[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(bad[v]) continue;
            bad[v] = 1;
            q.push(v);
        }
        for(int v : radj[u]){
            if(bad[v]) continue;
            bad[v] = 1;
            q.push(v);
        }
    }
    debug(bad);
    vi vis(k);
    vi chains;
    for(int i = 0; i < k; i++){
        if(vis[i] || bad[i] || !radj[i].empty()) continue;
        int len = 1;
        vis[i] = 1;
        int cur = i;
        while(!adj[cur].empty()){
            cur = *adj[cur].begin();
            vis[cur] = 1;
            len++;
        }
        chains.push_back(len);
    }
    debug(chains);
    map<int, int> sz;
    for(int i : chains) sz[i]++;
    debug(sz);

    vector<mint> dp(m+1);
    dp[0] = 1;
    for(int i = 1; i <= m; i++){
        for(pii p : sz){
            if(i-p.first < 0) continue;
            dp[i] += dp[i-p.first] * p.second;
        }
    }
    cout << dp[m] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}