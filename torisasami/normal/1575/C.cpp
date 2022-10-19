#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define REP(i, l, r) for (ll i = l; i < (r); i++)
#define REP2(i, l, r) for (ll i = (ll)r - 1; i >= (l); i--)
#define siz(x) (ll) x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    ll cnt = a % b;
    while (cnt != 0) {
        a = b;
        b = cnt;
        cnt = a % b;
    }
    return b;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

struct UnionFind {
    vector<ll> data;
    int num;

    UnionFind(int sz) {
        data.assign(sz, -1);
        num = sz;
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        num--;
        return (true);
    }

    int find(int k) {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    ll size(int k) {
        return (-data[find(k)]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {
    }

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }

    ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }

    ModInt &operator++() {
        return *this += ModInt(1);
    }

    ModInt operator++(int) {
        ModInt tmp = *this;
        ++*this;
        return tmp;
    }

    ModInt &operator--() {
        return *this -= ModInt(1);
    }

    ModInt operator--(int) {
        ModInt tmp = *this;
        --*this;
        return tmp;
    }

    ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }

    ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }

    bool operator==(const ModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const ModInt &p) const {
        return x != p.x;
    }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() {
        return mod;
    }
};

ll mpow2(ll x, ll n, ll mod) {
    ll ans = 1;
    while (n != 0) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}
ll modinv2(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0)
        u += mod;
    return u;
}

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {
    }

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    static int get_mod() {
        return mod;
    }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() {
        return *this += Mod_Int(1);
    }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() {
        return *this -= Mod_Int(1);
    }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const {
        return Mod_Int(-x);
    }

    Mod_Int operator+(const Mod_Int &p) const {
        return Mod_Int(*this) += p;
    }

    Mod_Int operator-(const Mod_Int &p) const {
        return Mod_Int(*this) -= p;
    }

    Mod_Int operator*(const Mod_Int &p) const {
        return Mod_Int(*this) *= p;
    }

    Mod_Int operator/(const Mod_Int &p) const {
        return Mod_Int(*this) /= p;
    }

    bool operator==(const Mod_Int &p) const {
        return x == p.x;
    }

    bool operator!=(const Mod_Int &p) const {
        return x != p.x;
    }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1)
                ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = Mod_Int<mod>;

mint mpow(mint x, ll n) {
    mint ans = 1;
    while (n != 0) {
        if (n & 1)
            ans *= x;
        x *= x;
        n = n >> 1;
    }
    return ans;
}

// ----- library -------
template <typename T>
struct Number_Theoretic_Transform {
    static int max_base;
    static T root;
    static vector<T> r, ir;

    Number_Theoretic_Transform() {
    }

    static void init() {
        if (!r.empty())
            return;
        int mod = T::get_mod();
        int tmp = mod - 1;
        root = 2;
        while (root.pow(tmp >> 1) == 1)
            root++;
        max_base = 0;
        while (tmp % 2 == 0)
            tmp >>= 1, max_base++;
        r.resize(max_base), ir.resize(max_base);
        for (int i = 0; i < max_base; i++) {
            r[i] = -root.pow((mod - 1) >> (i + 2)); // r[i]:=12^(i+2)
            ir[i] = r[i].inverse();                 // ir[i]:=1/r[i]
        }
    }

    static void ntt(vector<T> &a) {
        init();
        int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(n <= (1 << max_base));
        for (int k = n; k >>= 1;) {
            T w = 1;
            for (int s = 0, t = 0; s < n; s += 2 * k) {
                for (int i = s, j = s + k; i < s + k; i++, j++) {
                    T x = a[i], y = w * a[j];
                    a[i] = x + y, a[j] = x - y;
                }
                w *= r[__builtin_ctz(++t)];
            }
        }
    }

    static void intt(vector<T> &a) {
        init();
        int n = a.size();
        assert((n & (n - 1)) == 0);
        assert(n <= (1 << max_base));
        for (int k = 1; k < n; k <<= 1) {
            T w = 1;
            for (int s = 0, t = 0; s < n; s += 2 * k) {
                for (int i = s, j = s + k; i < s + k; i++, j++) {
                    T x = a[i], y = a[j];
                    a[i] = x + y, a[j] = w * (x - y);
                }
                w *= ir[__builtin_ctz(++t)];
            }
        }
        T inv = T(n).inverse();
        for (auto &e : a)
            e *= inv;
    }

    static vector<T> convolve(vector<T> a, vector<T> b) {
        int k = (int)a.size() + (int)b.size() - 1, n = 1;
        while (n < k)
            n <<= 1;
        a.resize(n), b.resize(n);
        ntt(a), ntt(b);
        for (int i = 0; i < n; i++)
            a[i] *= b[i];
        intt(a), a.resize(k);
        return a;
    }
};

template <typename T>
int Number_Theoretic_Transform<T>::max_base = 0;

template <typename T>
T Number_Theoretic_Transform<T>::root = T();

template <typename T>
vector<T> Number_Theoretic_Transform<T>::r = vector<T>();

template <typename T>
vector<T> Number_Theoretic_Transform<T>::ir = vector<T>();
// NTT
const int m1 = 1045430273;
const int m2 = 1051721729;
const int m3 = 1053818881;

template <typename T>
struct Arbitrary_Mod_Number_Theoretic_Transform {
    using mint_1 = Mod_Int<m1>;
    using mint_2 = Mod_Int<m2>;
    using mint_3 = Mod_Int<m3>;
    using NTT_1 = Number_Theoretic_Transform<mint_1>;
    using NTT_2 = Number_Theoretic_Transform<mint_2>;
    using NTT_3 = Number_Theoretic_Transform<mint_3>;

    Arbitrary_Mod_Number_Theoretic_Transform() {
    }

    static vector<T> convolve(const vector<T> &a, const vector<T> &b) {
        int n = a.size(), m = b.size();
        vector<mint_1> a1(n), b1(m);
        vector<mint_2> a2(n), b2(m);
        vector<mint_3> a3(n), b3(m);
        for (int i = 0; i < n; i++)
            a1[i] = a[i].x, a2[i] = a[i].x, a3[i] = a[i].x;
        for (int i = 0; i < m; i++)
            b1[i] = b[i].x, b2[i] = b[i].x, b3[i] = b[i].x;
        auto x = NTT_1::convolve(a1, b1);
        auto y = NTT_2::convolve(a2, b2);
        auto z = NTT_3::convolve(a3, b3);
        const auto m1_inv_m2 = mint_2(m1).inverse().x;
        const auto m1m2_inv_m3 = (mint_3(m1) * m2).inverse().x;
        const auto m1m2_mod = (T(m1) * m2).x;
        vector<T> ret(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            auto v1 = ((mint_2(y[i]) + m2 - x[i].x) * m1_inv_m2).x;
            auto v2 = ((z[i] + m3 - x[i].x - mint_3(m1) * v1) * m1m2_inv_m3).x;
            ret[i] = (T(x[i].x)) + T(m1) * v1 + T(m1m2_mod) * v2;
        }
        return ret;
    }
};
using NTT = Arbitrary_Mod_Number_Theoretic_Transform<mint>;
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n + 1, 0);
    rep(i, n) s[i + 1] = (s[i] + a[i]) % k;
    vector<mint> c0(k, 0), c2(k, 0);
    rep(i, n + 1) c0[s[i]]++;
    mint ans = 0;
    rep(i, k) ans += c0[i] * (c0[i] - 1) / 2;
    c0[s[0]]--;
    ll tmp = 0;
    rep(i, m - 1) tmp += s[n], tmp %= k, c2[tmp]++;
    auto res = NTT::convolve(c0, c2);
    rep(i, n) {
        ans += res[s[i]];
        if (s[i] + k < res.size())
            ans += res[s[i] + k];
    }
    ll all = s[n] * m % k;
    vector<mint> cnt(k, 0);
    REP(i, 1, n) ans += cnt[s[i]], cnt[(all + s[i]) % k]++;
    ans *= m;
    if (all == 0)
        ans -= m - 1;
    cout << ans << endl;
}