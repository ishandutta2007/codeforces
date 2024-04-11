#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define per(i, n) for (int i = (n)-1; 0 <= i; i--)
#define rep2(i, l, r) for (int i = (l); i < int(r); i++)
#define per2(i, l, r) for (int i = (r)-1; int(l) <= i; i--)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty())
        cout << '\n';
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using maxheap = std::priority_queue<T>;
template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

// __int128_t gcd(__int128_t a, __int128_t b) {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     __int128_t cnt = a % b;
//     while (cnt != 0) {
//         a = b;
//         b = cnt;
//         cnt = a % b;
//     }
//     return b;
// }

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
    vector<int> data;
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

    int size(int k) {
        return (-data[find(k)]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int operator[](int k) {
        return find(k);
    }
};

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

ll mpow2(ll x, ll n, ll mod) {
    ll ans = 1;
    x %= mod;
    while (n != 0) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    ans %= mod;
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

ll divide_int(ll a, ll b) {
    return (a >= 0 ? a / b : (a - b + 1) / b);
}

const int MOD = 1000000007;
// const int MOD = 998244353;
using mint = Mod_Int<MOD>;

mint mpow(mint x, ll n) {
    bool rev = n < 0;
    n = abs(n);
    mint ans = 1;
    while (n != 0) {
        if (n & 1)
            ans *= x;
        x *= x;
        n = n >> 1;
    }
    return (rev ? ans.inverse() : ans);
}

// ----- library -------
template <typename T>
struct Combination {
    vector<T> _fac, _ifac;

    Combination() {
        init();
    }
    Combination(int n) {
        init(n);
    }

    void init(int n = 2000010) {
        _fac.resize(n + 1), _ifac.resize(n + 1);
        _fac[0] = 1;
        for (int i = 1; i <= n; i++)
            _fac[i] = _fac[i - 1] * i;
        _ifac[n] = _fac[n].inverse();
        for (int i = n; i >= 1; i--)
            _ifac[i - 1] = _ifac[i] * i;
    }

    T fac(int k) {
        return _fac[k];
    }

    T ifac(int k) {
        return _ifac[k];
    }

    T inv(int k) {
        return fac(k - 1) * ifac(k);
    }

    T P(int n, int k) {
        if (k < 0 || n < k)
            return 0;
        return fac(n) * ifac(n - k);
    }

    T C(int n, int k) {
        if (k < 0 || n < k)
            return 0;
        return fac(n) * ifac(n - k) * ifac(k);
    }

    T H(int n, int k) { // kn
        if (n < 0 || k < 0)
            return 0;
        return k == 0 ? 1 : C(n + k - 1, k);
    }

    T second_stirling_number(int n, int k) { // nk1
        T ret = 0;
        for (int i = 0; i <= k; i++) {
            T tmp = C(k, i) * T(i).pow(n);
            ret += ((k - i) & 1) ? -tmp : tmp;
        }
        return ret * ifac(k);
    }

    T bell_number(int n, int k) { // nk
        if (n == 0)
            return 1;
        k = min(k, n);
        vector<T> pref(k + 1);
        pref[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (i & 1)
                pref[i] = pref[i - 1] - ifac(i);
            else
                pref[i] = pref[i - 1] + ifac(i);
        }
        T ret = 0;
        for (int i = 1; i <= k; i++)
            ret += T(i).pow(n) * ifac(i) * pref[k - i];
        return ret;
    }
};
using comb = Combination<mint>;
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    comb comb;
    int n, k;
    cin >> n >> k;
    mint ans = 0;
    rep(i, min(k, n) + 1) ans += comb.C(n, i);
    cout << ans << endl;
}