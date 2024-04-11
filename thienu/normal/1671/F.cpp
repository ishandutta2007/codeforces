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

template <typename T>
struct Poly{
    vector<T> coeff;

    T & operator[] (int x) {
        return coeff[x];
    }

    Poly() { }

    Poly(int sz) { coeff.resize(sz); }
    Poly(unsigned int sz) { coeff.resize(sz); }
    Poly(ll sz) { coeff.resize(sz); }
    Poly(unsigned long long sz) { coeff.resize(sz); }

    template <typename R>
    Poly(vector<R> vec){
        coeff.resize(vec.size());
        for(int i = 0; i < vec.size(); i++){
            coeff[i] = T(vec[i]);
        }
    }

    template <typename R>
    Poly(Poly<R> poly){
        coeff.resize(poly.size());
        for(int i = 0; i < poly.size(); i++){
            coeff[i] = T(poly[i]);
        }
    }

    int size() const {
        return coeff.size();
    }

    void resize(int sz) {
        coeff.resize(sz);
    }

    Poly<T> to_size(int sz) const {
        Poly<T> res(*this);
        res.resize(sz);
        return res;
    }

    bool empty() const {
        return coeff.empty();
    }


    /* Trivial ops */
    
    Poly<T> operator+(Poly<T> other){
        Poly<T> res(max(size(), other.size()));
        for(int i = 0; i < res.size(); i++){
            res[i] = ((size() > i) ? coeff[i] : T(0)) + ((other.size() > i) ? other[i] : T(0));
        }
        return res;
    }

    void operator+=(const Poly<T> other){
        if(other.size() > size()){
            coeff.resize(other.size());
        }
        for(int i = 0; i < other.size(); i++){
            coeff += other[i];
        }
    }

    Poly<T> operator-(Poly<T> other){
        Poly<T> res(max(size(), other.size()));
        for(int i = 0; i < res.size(); i++){
            res[i] = ((size() > i) ? coeff[i] : T(0)) - ((other.size() > i) ? other[i] : T(0));
        }
        return res;
    }

    void operator-=(const Poly<T> other){
        if(other.size() > size()){
            coeff.resize(other.size());
        }
        for(int i = 0; i < other.size(); i++){
            coeff += other[i];
        }
    }
    
    Poly<T> operator*(const T scalar) const {
        Poly<T> res(size());
        for(int i = 0; i < size(); i++){
            res[i] = coeff[i] * scalar;
        }
        return res;
    }

    void operator*=(const T scalar){
        for(int i = 0; i < size(); i++){
            coeff[i] *= scalar;
        }
    }

    Poly<T> operator/(const T scalar) const {
        Poly<T> res(size());
        for(int i = 0; i < size(); i++){
            res[i] = coeff[i] / scalar;
        }
        return res;
    }

    void operator/=(const T scalar){
        for(int i = 0; i < size(); i++){
            coeff[i] /= scalar;
        }
    }

    // testing equality for zero: x == Poly<T>()
    bool operator==(Poly<T> other) {
        for(int i = 0; i < max(size(), other.size()); i++){
            if(((size() > i) ? coeff[i] : T(0)) != ((other.size() > i) ? other[i] : T(0))) return false;
        }
        return true;
    }

    bool operator!=(Poly<T> other) {
        return !(*this == other);
    }

    // Computes the polynomial evaluated at x.
    T operator()(T x){
        T res = T(0);
        for(int i = size() - 1; i >= 0; i--){
            res = res * x;
            res = res + coeff[i];
        }
        return res;
    }



    /* FFT ops */

    Poly<T> operator*(const Poly<T> other) const {
        return multiply(*this, other);
    }

    // F.inv(n) returns a polynomial R such that F * R = 1 (mod z^n).
    // This means all nonzero coefficients of exponents < n are zero under the field.
    // The length of the returned polynomial will be the smallest power of two >= n.
    // Explanation: https://codeforces.com/blog/entry/12513 (editorial for div1E)
    Poly<T> inv(int n) const {
        assert(coeff.size() > 0);
        assert(coeff[0] != T(0));
        Poly<T> res = Poly<T>(vector<T>{T(1) / coeff[0]});
        int m = 1;
        while(m < n){
            m <<= 1;
            res = (res * T(2)) - (res * res * (*this)).to_size(m);
        }
        return res;
    }

    // F.sqrt(n) returns a polynomial S such that S * S = 1 (mod z^n).
    // This means all nonzero coefficients of exponents < n are zero under the field.
    // The length of the returned polynomial will be at least n.
    // Explanation: https://codeforces.com/blog/entry/12513 (editorial for div1E)
    // If using mod-ints, please check that the square root exists before calling.
    Poly<T> sqrt(int n) const {
        int i;
        for(i = 0; i < coeff.size() && coeff[i] == 0; i++) {}
        if(i == coeff.size()) {
            return Poly<T>(n);
        }
        assert(i % 2 == 0); // if not, no solutions
        Poly<T> nz = Poly<T>(vector<T>(coeff.begin() + i, coeff.end()));
        Poly<T> res = Poly<T>(vector<T>{find_sqrt(nz[0])});
        int m = 1;
        while(m+i/2 < n){
            m <<= 1;
            res = (res + (res.inv(m) * nz).to_size(m)) / T(2);
        }
        debug(res, nz, m, i);
        vector<T> padded_coeff(m+i/2);
        copy(res.coeff.begin(), res.coeff.end(), padded_coeff.begin() + i/2);
        Poly<T> padded_res = Poly<T>(padded_coeff);
        return padded_res;
    }
    
    private:

    template<uint M>
    static ModInt<M> find_sqrt(ModInt<M> x){
        return x.sqrt();
    }
    
    static double find_sqrt(double x){
        return ::sqrt(x);
    }


    /* FFT corner */

    /* Multiplication pattern matching */
    template <uint _MOD>
    static Poly<ModInt<_MOD>> multiply(Poly<ModInt<_MOD>> a, Poly<ModInt<_MOD>> b){
        int root = primitive_root_constexpr(_MOD);
        if(root == -1){
            cerr << "[WARN] Arbitrary-constant-mod FFT is being implemented!" << endl;
            // TODO
        }else{
            return conv_ntt(a, b, ModInt<_MOD>(root));
        }
    }

    // See util/generate_primitive_root.cpp to generate more
    static constexpr int primitive_root_constexpr(uint m) {
        switch(m){
            case 2:          return 1;
            case 167772161:  return 3;
            case 469762049:  return 3;
            case 754974721:  return 11;
            case 998244353:  return 3;
            case 1004535809: return 3;
            case 1012924417: return 5;

            default:         return -1;
        }
    }
    
    /* For mods of FFT-able form */
    template <uint _MOD>
    static void ntt(vector<ModInt<_MOD>> &a, ModInt<_MOD> _root) {
        using _mint = ModInt<_MOD>;
        int n = a.size(), L = 31 - __builtin_clz(n);
        vector<_mint> rt(2, 1);
        for (int k = 2, s = 2; k < n; k *= 2, s++) {
            rt.resize(n);
            _mint z[] = {1, _root.pow(_MOD >> s)};
            for(int i = k; i < 2*k; i++) rt[i] = rt[i / 2] * z[i & 1];
        }
        vi rev(n);
        for(int i = 0; i < n; i++){
            rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
        }
        for(int i = 0; i < n; i++){
            if (i < rev[i]){
                swap(a[i], a[rev[i]]);
            }
        }
        for (int k = 1; k < n; k *= 2){
            for (int i = 0; i < n; i += 2 * k){
                for(int j = 0; j < k; j++) {
                    _mint z = rt[j + k] * a[i + j + k], &ai = a[i + j];
                    a[i + j + k] = ai - z;
                    ai += z;
                }
            }
        }
    }

    template <uint _MOD>
    static Poly<ModInt<_MOD>> conv_ntt(const Poly<ModInt<_MOD>> &a, const Poly<ModInt<_MOD>> &b, ModInt<_MOD> _root) {
        using _mint = ModInt<_MOD>;
        if (a.empty() || b.empty()) return Poly<_mint>();
        int s = a.size() + b.size() - 1, B = 32 - __builtin_clz(s), n = 1 << B;
        _mint inv = _mint(n).inv();
        vector<_mint> L(a.coeff), R(b.coeff), out(n);
        L.resize(n), R.resize(n);
        ntt(L, _root);
        ntt(R, _root);
        for(int i = 0; i < n; i++){
            out[-i & (n - 1)] = L[i] * R[i] * inv;
        }
        ntt(out, _root);
        return Poly<_mint>(vector<_mint>(out.begin(), out.begin() + s));
    }
};

template<typename T> ostream& operator<<(ostream &os, Poly<T> x) { return os << "<Poly " << x.coeff << ">"; }


// Adapted from kactl
template <typename T>
Poly<T> interpolate(vector<T> x, vector<T> y) {
    int n = x.size();
    assert(y.size() == n);
    vector<T> res(n), temp(n);
    for(int k = 0; k < n-1; k++){
        for(int i = k+1; i < n; i++){
            y[i] = (y[i] - y[k]) / (x[i] - x[k]);
        }
    }
    T last = 0; temp[0] = 1;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++) {
            res[i] += y[k] * temp[i];
            swap(last, temp[i]);
            temp[i] -= last * x[k];
        }
    }
    return res;
}

using P = Poly<mint>;

const int N = 100;
const int M = 50;

const int MAX = 11;

P poly[MAX+1][MAX+1];
vector<mint> init[MAX+1][MAX+1];

template <typename T>
using V = vector<T>;

void setup(){
    // dp[n][#invs][#adj invs][#pos of last num]
    V<V<V<V<mint>>>> dp(N+1, V<V<V<mint>>>(MAX+2, V<V<mint>>(MAX+2, V<mint>(N+1, 0))));
    dp[1][0][0][0] = 1;
    for(int i = 1; i < N-1; i++){
        for(int j = 0; j <= MAX; j++){
            for(int k = 0; k <= MAX; k++){
                for(int l = 0; l < i; l++){
                    for(int nxt = 0; nxt <= i; nxt++){
                        if(j + nxt < MAX + 2) dp[i+1][j + nxt][k + (nxt > l)][nxt] += dp[i][j][k][l];
                    }
                }
            }
        }
    }

    vector<mint> range(N-M);
    iota(range.begin(), range.end(), mint(M));
    
    for(int k = 0; k <= MAX; k++){
        for(int x = 0; x <= MAX; x++){
            vector<mint> v(M);
            for(int i = 0; i < M; i++){
                v[i] = accumulate(dp[i][k][x].begin(), dp[i][k][x].end(), mint(0));
            }
            init[k][x] = v;
            vector<mint> y;
            for(int i = M; i < N; i++){
                y.push_back(accumulate(dp[i][k][x].begin(), dp[i][k][x].end(), mint(0)));
            }
            poly[k][x] = interpolate(range, y);
        }
    }
}

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    if(n < M){
        cout << init[k][x][n] << endl;
    }else{
        cout << poly[k][x](n) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setup();
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}