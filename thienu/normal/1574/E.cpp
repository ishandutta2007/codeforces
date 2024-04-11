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

struct RowChecker{
    int n, m;
    vvi par;
    int bad = 0, forced = 0;
    RowChecker(int n, int m) : n(n), m(m){
        // n rows, m columns
        par = vvi(2, vi(n));
    }

    void erase(int x, int y, int v){
        int p = (y+v) & 1;
        par[p][x]--;
        if(par[p][x] == 0 && par[p^1][x] > 0) bad--;
        if(par[p][x] == 0 && par[p^1][x] == 0) forced--;
    }

    void upd(int x, int y, int v){
        int p = (y+v) & 1;
        par[p][x]++;
        if(par[p][x] == 1 && par[p^1][x] > 0) bad++;
        if(par[p][x] == 1 && par[p^1][x] == 0) forced++;
    }

    mint ways(){
        if(bad) return 0;
        return mint(2).pow(n-forced);
    }
};

struct AltChecker{
    int n, m;
    vi par;
    AltChecker(int n, int m) : n(n), m(m){
        // n rows, m columns
        par.resize(2);
    }

    void erase(int x, int y, int v){
        int p = (x+y+v) & 1;
        par[p]--;
    }

    void upd(int x, int y, int v){
        int p = (x+y+v) & 1;
        par[p]++;
    }

    mint ways(){
        if(par[0] && par[1]) return 0;
        if(par[0] || par[1]) return 1;
        return 2;
    }
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    RowChecker horiz(n, m);
    RowChecker vert(m, n);
    AltChecker alt(n, m);
    set<pii> zero, one;
    while(q--){
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        pii p = {x, y};
        if(t == -1){
            if(zero.find(p) != zero.end()){
                horiz.erase(x, y, 0);
                vert.erase(y, x, 0);
                alt.erase(x, y, 0);
                zero.erase(p);
            }else if(one.find(p) != one.end()){
                horiz.erase(x, y, 1);
                vert.erase(y, x, 1);
                alt.erase(x, y, 1);
                one.erase(p);
            }
        }else{
            if(zero.find(p) != zero.end()){
                horiz.erase(x, y, 0);
                vert.erase(y, x, 0);
                alt.erase(x, y, 0);
                zero.erase(p);
            }else if(one.find(p) != one.end()){
                horiz.erase(x, y, 1);
                vert.erase(y, x, 1);
                alt.erase(x, y, 1);
                one.erase(p);
            }
            horiz.upd(x, y, t);
            vert.upd(y, x, t);
            alt.upd(x, y, t);
            if(t == 0) zero.insert(p);
            else one.insert(p);
        }
        debug(horiz.ways(), vert.ways(), alt.ways());
        cout << horiz.ways() + vert.ways() - alt.ways() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}