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

// Source: kactl
// Might have zero solutions, be careful! (Check with sqrt_exists())
// If x is a square root, -x is also a square root
template <uint MOD>
bool ModInt<MOD>::sqrt_exists() const {
    return _v == 0 || pow((MOD-1)/2) == ModInt(1);
}

template <uint MOD>
ModInt<MOD> ModInt<MOD>::sqrt() const{
    if(_v == 0) return ModInt(0);
    assert(sqrt_exists()); // else no solution
    if (MOD % 4 == 3) return pow((MOD+1)/4);
    // a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5
    ll s = MOD - 1; ModInt n = 2;
    int r = 0, m;
    while (s % 2 == 0)
        ++r, s /= 2;
    /// find a non-square mod p
    while (n.pow((MOD - 1) / 2) != ModInt(-1)) ++n;
    ModInt x = pow((s + 1) / 2);
    ModInt b = pow(s), g = n.pow(s);
    for (;; r = m) {
        ModInt t = b;
        for (m = 0; m < r && t != ModInt(1); ++m)
            t = t * t;
        if (m == 0) return x;
        ModInt gs = g.pow(1LL << (r - m - 1));
        g = gs * gs;
        x = x * gs;
        b = b * g;
    }
}

const uint MOD = 1000000007;
using mint = ModInt<MOD>;


using cnum = mint;
const int N = 5e5 + 20;
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

cnum ncr_crude(ll n, ll r){
    cnum ans = 1;
    for(int i = 0; i < r; i++){
        ans = ans * cnum(i+1).inv();
        ans = ans * n-i;
    }
    return ans;
}


void solve(){
    int n;
    cin >> n;
    mint ans = 0;
    for(int i = 0; i <= n; i++){
        int j;
        cin >> j;
        ans += ncr(i + j, i + 1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    solve();
    return 0;
}