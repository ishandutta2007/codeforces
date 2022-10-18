#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

template<typename T>
struct Z_p{
    using Type = typename decay<decltype(T::value)>::type;
    static vector<Type> MOD_INV;
    constexpr Z_p(): value(){ }
    template<typename U> Z_p(const U &x){ value = normalize(x); }
    template<typename U> static Type normalize(const U &x){
        Type v;
        if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if(v < 0) v += mod();
        return v;
    }
    const Type& operator()() const{ return value; }
    template<typename U> explicit operator U() const{ return static_cast<U>(value); }
    constexpr static Type mod(){ return T::value; }
    Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
    Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
    template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
    template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
    Z_p &operator++(){ return *this += 1; }
    Z_p &operator--(){ return *this -= 1; }
    Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
    Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
    Z_p operator-() const{ return Z_p(-value); }
    template<typename U = T>
    typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
        #ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
        #else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        #endif
        return *this;
    }
    template<typename U = T>
    typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template<typename U = T>
    typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
        value = normalize(value * rhs.value);
        return *this;
    }
    template<typename U>
    Z_p &operator^=(U e){
        if(e < 0) *this = 1 / *this, e = -e;
        Z_p res = 1;
        for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
        return *this = res;
    }
    template<typename U>
    Z_p operator^(U e) const{
        return Z_p(*this) ^= e;
    }
    Z_p &operator/=(const Z_p &otr){
        Type a = otr.value, m = mod(), u = 0, v = 1;
        if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
        while(a){
            Type t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        assert(m == 1);
        return *this *= u;
    }
    template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
    Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
    typename common_type<typename Z_p<T>::Type, int64_t>::type x;
    in >> x;
    number.value = Z_p<T>::normalize(x);
    return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }
/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/
constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;
template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(int SZ){
    auto &inv = Z_p<T>::MOD_INV;
    if(inv.empty()) inv.assign(2, 1);
    for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}
template<typename T>
vector<T> precalc_power(T base, int SZ){
    vector<T> res(SZ + 1, 1);
    for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
    return res;
}

template<class T, char Conv = '^'>
void fast_walsh_hadamard_transform(vector<T> &a, const bool invert = false){
    int n = (int)a.size();
    for(auto len = 1; len < n; len <<= 1){
        for(auto i = 0; i < n; i += len << 1){
            for(auto j = 0; j < len; ++ j){
                T u = a[i + j], v = a[i + j + len];
                if(Conv == '^') a[i + j] = u + v, a[i + j + len] = u - v;
                if(Conv == '|') a[i + j + len] += invert ? -u : u;
                if(Conv == '&') a[i + j] += invert ? -v : v;
            }
        }
    }
    if(Conv == '^' && invert){
        T inv_n = T(1) / n;
        for(auto &x: a) x *= inv_n;
    }
}
template<class T, char Conv = '^'>
vector<T> convolute(vector<T> p, vector<T> q){
    int n = max({(int)p.size(), (int)q.size() - 1, 1});
    if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
    p.resize(n), q.resize(n);
    fast_walsh_hadamard_transform<T, Conv>(p), fast_walsh_hadamard_transform<T, Conv>(q);
    for(auto i = 0; i < n; ++ i) p[i] *= q[i];
    fast_walsh_hadamard_transform<T, Conv>(p, true);
    return p;
}
template<class T>
vector<T> subset_convolute(vector<T> p, vector<T> q){
    int n = max({(int)p.size(), (int)q.size() - 1, 1});
    if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
    int w = __lg(n);
    p.resize(n), q.resize(n);
    vector <vector <Zp>> a(w + 1, vector<Zp>(n)), b(a);
    for(auto i = 0; i < n; ++ i) a[__builtin_popcount(i)][i] = p[i];
    for(auto i = 0; i < n; ++ i) b[__builtin_popcount(i)][i] = q[i];
    for(auto bit = 0; bit <= w; ++ bit) fast_walsh_hadamard_transform<Zp, '|'>(a[bit]), fast_walsh_hadamard_transform<Zp, '|'>(b[bit]);
    vector<T> r(n);
    for(auto bit = 0; bit <= w; ++ bit){
        vector<T> c(n);
        for(auto lbit = 0; lbit <= bit; ++ lbit) for(auto i = 0; i < n; ++ i) c[i] += a[lbit][i] * b[bit - lbit][i];
        fast_walsh_hadamard_transform<T, '|'>(c, true);
        for(auto i = 0; i < n; ++ i) if(__builtin_popcount(i) == bit) r[i] = c[i];
    }
    return r;
}

template<class T>
void fast_zeta_transform(vector<T> &a){
    int n = max((int)a.size(), 1);
    if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
    int w = __lg(n);
    a.resize(n);
    for(auto bit = 0; bit < w; ++ bit){
        for(auto i = 0; i < n; ++ i){
            if(i & 1 << bit) a[i] += a[i ^ 1 << bit];
        }
    }
}
template<class T>
void fast_mobius_transform(vector<T> &a){
    int n = max((int)a.size(), 1);
    if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
    int w = __lg(n);
    a.resize(n);
    for(auto bit = 0; bit < w; ++ bit){
        for(auto i = 0; i < n; ++ i){
            if(i & 1 << bit) a[i] -= a[i ^ 1 << bit];
        }
    }
}

const int N = 1e6 + 5, M = (1 << 17);

int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    vector <Zp> f(M, 0);
    f[0] = 0; f[1] = 1;
    For(i, 2, M){
        f[i] = f[i - 1] + f[i - 2];
    }
    cin >> n;
    vi s(n); vector <Zp> cnt(M, 0);
    For(i, 0, n){
        cin >> s[i];
        cnt[s[i]]++;
    }
    vector <Zp> a = cnt, b = cnt, c = cnt, d = cnt, e = cnt;
    vector <Zp> ab = subset_convolute <Zp>(a, b), de = convolute <Zp, '^'>(d, e);
    For(i, 0, isz(ab)){
        ab[i] *= f[i];
    }
    For(i, 0, isz(c)){
        c[i] *= f[i];
    }
    For(i, 0, isz(de)){
        de[i] *= f[i];
    }
    vector <Zp> cac = convolute <Zp, '&'>(ab, convolute <Zp, '&'>(c, de));
    Zp ans = 0;
    For(i, 0, 17){
        ans += cac[1 << i];
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/