#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

template<typename T>
struct modular_base{
    using Type = typename decay<decltype(T::value)>::type;
    static vector<Type> _MOD_INV;
    constexpr modular_base(): value(){ }
    template<typename U> modular_base(const U &x){ value = normalize(x); }
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
        if(a < (int)_MOD_INV.size()) return *this *= _MOD_INV[a];
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
template<typename T> vector<typename modular_base<T>::Type> modular_base<T>::_MOD_INV;
template<typename T>
void precalc_inverse(int SZ){
    auto &inv = T::_MOD_INV;
    if(inv.empty()) inv.assign(2, 1);
    for(; inv.size() <= SZ; ) inv.push_back((T::mod() - 1LL * T::mod() / (int)inv.size() * inv[T::mod() % (int)inv.size()]) % T::mod());
}
template<typename T>
vector<T> precalc_power(T base, int SZ){
    vector<T> res(SZ + 1, 1);
    for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
    return res;
}

/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using modular = modular_base<VarMod>;
*/

constexpr int mod = 1e9 + 7; // 1000000007
// constexpr int mod = (119 << 23) + 1; // 998244353
// constexpr int mod = 1e9 + 9; // 1000000009
using modular = modular_base<integral_constant<decay<decltype(mod)>::type, mod>>;

struct Z2_basis{
    static const int D = 60;

    int _rank;

    ll basis[D];

    void clear(){
        _rank = 0;
        fill(basis, basis + D, 0);
    }

    Z2_basis(){
        clear();
    }

    bool insert(ll x){
        FordE(d, D - 1, 0){
            if (!(x >> d & 1)){
                continue;
            }
            if (basis[d] == 0){
                _rank++;
                basis[d] = x;
                return 1;
            }
            else{
                x ^= basis[d];
            }
        }
        return 0;
    }
    
    int rank(){
        return _rank;
    }
};

const int N = 1e5 + 5, M = 2e5 + 5, D = 60;

int n, m;
vector <pair <int, ll>> adj[N];

bool vis[N];
Z2_basis cac;

ll prefxor[N];
int cnt0[D], cnt1[D];

void dfs(int u){
    vis[u] = 1;
    For(d, 0, D){
        if (prefxor[u] >> d & 1){
            cnt1[d]++;
        }
        else{
            cnt0[d]++;
        }
    }
    Fora(&edge, adj[u]){
        int v; ll w; tie(v, w) = edge;
        if (vis[v]){
            cac.insert(prefxor[u] ^ prefxor[v] ^ w);
        }
        else{
            prefxor[v] = prefxor[u] ^ w;
            dfs(v);
        }
    }
}

modular ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    ForE(u, 1, n){
        if (vis[u]){
            continue;
        }
        cac.clear();
        fill(cnt0, cnt0 + D, 0);
        fill(cnt1, cnt1 + D, 0);
        dfs(u);
        int cnt = cnt0[0] + cnt1[0];
        ll orbasis = 0;
        For(d, 0, D){
            orbasis |= cac.basis[d];
        }
        For(d, 0, D){
            if (!(orbasis >> d & 1)){
                ans += (modular)cnt0[d] * cnt1[d] * (1ll << cac.rank()) * (1ll << d);
            }
            else{
                ans += (modular)cnt * (cnt - 1) / 2 * (1ll << (cac.rank() - 1)) * (1ll << d);
            }
        }
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