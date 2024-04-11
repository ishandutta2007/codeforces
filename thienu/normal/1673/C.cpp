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

const uint MOD = 1e9 + 7;
using mint = ModInt<MOD>;
const int MAX = 40000;

bool is_palindrome(int x){
    vi v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    vi w = v;
    reverse(w.begin(), w.end());
    return v == w;
}

void solve(){
    vi palindromes;
    for(int i = 1; i <= MAX; i++){
        if(is_palindrome(i)){
            palindromes.push_back(i);
        }
    }
    int num_palindromes;
    num_palindromes = palindromes.size();

    vector<vector<mint>> dp(MAX+1, vector<mint>(num_palindromes + 1));
    dp[0][0] = 1;
    for(int j = 1; j <= num_palindromes; j++){
        for(int i = 0; i <= MAX; i++){
            dp[i][j] = dp[i][j-1] + (i >= palindromes[j-1] ? dp[i-palindromes[j-1]][j] : 0);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][num_palindromes] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}