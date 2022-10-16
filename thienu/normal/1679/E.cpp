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

const uint MOD = 998244353;
using mint = ModInt<MOD>;

int B = 17;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi cnt(n+1);
    for(int i = 0; i < n; i++){
        cnt[i+1] = cnt[i] + (s[i] == '?');
    }

    vector<vector<mint>> reqs(B+1, vector<mint>(1<<B));
    for(int x = 1; x <= B; x++){
        vector<vector<mint>> dp(n+1, vector<mint>(n+1, 1));
        vector<vector<int>> mask(n+1, vector<int>(n+1, 0));
        for(int len = 1; len <= n; len++){
            for(int l = 0; l+len <= n; l++){
                int r = l+len;
                int msk; mint ways;
                if(len == 1){
                    if(s[l] == '?'){
                        msk = 0;
                        ways = x;
                    }else{
                        msk = 0;
                        ways = 1;
                    }
                }else{
                    if(s[l] == s[r-1] && s[l] == '?'){
                        msk = mask[l+1][r-1];
                        ways = dp[l+1][r-1] * x;
                    }else if(s[l] == '?'){
                        msk = mask[l+1][r-1] | (1 << (s[r-1]-'a'));
                        ways = dp[l+1][r-1];
                    }else if(s[r-1] == '?'){
                        msk = mask[l+1][r-1] | (1 << (s[l]-'a'));
                        ways = dp[l+1][r-1];
                    }else if(s[l] == s[r-1]){
                        msk = mask[l+1][r-1];
                        ways = dp[l+1][r-1];
                    }else{
                        msk = mask[l+1][r-1];
                        ways = 0;
                    }
                }
                // debug(x, l, r, ways, msk, ways * mint(x).pow(cnt[n] - cnt[r] + cnt[l]));
                reqs[x][msk] += ways * mint(x).pow(cnt[n] - cnt[r] + cnt[l]);
                dp[l][r] = ways;
                mask[l][r] = msk;
            }
        }
        // debug(x, reqs[x]);
        // sos
        for(int b = 0; b < B; b++){
            for(int i = 0; i < (1 << B); i++){
                if((i >> b) & 1){
                    reqs[x][i] += reqs[x][i ^ (1 << b)];
                }
            }
        }
    }
    // debug(reqs);

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int msk = 0;
        for(char c : s){
            msk |= (1 << (c-'a'));
        }
        int x = __builtin_popcount(msk);
        cout << reqs[x][msk] << endl;
    }

    // TODO: submit after systests
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}