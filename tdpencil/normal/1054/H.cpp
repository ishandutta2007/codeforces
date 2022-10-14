
// I make this just for fun because i'm done
// Aimi Haraguni >> Konomi Suzuki >> Yui >>  Ikimono Gakari >> Garnidelia >> Kalafina >> Eir Aoi.   .. dude? 
// problems that involves any kind of persistent data structures are the best of the best, are not them?
 
#pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define all(v) (v).begin(), (v).end()
#define fill(x, v) memset(x, v, sizeof(x))
#define FER(i,a,b) for(int i=int(a); i< int(b); ++i)
#define IFR(i,a,b) for(int i=int(a); i>=int(b); --i )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
// #define N 6800000
// #define M 19
// #define mod3 9
 
// #define mod3  998244353
// #define mod 1000000007
// #define mod2 1000000009
// 998244353 
// #define mod1 998244353
#define mody 490019
#define bas 987625403
#define sqr(x) (x)*(x)  
#define INF 3000000000000000000
#define N1 1000
 
using namespace std;
using namespace __gnu_pbds;
 
typedef int ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<vi> vv;
typedef vector<ii> vii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> S_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}

/*
inline ll add(ll a, ll b, ll mod) { return a+b < mod? a+b : a+b-mod;}
inline ll rem(ll a, ll b, ll mod) { return a >= b? a - b: a- b + mod;}
inline ll mul(ll a, ll b, ll mod) { return (long long) a*b%mod;}
inline void Mul(ll &a, ll b, ll mod) { a = (long long) a*b%mod;}
inline ll bp(ll a, ll p, ll mod){
    // if(!a) return 1;
    ll ret;
    for(ret = 1; p; p>>=1, Mul(a, a, mod)) (p & 1) && (Mul(ret, a, mod), 1);
    return ret;
}
*/
static inline void read(ll &result) {
    bool minus = false;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' and ch <= '9') break;
        ch = getchar();
    }
    (ch == '-')? minus = true: result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' or ch > '9') break;
        result = (result<<3)+ (result<<1) + (ch - '0');
    }
    if(minus) result = -result;
}

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = {1}) {
    assert(n >= 0);
    T res = e;
    while (n) {
        if (n & 1) res = op(res, a);
        if (n >>= 1) a = op(a, a);
    }
    return res;
}
 
template <unsigned Mod = 1'000'000'007> 
struct Modular {
    using M = Modular;
    unsigned v;
    Modular(long long a = 0) : v((a %= (long long) Mod) < 0 ? a + Mod : a) {}
    M operator-() const { return M() -= *this; }
    M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
    M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
    M& operator*=(M r) { v = (long long)v * r.v % Mod; return *this; }
    M& operator/=(M r) { return *this *= power(r, Mod - 2); }
    M pow(uint64_t k) const{
        return power(*this, k);
    }
    M inv() const{ return pow(Mod-2);}
    friend M operator+(M l, M r) { return l += r; }
    friend M operator-(M l, M r) { return l -= r; }
    friend M operator*(M l, M r) { return l *= r; }
    friend M operator/(M l, M r) { return l /= r; }
    friend bool operator==(M l, M r) { return l.v == r.v; }
    friend bool operator!=(M l, M r) { return l.v != r.v; }
    bool operator < (const M & rhs) const {return v < rhs.v;}
    M sqrt() const{
        if(v == 0) return 0;
        if(Mod == 2) return 1;
        if(pow((Mod-1)>>1) == Mod -1) return 0;
        uint64_t Q = Mod - 1LL, m = 0, i;
        M zQ;
        while(!(Q&1)) Q>>=1, m++;
        for(int z = 1; ; z++) if(M(z).pow((Mod-1)>>1) == Mod -1){
            zQ = M(z).pow(Q);
            break;
        }
        M t = pow(Q), R = pow((Q+1)>>1), r;
        for( ; ; ){
            if(t == 1) {
                r = R;
                break;
            }
            for(i = 1; M(t).pow(1<<i) != 1; i++);
            M b = M(zQ).pow(1<<(m-1-i));
            m = i, zQ = b*b, t = t*zQ, R = R*b;
        }
        return min(r, Mod-r);
    }
    friend ostream& operator<<(ostream& os, M a) { return os << a.v; }
    friend istream& operator>>(istream& is, M &a) { int64_t w; is >> w; a = M(w); return is; }
};
 
 
using mint = Modular<200003>;
 
namespace ntt {
 
    template <unsigned Mod> void ntt(vector<Modular<Mod>>& a, bool inverse) {
        static vector<Modular<Mod>> dw(30), idw(30);
        if (dw[0] == 0) {
            Modular<Mod> root = 2;
            while (power(root, (Mod - 1) / 2) == 1) root += 1;
            for (int32_t i = 0; i < 30; ++i)
                dw[i] = -power(root, (Mod - 1) >> (i + 2)), idw[i] = 1 / dw[i];
        }
        int32_t n = a.size();
        assert((n & (n - 1)) == 0);
        if (not inverse) {
            for (int32_t m = n; m >>= 1; ) {
                Modular<Mod> w = 1;
                int32_t m2 = m << 1;
                for (int32_t s = 0, k = 0; s < n; s += m2) {
                    for (int32_t i = s, j = s + m; i < s + m; ++i, ++j) {
                        auto x = a[i], y = a[j] * w;
                        if (x.v >= Mod) x.v -= Mod;
                        a[i].v = x.v + y.v, a[j].v = x.v + (Mod - y.v);
                        //here a[i] is not normalised
                    }
                    w *= dw[__builtin_ctz(++k)];
                }
            }
        } 
        else {
            for (int32_t m = 1; m < n; m <<= 1) {
                Modular<Mod> w = 1;
                int32_t m2 = m << 1;
                for (int32_t s = 0, k = 0; s < n; s += m2) {
                    for (int32_t i = s, j = s + m; i < s + m; ++i, ++j) {
                        auto x = a[i], y = a[j];
                        a[i] = x + y, a[j].v = x.v + (Mod - y.v), a[j] *= w;
                    }
                    w *= idw[__builtin_ctz(++k)];
                }
            }
            auto inv = 1 / Modular<Mod>(n);
            for (auto&& e : a) e *= inv;
        }
    }
    template <unsigned Mod>
        vector<Modular<Mod>> operator*(vector<Modular<Mod>> l, vector<Modular<Mod>> r) {
            if (l.empty() or r.empty()) return {};
            int32_t n = l.size(), m = r.size(), sz = 1 << __lg(((n + m - 1) << 1) - 1);
            if (min(n, m) < 30) {
                vector<int64_t> res(n + m - 1);
                for (int32_t i = 0; i < n; ++i) for (int32_t j = 0; j < m; ++j)
                    res[i + j] += (l[i] * r[j]).v;
                return {begin(res), end(res)};
            }
            bool eq = l == r;
            l.resize(sz), ntt(l, false);
            if (eq) r = l;
            else r.resize(sz), ntt(r, false);
            for (int32_t i = 0; i < sz; ++i) l[i] *= r[i];
            ntt(l, true), l.resize(n + m - 1);
            return l;
        }
 
    //for 1e9+7 ntt
    constexpr unsigned mod = 490019;
    using Mint = Modular<mod>;
    /*
    167772161; //= 2^25 * 5 + 1
    469762049; //= 2^26 * 7 + 1
    754974721; //= 2^24 * 45 + 1
    1045430273; //= 2^20 * 997 + 1
    1051721729; //= 2^20 * 1003 + 1
    1053818881; //= 2^20 * 1005 + 1
    */
    vector<Mint> operator*(const vector<Mint>& l, const vector<Mint>& r) {
        if (l.empty() or r.empty()) return {};
        int n = l.size(), m = r.size();
        static constexpr uint64_t mod0 = 167772161, mod1 = 1300234241, mod2 = 1484783617;
        using Mint0 = Modular<mod0>;
        using Mint1 = Modular<mod1>;
        using Mint2 = Modular<mod2>;
        vector<Mint0> l0(n), r0(m);
        vector<Mint1> l1(n), r1(m);
        vector<Mint2> l2(n), r2(m);
        for (int i = 0; i < n; ++i) l0[i] = l[i].v, l1[i] = l[i].v, l2[i] = l[i].v;
        for (int j = 0; j < m; ++j) r0[j] = r[j].v, r1[j] = r[j].v, r2[j] = r[j].v;
        l0 = l0 * r0, l1 = l1 * r1, l2 = l2 * r2;
        vector<Mint> res(n + m - 1);
        static const Mint1 im0 = 1 / Mint1(mod0);
        static const Mint2 im1 = 1 / Mint2(mod1), im0m1 = im1 / mod0;
        static const Mint m0 = mod0, m0m1 = m0 * mod1;
        for (int i = 0; i < n + m - 1; ++i) {
            unsigned y0 = l0[i].v;
        	unsigned y1 = (im0 * (l1[i] - y0)).v;
            unsigned y2 = (im0m1 * (l2[i] - y0) - im1 * y1).v;
            res[i] = y0 + m0 * y1 + m0m1 * y2;
        }
        return res;
    }
 
}
 
using namespace ntt;
 
 
struct poly {
    vector<Mint> a;
    inline void normalize() {
        while((int)a.size() && a.back() == 0) a.pop_back();
    }
    template<class...Args> poly(Args...args): a(args...) { normalize(); }
    poly(const initializer_list<Mint> &x): a(x.begin(), x.end()) {normalize();}
    int size() const { return (int)a.size(); }
    inline Mint coef(const int i)const { return (i < a.size()) ? a[i]: Mint(0); }
    Mint operator[](const int i) { return coef(i); }
    bool is_zero() const {return a.empty();}
    poly operator + (const poly &x) const {
        int n = max(size(), x.size());
        vector<Mint> ans(n);
        for(int i = 0; i < n; i++) ans[i] = coef(i) + x.coef(i);
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator - (const poly &x) const {
        int n = max(size(), x.size());
        vector<Mint> ans(n);
        for(int i = 0; i < n; i++) ans[i] = coef(i) - x.coef(i);
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator * (const poly& b) const {
        if(is_zero() || b.is_zero()) return {};
        vector<Mint> A, B;
        for(auto xd: a) A.pb(xd);
        for(auto xd: b.a) B.pb(xd);
        auto ans = A * B;
        while ((int)ans.size() && ans.back() == 0) ans.pop_back();
        return ans;
    }
    poly operator * (const Mint& x) const {
        int n = size();
        vector<Mint> ans(n);
        for(int i = 0; i < n; i++) ans[i] = a[i] * x;
        return ans;
    }
    poly operator / (const Mint &x) const{ return (*this) * x.inv(); }
    poly& operator += (const poly &x) { return *this = (*this) + x; }
    poly& operator -= (const poly &x) { return *this = (*this) - x; }
    poly& operator *= (const poly &x) { return *this = (*this) * x; }
    poly& operator *= (const Mint &x) { return *this = (*this) * x; }
    poly& operator /= (const Mint &x) { return *this = (*this) / x; }
    poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; } //modulo by x^k
    poly mul_xk(int k) const { // multiply by x^k
        poly ans(*this);
        ans.a.insert(ans.a.begin(), k, 0);
        return ans;
    }
    poly mul_xk2(long long k, int n) const { // multiply by x^k mod x^n
        poly ans(*this);
        if(k >= 1LL*n){
            ans.a.clear();
            return ans;
        }
        int m = k;
        ans.a.insert(ans.a.begin(), m, 0);
        return ans.mod_xk(n);
        // return ans;
    }
    poly div_xk(int k) const { // divide by x^k
        return vector<Mint>(a.begin() + min(k, (int)a.size()), a.end());
    }
    poly substr(int l, int r) const { // return mod_xk(r).div_xk(l)
        l = min(l, size());
        r = min(r, size());
        return vector<Mint>(a.begin() + l, a.begin() + r);
    }
    poly reverse_it(int n, bool rev = 0) const { // reverses and leaves only n terms
        poly ans(*this);
        if(rev) { // if rev = 1 then tail goes to head
            ans.a.resize(max(n, (int)ans.a.size()));
        }
        reverse(ans.a.begin(), ans.a.end());
        return ans.mod_xk(n);
    }
    poly differantiate() const {
        int n = size(); vector<Mint> ans(n-1);
        for(int i = 1; i < size(); i++) ans[i - 1] = coef(i) * i;
        return ans;
    }
    poly integrate() const {
        int n = size(); vector<Mint> ans(n+1);
        for(int i = 0; i < size(); i++) ans[i + 1] = coef(i) / (i + 1);
        return ans;
    }
    poly inverse(int n) const {  // 1 / p(x) % x^n, O(nlogn)
        assert(!is_zero()); assert(a[0] != 0);
        poly ans{Mint(1) / a[0]};
        for(int i = 1; i < n; i *= 2) {
            ans = (ans * Mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
        }
        return ans.mod_xk(n);
    }
    pair<poly, poly> divmod_slow(const poly &b) const { // when divisor or quotient is small
        vector<Mint> A(a);
        vector<Mint> ans;
        while(A.size() >= b.a.size()) {
            ans.push_back(A.back() / b.a.back());
            if(ans.back() != Mint(0)) {
                for(size_t i = 0; i < b.a.size(); i++) {
                    A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
                }
            }
            A.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return {ans, A};
    }
    pair<poly, poly> divmod(const poly &b) const { // returns quotient and remainder of a mod b
        if(size() < b.size()) return {poly{0}, *this};
        int d = size() - b.size();
        if(min(d, b.size()) < 250) return divmod_slow(b);
        poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1)).mod_xk(d + 1).reverse_it(d + 1, 1);
        return {D, *this - (D * b)};
    }
    poly operator / (const poly &t) const {return divmod(t).first;}
    poly operator % (const poly &t) const {return divmod(t).second;}
    poly& operator /= (const poly &t) {return *this = divmod(t).first;}
    poly& operator %= (const poly &t) {return *this = divmod(t).second;}
    poly log(int n) const { //ln p(x) mod x^n
        assert(a[0] == 1);
        return (differantiate().mod_xk(n) * inverse(n)).integrate().mod_xk(n);
    }
    poly exp(int n) const { //e ^ p(x) mod x^n
        if(is_zero()) return {1};
        assert(a[0] == 0);
        poly ans({1});
        int i = 1;
        while(i < n) {
            poly C = ans.log(2 * i).div_xk(i) - substr(i, 2 * i);
            ans -= (ans * C).mod_xk(i).mul_xk(i);
            i *= 2;
        }
        return ans.mod_xk(n);
    }
    //better for small k k < 100000 || n > 100000
    poly pow(int k, int n) const { // p(x)^k mod x^n
        if(is_zero()) return *this;
        poly ans({1}), b = mod_xk(n);
        while(k) {
            if(k & 1) ans = (ans * b).mod_xk(n);
            b = (b * b).mod_xk(n);
            k >>= 1;
        }
        return ans;
    }
    int leading_xk() const { //minimum i such that C[i] > 0
        if(is_zero()) return 1000000000;
        int res = 0; 
        while(res < size() and a[res] == Mint(0)) res++;
        return res;
    }
    //better for k > 100000, n < 100000
    poly pow2(long long k, int n) const { // p(x)^k mod x^n
        if(is_zero()) return *this;
        int i = leading_xk();
        Mint j = a[i];
        poly t = div_xk(i) / j;
        return (t.log(n) * Mint(k)).exp(n).mul_xk2(1LL*i * k, n) * (j.pow(1LL*k));
    }
    poly root(int n, int k = 2) const { //kth root of p(x) mod x^n
        if(is_zero()) return *this;
        if (k == 1) return mod_xk(n);
        assert(a[0] == 1);
        poly q({1});
        for(int i = 1; i < n; i <<= 1){
            if(k == 2) q += mod_xk(2 * i) * q.inverse(2 * i);
            else q = q * Mint(k - 1) + mod_xk(2 * i) * q.inverse(2 * i).pow(k - 1, 2 * i);
            q = q.mod_xk(2 * i) / Mint(k);
        }
        return q.mod_xk(n);
    }
    poly mulx(Mint x) { //component-wise multiplication with x^k
        Mint cur = 1; poly ans(*this);
        for(int i = 0; i < size(); i++) ans.a[i] *= cur, cur *= x;
        return ans;
    }
    poly mulx_sq(Mint x) { //component-wise multiplication with x^{k^2}
        Mint cur = x, total = 1, xx = x * x; poly ans(*this);
        for(int i = 0; i < size(); i++) ans.a[i] *= total, total *= cur, cur *= xx;
        return ans;
    }
    vector<Mint> chirpz_even(Mint z, int n) { //P(1), P(z^2), P(z^4), ..., P(z^2(n-1))
        int m = size() - 1;
        if(is_zero()) return vector<Mint>(n, 0);
        vector<Mint> vv(m + n);
        Mint iz = z.inv(), zz = iz * iz, cur = iz, total = 1;
        for(int i = 0; i <= max(n - 1, m); i++) {
            if(i <= m) vv[m - i] = total;
            if(i < n) vv[m + i] = total;
            total *= cur; cur *= zz;
        }
        poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
        vector<Mint> ans(n);
        for(int i = 0; i < n; i++) ans[i] = w[i];
        return ans;
    }
    //O(nlogn)
    vector<Mint> chirpz(Mint z, int n) { //P(1), P(z), P(z^2), ..., P(z^(n-1))
        auto even = chirpz_even(z, (n + 1) / 2);
        auto odd = mulx(z).chirpz_even(z, n / 2);
        vector<Mint> ans(n);
        for(int i = 0; i < n / 2; i++) {
            ans[2 * i] = even[i];
            ans[2 * i + 1] = odd[i];
        }
        if(n % 2 == 1) ans[n - 1] = even.back();
        return ans;
    }
    poly shift_it(int m, vector<poly> &pw) {
        if (size() <= 1) return *this;
        while (m >= size()) m /= 2;
        poly q(a.begin() + m, a.end());
        return q.shift_it(m, pw) * pw[m] + mod_xk(m).shift_it(m, pw);
    };
    //n log(n)
    poly shift(Mint a) { //p(x + a)
        int n = size();
        if(n == 1){
            poly ans = {coef(0)};
            return ans;
        }
        vector<poly> pw(n);
        pw[0] = poly({1});
        pw[1] = poly({a, 1});
        int i = 2;
        for (; i < n; i *= 2) pw[i] = pw[i / 2] * pw[i / 2];
        return shift_it(i, pw);
    }
    Mint eval(Mint x) { // evaluates in single point x
        Mint ans(0);
        for(int i = size() - 1; i >= 0; i--) {
            ans *= x;
            ans += a[i];
        }
        return ans;
    }
    poly build(vector<poly> &ans, int v, int l, int r, vector<Mint> &vec) { //builds evaluation tree for (x-a1)(x-a2)...(x-an)
        if(l == r) return ans[v] = poly({-vec[l], 1});
        int mid = l + r >> 1;
        return ans[v] = build(ans, 2 * v, l, mid, vec) * build(ans, 2 * v + 1, mid + 1, r, vec);
    }
    vector<Mint> eval(vector<poly> &tree, int v, int l, int r, vector<Mint> &vec) { // auxiliary evaluation function
        if(l == r) return {eval(vec[l])};
        int mid = l + r >> 1;
        auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
        auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
        A.insert(A.end(), B.begin(), B.end());
        return A;
    }
    //O(nlog^2n)
    vector<Mint> eval(vector<Mint> x) {// evaluate polynomial in (x_0, ..., x_n-1)
        int n = x.size();
        if(is_zero()) return vector<Mint>(n, Mint(0));
        vector<poly> tree(4 * n);
        build(tree, 1, 0, n - 1, x);
        return eval(tree, 1, 0, n - 1, x);
    }
    poly interpolate(vector<poly> &tree, int v, int l, int r, int ly, int ry, vector<Mint> &y) { //auxiliary interpolation function
        if(l == r) return {y[ly] / a[0]};
        int mid = l + r >> 1;
        int midy = ly + ry >> 1;
        auto A = (*this % tree[2 * v]).interpolate(tree, 2 * v, l, mid, ly, midy, y);
        auto B = (*this % tree[2 * v + 1]).interpolate(tree, 2 * v + 1, mid + 1, r, midy + 1, ry, y);
        return A * tree[2 * v + 1] + B * tree[2 * v];
    }
    poly sqrt(int d = -1) const{
        if(d == -1) d = size();
        if(is_zero()) return {};
        if(coef(0) == Mint(0)){
            FER(i, 1, size()){
                if(coef(i) != Mint(0)){
                    if((i&1) or d - (i>>1) <= 0) return {};
                    return ((*this).div_xk(i)).sqrt(d - (i>>1)).mul_xk(i>>1);
                }
            }
            return {};
        }
        Mint s = coef(0).sqrt();
        if(s == Mint(0)) return {};
        poly y = *this/coef(0), res({Mint(1)});
        Mint i2 = Mint(1)/Mint(2);
        for(int i = 1; i < d; i<<=1){
            res = (res + y.mod_xk(i<<1)*res.inverse(i<<1))*i2;
        }
        auto ret = res.mod_xk(d)*s;
        ret.normalize();
        return ret;
    }
};
//O(nlog^2n)
poly interpolate(vector<Mint> x, vector<Mint> y) { //interpolates minimum polynomial from (xi, yi) pairs
    int n = x.size(); assert(n == (int)y.size());//assert(all x are distinct)
    vector<poly> tree(4 * n);
    poly tmp({1});
    return tmp.build(tree, 1, 0, n - 1, x).differantiate().interpolate(tree, 1, 0, n - 1, 0, n - 1, y);
}
//O(a.size() * b.size())
//if gcd.size() - 1 = number of common roots between a and b
poly gcd(poly a, poly b) {
    return b.is_zero()? a : gcd(b, a % b);
}
//Let ra_0, ..., ra_n be the roots of A and rb_0, ..., rb_m be the roots of B
//resultant = A(rb_0) * ... A(rb_m). It is 0 iif there is a common a root between A and B
//O(a.size() * b.size())
Mint resultant(poly a, poly b) { //computes resultant of a and b, assert(!a.is_zero())
    if(b.is_zero() || a.is_zero()) return 0;
    else if(b.size() == 1) return b.a.back().pow((int)a.size() - 1);
    else {
        int pw = (int)a.size() - 1;
        a %= b;
        pw -= (int)a.size() - 1;
        Mint mul = b.a.back().pow(pw) * Mint(((b.size() - 1) & (a.size() - 1) & 1) ? -1 : 1);
        Mint ans = resultant(b, a);
        return ans * mul;
    }
}

int main(){
    ll n, m, c; read(n), read(m), read(c);
    vi ar(n), br(m);
    FER(i, 0, n) read(ar[i]);
    FER(i, 0, m) read(br[i]);
    if(c == 1){
        poly a, b;
        for(auto xd: ar) a.a.pb(Mint(xd));
        for(auto xd: br) b.a.pb(Mint(xd));
        Mint ans = 0;
        auto ret = a * b;
        for(auto xd: ret.a) ans += xd;
        cout<<ans<<"\n";
        return 0;
    }
    // compress for i
    vector<Mint> a(mody, Mint(0)), b(mody, Mint(0));
    FER(i, 0, n) {
        long long j = i;
        long long id = (1LL*sqr(j))%(mody - 1);
        a[(int) id] += Mint(ar[i]);
    }
    FER(i, 0, m){
        long long j = i;
        long long id = (1LL*sqr(j)*j)%(mody - 1);
        b[(int)id] += Mint(br[i]);
    }
    poly base;
    for(auto xd: b) base.a.pb(xd);
    base.normalize();
    auto coef = base.chirpz(Mint(c), mody - 1);
    Mint ans = 0;
    FER(i, 0, mody - 1){
        ans += a[i]*coef[i];
    }
    printf("%d\n", ans.v);
    return 0;
}