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

const uint MOD = 1e9 + 7;
using mint = ModInt<MOD>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const mint C = rng();
// DON'T FORGET TO DELETE
const mint C = 1203724;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<mint> hsh(n+1);
    vi npow(n);
    int cur_pow = 0;
    mint cur = 0;
    hsh[0] = 0;
    for(int i = 0; i < n; i++){
        if(i+1 < n && s[i] == '1' && s[i+1] == '1'){
            hsh[i+1] = cur;
            hsh[i+2] = cur;
            npow[i] = npow[i+1] = cur_pow;
            i++;
            continue;
        }
        cur_pow++;
        cur += (s[i]-'0'+1) * C.pow(cur_pow);
        hsh[i+1] = cur;
        npow[i] = cur_pow;
    }
    debug(hsh);

    // leftmost/rightmost 1
    vi lb(n, -1), rb(n, -1);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') continue;
        if(s[i] == '1'){
            if(i && s[i-1] == '1') lb[i] = lb[i-1];
            else lb[i] = i;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0') continue;
        if(s[i] == '1'){
            if(i+1 < n && s[i+1] == '1') rb[i] = rb[i+1];
            else rb[i] = i;
        }
    }
    debug(lb, rb);

    auto get_hsh = [&](int l, int r) {
        int a = s[l] == '0' ? l : rb[l] + 1;
        int b = s[r-1] == '0' ? r : lb[r-1];
        if(a > b){
            return ((r - l) & 1) ? mint(2) : mint(0);
        }
        debug(a, b, npow[a]);
        mint tmp = (hsh[b] - hsh[a]) / C.pow(npow[a]);
        debug(tmp);
        if((r-b) & 1){
            int nxt = npow[b-1] - npow[a] + 1;
            debug(nxt);
            tmp += 2 * C.pow(nxt);
        }
        if((a-l) & 1){
            tmp *= C;
            tmp += 2;
        }
        return tmp;
    };

    // get_hsh(2, 6);

    int q;
    cin >> q;
    while(q--){
        int a, b, len;
        cin >> a >> b >> len;
        a--;b--;
        mint ha = get_hsh(a, a+len);
        mint hb = get_hsh(b, b+len);
        debug(ha, hb);
        if(ha == hb){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}