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


bool operator<(mint a, mint b){
    return a._v < b._v;
}

vi playout(int k, int s, int d, vi &places){
    if(k == 0) return {places[d]};
    int sl = ((1<<((1<<(k-1))-1))-1) & s;
    s >>= ((1<<(k-1))-1);
    int sr = ((1<<((1<<(k-1))-1))-1) & s;
    vi l = playout(k-1, sl, d+1, places);
    vi r = playout(k-1, sr, d+1, places);
    vi ans;
    s >>= ((1<<(k-1))-1);
    bool ok = s;
    for(int i : l){
        if(!ok && i == places[d+1]) ans.push_back(places[d]);
        else ans.push_back(i);
    }
    for(int i : r){
        if(ok && i == places[d+1]) ans.push_back(places[d]);
        else ans.push_back(i);
    }
    // debug(k, s, d, places, l, r, ok, ans, sl, sr);
    return ans;
}

mint hsh(vi &places, mint A, int start = 1){
    mint ans;
    for(int i = 0; i < places.size(); i++){
        ans += (start * A.pow(places[i]));
        start++;
    }
    return ans;
}

void answer(vi &l, vi &r){
    for(int i : l){
        cout << i << ' ';
    }
    for(int i : r){
        cout << i << ' ';
    }
    cout << endl;
}

void solve(){
    int k;
    mint A, h;
    cin >> k >> A >> h;
    debug(k, A, h);

    // if(k < 5){
    //     vi places = {1, 2, 3, 5, 9, 17};
    //     for(int i = 0; i < (1<<((1<<k)-1)); i++){
    //         vi x = playout(k, i, 0, places);
    //         if(hsh(x, A) == h){
    //             for(int i : x){
    //                 cout << i << ' ';
    //             }
    //             cout << endl;
    //             return;
    //         }
    //     }
    //     cout << -1 << endl;
    //     return;
    // }
    int limit = 1<<((1<<(k-1))-1);
    vi places_losers = {2, 3, 5, 9, 17};
    vi places_winners = {1, 3, 5, 9, 17};

    map<mint, vi> h1w, h1l, h2w, h2l;
    for(int i = 0; i < limit; i++){
        vi win = playout(k-1, i, 0, places_winners);
        vi lose = playout(k-1, i, 0, places_losers);
        h1w[hsh(win, A, 1)] = win;
        h2w[hsh(win, A, 1+(1<<(k-1)))] = win;
        h1l[hsh(lose, A, 1)] = lose;
        h2l[hsh(lose, A, 1+(1<<(k-1)))] = lose;
    }

    debug(h1w, h1l);
    debug(h2w, h2l);
    
    for(auto p : h1w){
        if(h2l.find(h-p.first) != h2l.end()){
            answer(p.second, h2l[h-p.first]);
            return;
        }
    }
    for(auto p : h1l){
        if(h2w.find(h-p.first) != h2w.end()){
            answer(p.second, h2w[h-p.first]);
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vi tmp = {1, 2, 3, 5, 9, 17};
    // vi x = {3,17,9,17,9,17,5,17,9,17,17,5,1,17,9,17,9,17,17,2,5,17,9,17,3,17,17,9,17,9,17,5};
    // debug(x);
    // debug(hsh(x, 100));

    solve();
    return 0;
}