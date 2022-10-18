#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

template<typename T>
struct modular_base{
    using Type = typename decay<decltype(T::value)>::type;
    template<class U>
    static vector<modular_base<T>> precalc_power(U base, size_t SZ){
        vector<modular_base<T>> res(SZ + 1, 1);
        for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
        return res;
    }
    static vector<Type> _INV;
    static void precalc_inverse(size_t SZ){
        if(_INV.empty()) _INV.assign(2, 1);
        for(auto x = (int)_INV.size(); x <= SZ; ++ x) _INV.push_back((mod() - 1LL * mod() / x * _INV[mod() % x]) % mod());
    }
    // mod must be a prime
    static Type _primitive_root;
    static modular_base<T> primitive_root(){
        if(_primitive_root) return _primitive_root;
        if(mod() == 2) return _primitive_root = 1;
        if(mod() == 998244353) return _primitive_root = 3;
        Type divs[20] = {};
        divs[0] = 2;
        int cnt = 1;
        Type x = (mod() - 1) / 2;
        while(x % 2 == 0) x /= 2;
        for(auto i = 3; 1LL * i * i <= x; i += 2){
            if(x % i == 0){
                divs[cnt ++] = i;
                while(x % i == 0) x /= i;
            }
        }
        if(x > 1) divs[cnt ++] = x;
        for(auto g = 2; ; ++ g){
            bool ok = true;
            for(auto i = 0; i < cnt; ++ i){
                if((modular_base<T>(g) ^ (mod() - 1) / divs[i]) == 1){
                    ok = false;
                    break;
                }
            }
            if(ok) return _primitive_root = g;
        }
    }
    constexpr modular_base(): value(){ }
    modular_base(const double &x){ value = normalize(llround(x)); }
    modular_base(const long double &x){ value = normalize(llround(x)); }
    template<typename U> modular_base(const U &x){ value = normalize(x); }
    template<typename U> static Type normalize(const U &x){
        Type v;
        if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if(v < 0) v += mod();
        return v;
    }
    const Type& operator()() const{ return value; }
    template<typename U> explicit operator U() const{ return value; }
    constexpr static Type mod(){ return T::value; }
    modular_base &operator+=(const modular_base &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
    modular_base &operator-=(const modular_base &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
    template<typename U> modular_base &operator+=(const U &otr){ return *this += modular_base(otr); }
    template<typename U> modular_base &operator-=(const U &otr){ return *this -= modular_base(otr); }
    modular_base &operator++(){ return *this += 1; }
    modular_base &operator--(){ return *this -= 1; }
    modular_base operator++(int){ modular_base result(*this); *this += 1; return result; }
    modular_base operator--(int){ modular_base result(*this); *this -= 1; return result; }
    modular_base operator-() const{ return modular_base(-value); }
    template<typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, int>::value, modular_base>::type &operator*=(const modular_base& rhs){
        #ifdef _WIN32
        unsigned long long x = static_cast<long long>(value) * static_cast<long long>(rhs.value);
        unsigned int xh = static_cast<unsigned int>(x >> 32), xl = static_cast<unsigned int>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a" (d), "=d" (m)
            : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
        #else
        value = normalize(static_cast<long long>(value) * static_cast<long long>(rhs.value));
        #endif
        return *this;
    }
    template<typename U = T>
    typename enable_if<is_same<typename modular_base<U>::Type, long long>::value, modular_base>::type &operator*=(const modular_base &rhs){
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template<typename U = T>
    typename enable_if<!is_integral<typename modular_base<U>::Type>::value, modular_base>::type &operator*=(const modular_base &rhs){
        value = normalize(value * rhs.value);
        return *this;
    }
    template<typename U>
    modular_base &operator^=(U e){
        if(e < 0) *this = 1 / *this, e = -e;
        modular_base res = 1;
        for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
        return *this = res;
    }
    template<typename U>
    modular_base operator^(U e) const{
        return modular_base(*this) ^= e;
    }
    modular_base &operator/=(const modular_base &otr){
        Type a = otr.value, m = mod(), u = 0, v = 1;
        if(a < (int)_INV.size()) return *this *= _INV[a];
        while(a){
            Type t = m / a;
            m -= t * a; swap(a, m);
            u -= t * v; swap(u, v);
        }
        assert(m == 1);
        return *this *= u;
    }
    Type value;
};
template<typename T>
vector<typename std::decay<decltype (T::value)>::type> modular_base<T>::_INV;
template<typename T>
typename std::decay<decltype (T::value)>::type modular_base<T>::_primitive_root;
template<typename T> bool operator==(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const modular_base<T>& lhs, U rhs){ return lhs == modular_base<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) == rhs; }
template<typename T> bool operator!=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const modular_base<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const modular_base<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const modular_base<T> &lhs, const modular_base<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> modular_base<T> operator+(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(const modular_base<T> &lhs, U rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator+(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) += rhs; }
template<typename T> modular_base<T> operator-(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator-(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) -= rhs; }
template<typename T> modular_base<T> operator*(const modular_base<T> &lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(const modular_base<T>& lhs, U rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator*(U lhs, const modular_base<T> &rhs){ return modular_base<T>(lhs) *= rhs; }
template<typename T> modular_base<T> operator/(const modular_base<T> &lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(const modular_base<T>& lhs, U rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> modular_base<T> operator/(U lhs, const modular_base<T> &rhs) { return modular_base<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, modular_base<T> &number){
    typename common_type<typename modular_base<T>::Type, long long>::type x;
    in >> x;
    number.value = modular_base<T>::normalize(x);
    return in;
}
template<typename T> ostream &operator<<(ostream &out, const modular_base<T> &number){ return out << number(); }

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;
*/

// constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = (119 << 23) + 1; // 998244353
constexpr int mod = 1e9 + 9; // 1000000009
using modular = modular_base<integral_constant<decay<decltype(mod)>::type, mod>>;

template<class T, class F>
struct segment_tree{
    int n, size, log;
    vector<T> data;
    F TT; // monoid operation (always adjacent)
    T T_id; // monoid identity
    // O(n)
    segment_tree(int n, F TT, T T_id): segment_tree(vector<T>(n, T_id), TT, T_id){}
    // O(n)
    segment_tree(int n, T init, F TT, T T_id): segment_tree(vector<T>(n, init), TT, T_id){}
    // O(n)
    segment_tree(const vector<T> &a, F TT, T T_id): n((int)a.size()), TT(TT), T_id(T_id){ // O(n)
        log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
        data = vector<T>(size << 1, T_id);
        copy(a.begin(), a.end(), data.begin() + size);
        for(auto i = size - 1; i >= 1; -- i) refresh(i);
    }
    // O(1)
    void refresh(int i){
        data[i] = TT(data[i << 1], data[i << 1 | 1]);
    }
    // O(log n)
    void set(int p, T x){
        assert(0 <= p && p < n);
        data[p += size] = x;
        for(auto i = 1; i <= log; ++ i) refresh(p >> i);
    }
    // O(log n)
    void update(int p, T x){
        assert(0 <= p && p < n);
        p += size;
        data[p] = TT(data[p], x);
        for(auto i = 1; i <= log; ++ i) refresh(p >> i);
    }
    // O(1)
    T query(int p) const{
        assert(0 <= p && p < n);
        return data[p + size];
    }
    // O(log n)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        T res_left = T_id, res_right = T_id;
        for(l += size, r += size; l < r; l >>= 1, r >>= 1){
            if(l & 1) res_left = TT(res_left, data[l ++]);
            if(r & 1) res_right = TT(data[-- r], res_right);
        }
        return TT(res_left, res_right);
    }
    // O(1)
    T query_all() const{
        return data[1];
    }
    // pred(sum[l, r)) is T, T, ..., T, F, F, ..., F
    // Returns max r with T
    // O(log n)
    int max_pref(int l, auto pred) const{
        assert(0 <= l && l <= n && pred(T_id));
        if(l == n) return n;
        l += size;
        T sm = T_id;
        do{
            while(~l & 1) l >>= 1;
            if(!pred(TT(sm, data[l]))){
                while(l < size){
                    l = l << 1;
                    if(pred(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
                }
                return l - size;
            }
            sm = TT(sm, data[l ++]);
        }while((l & -l) != l);
        return n;
    }
    // pred(sum[l, r)) is F, F, ..., F, T, T, ..., T
    // Returns min l with T
    // O(log n)
    int min_suff(int r, auto pred) const{
        assert(0 <= r && r <= n && pred(T_id));
        if(r == 0) return 0;
        r += size;
        T sm = T_id;
        do{
            -- r;
            while(r > 1 && r & 1) r >>= 1;
            if(!pred(TT(data[r], sm))){
                while(r < size){
                    r = r << 1 | 1;
                    if(pred(TT(data[r], sm))) sm = TT(data[r --], sm);
                }
                return r + 1 - size;
            }
            sm = TT(data[r], sm);
        }while((r & -r) != r);
        return 0;
    }
    template<class output_stream>
    friend output_stream &operator<<(output_stream &out, const segment_tree<T, F> &seg){
        out << "[";
        for(auto i = 0; i < seg.n; ++ i){
            out << seg.query(i);
            if(i != seg.n - 1) out << ", ";
        }
        return out << ']';
    }
};

struct T{
    modular sum;

    T(modular sum = 0): sum(sum){

    }
};

auto TT = [](const T &lhs, const T &rhs){
    return T(lhs.sum + rhs.sum);
};

const int N = 3e5 + 5, base = 7;

modular powbase[N], invpowbase[N];

int n;
int a[N];

template<class T, class F>
modular calhash_lr(int n, int l, int r, segment_tree <T, F> &hash_lr){
    return hash_lr.query(l, r + 1).sum * invpowbase[l];
}

template<class T, class F>
modular calhash_rl(int n, int l, int r, segment_tree <T, F> &hash_rl){
    return hash_rl.query(l, r + 1).sum * invpowbase[n - r + 1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    powbase[0] = 1;
    For(i, 1, N){
        powbase[i] = powbase[i - 1] * base;
    }
    invpowbase[N - 1] = (modular)1 / powbase[N - 1];
    FordE(i, N - 2, 0){
        invpowbase[i] = invpowbase[i + 1] * base;
    }

    segment_tree hash_lr(n + 2, T(), TT, T());
    segment_tree hash_rl(n + 2, T(), TT, T());
    ForE(i, 1, n){
        hash_lr.set(i, T(1 * powbase[i]));
        hash_rl.set(i, T(1 * powbase[n - i + 1]));
    }

    ForE(i, 1, n){
        int j = a[i];
        int len = min(j - 1, n - j);
        int l = j - len, r = j + len;
        if (calhash_lr(n, l, r, hash_lr) != calhash_rl(n, l, r, hash_rl)){
            cout << "YES" << endl;
            return 0;
        }
        hash_lr.set(j, T(2 * powbase[j]));
        hash_rl.set(j, T(2 * powbase[n - j + 1]));
    }
    cout << "NO" << endl;
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