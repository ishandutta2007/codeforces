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

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = ModInt<mod>;

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
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) { // v
        bit.resize(n + 1);
        copy(begin(v), end(v), bit.begin() + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) {
                bit[b] += bit[b - a / 2];
            }
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n) {
        bit.resize(n + 1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) {
                bit[b] += bit[b - a / 2];
            }
        }
    }

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i))
            bit[i] += x;
    }

    void change(int i, const T &x) {
        add(i, x - query(i, i + 1));
    }

    T sum(int i) const {
        T ret = 0;
        for (; i > 0; i -= (i & -i))
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) const {
        return sum(r) - sum(l);
    }

    T operator[](int i) const {
        return query(i, i + 1);
    }

    int lower_bound(T x) const { // [0,a]xa
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x)
                x -= bit[ret += (1 << k)];
        }
        return ret;
    }

    int upper_bound(T x) const { // [0,a]xa
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x)
                x -= bit[ret += (1 << k)];
        }
        return ret;
    }
};
template <typename T>
long long inversion_number(const vector<T> &a) {
    int n = a.size();
    vector<int> v(n);
    iota(begin(v), end(v), 0);
    sort(begin(v), end(v), [&](int i, int j) {
        if (a[i] != a[j])
            return a[i] < a[j];
        return i < j;
    });
    Binary_Indexed_Tree<int> bit(n, 0);
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += bit.query(v[i] + 1, n);
        bit.add(v[i], 1);
    }
    return ret;
}
template <typename T>
struct Compress {
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs) {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs) {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) {
        xs.emplace_back(x);
    }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const {
        return xs[k];
    }
};
template <typename Monoid, typename Operator_Monoid>
struct Lazy_Segment_Tree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, Operator_Monoid)>;
    using H = function<Operator_Monoid(Operator_Monoid, Operator_Monoid)>;
    int n, height;
    vector<Monoid> seg;
    vector<Operator_Monoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e1;
    const Operator_Monoid e2;

    // f(f(a,b),c) = f(a,f(b,c)), f(e1,a) = f(a,e1) = a
    // h(h(p,q),r) = h(p,h(q,r)), h(e2,p) = h(p,e2) = p
    // g(f(a,b),p) = f(g(a,p),g(b,p))
    // g(g(a,p),q) = g(a,h(p,q))

    Lazy_Segment_Tree(const vector<Monoid> &v, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2) : f(f), g(g), h(h), e1(e1), e2(e2) {
        int m = v.size();
        n = 1, height = 0;
        while (n < m) n <<= 1, height++;
        seg.assign(2 * n, e1), lazy.assign(2 * n, e2);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Lazy_Segment_Tree(int m, const Monoid &x, const F &f, const G &g, const H &h, const Monoid &e1, const Operator_Monoid &e2) : f(f), g(g), h(h), e1(e1), e2(e2) {
        n = 1, height = 0;
        while (n < m) n <<= 1, height++;
        seg.assign(2 * n, e1), lazy.assign(2 * n, e2);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    inline Monoid reflect(int i) const { return (lazy[i] == e2 ? seg[i] : g(seg[i], lazy[i])); }

    inline void recalc(int i) {
        while (i >>= 1) seg[i] = f(reflect(2 * i), reflect(2 * i + 1));
    }

    inline void eval(int i) {
        if (i < n && lazy[i] != e2) {
            lazy[2 * i] = h(lazy[2 * i], lazy[i]);
            lazy[2 * i + 1] = h(lazy[2 * i + 1], lazy[i]);
            seg[i] = reflect(i), lazy[i] = e2;
        }
    }

    inline void thrust(int i) {
        for (int j = height; j > 0; j--) eval(i >> j);
    }

    void apply(int l, int r, const Operator_Monoid &x) {
        l = max(l, 0), r = min(r, n);
        if (l >= r) return;
        l += n, r += n;
        thrust(l), thrust(r - 1);
        int a = l, b = r;
        while (l < r) {
            if (l & 1) lazy[l] = h(lazy[l], x), l++;
            if (r & 1) r--, lazy[r] = h(lazy[r], x);
            l >>= 1, r >>= 1;
        }
        recalc(a), recalc(b - 1);
    }

    Monoid query(int l, int r) {
        l = max(l, 0), r = min(r, n);
        if (l >= r) return e1;
        l += n, r += n;
        thrust(l), thrust(r - 1);
        Monoid L = e1, R = e1;
        while (l < r) {
            if (l & 1) L = f(L, reflect(l++));
            if (r & 1) R = f(reflect(--r), R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator[](int i) { return query(i, i + 1); }

    template <typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) {
        while (i < n) {
            eval(i);
            Monoid nxt = type ? f(reflect(2 * i + type), M) : f(M, reflect(2 * i + type));
            if (check(nxt, x)) {
                i = 2 * i + type;
            } else {
                M = nxt, i = 2 * i + (type ^ 1);
            }
        }
        return i - n;
    }

    template <typename C>
    int find_first(int l, const C &check, const Monoid &x) { // check(([l,r]), x)r
        Monoid L = e1;
        int a = l + n, b = n + n;
        thrust(a);
        while (a < b) {
            if (a & 1) {
                Monoid nxt = f(L, reflect(a));
                if (check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }

    template <typename C>
    int find_last(int r, const C &check, const Monoid &x) { // check(([l,r)), x)l
        Monoid R = e1;
        int a = n, b = r + n;
        thrust(b - 1);
        while (a < b) {
            if (b & 1 || a == 1) {
                Monoid nxt = f(reflect(--b), R);
                if (check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        Compress<int> C;
        C.add(a), C.add(b);
        C.build();
        rep(i, n) a[i] = C.get(a[i]);
        rep(i, m) b[i] = C.get(b[i]);
        ll ans = inversion_number(a);
        auto f = [](int a, int b) { return min(a, b); };
        auto g = [](int a, int b) { return a + b; };
        vector<int> v0(n+1);
        iota(all(v0),0);
        Lazy_Segment_Tree<int, int> seg(v0, f, g, g, 1e9, 0);
        vector<pair<int, pair<int, int>>> ev;
        rep(i, n) ev.push_back({a[i], {0, i}}), ev.push_back({a[i] + 1, {1, i}});
        rep(i, m) ev.push_back({b[i], {2, 0}});
        sort(all(ev));
        for (auto e : ev) {
            auto [type, idx] = e.second;
            if (type == 0)
                seg.apply(idx + 1, n + 1, -1);
            else if (type == 1)
                seg.apply(0, idx + 1, 1);
            else
                ans += seg.query(0, n + 1);
        }
        cout << ans << '\n';
    }
}