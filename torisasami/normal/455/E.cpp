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

// const int MOD = 1000000007;
const int MOD = 998244353;
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
template <typename T, T x_low, T x_high, T id>
struct DynamicLiChaoTree {

    struct Line {
        T a, b;

        Line(T a, T b) : a(a), b(b) {
        }

        inline T get(T x) const {
            return a * x + b;
        }
    };

    struct Node {
        Line x;
        Node *l, *r;

        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {
        }
    };

    Node *root;

    DynamicLiChaoTree() : root{nullptr} {
    }

    // void rec_delete(Node *now) {
    //     if (!now)
    //         return;
    //     rec_delete(now->l), rec_delete(now->r);
    //     delete now;
    // }

    // ~DynamicLiChaoTree() {
    //     rec_delete(root);
    // }

    // void del() {
    //     rec_delete(root);
    // }

    Node *add_line(Node *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r) {
        if (!t)
            return new Node(x);

        T t_l = t->x.get(l), t_r = t->x.get(r);

        if (t_l <= x_l && t_r <= x_r) {
            return t;
        } else if (t_l >= x_l && t_r >= x_r) {
            t->x = x;
            return t;
        } else {
            T m = (l + r) / 2;
            if (m == r)
                --m;
            T t_m = t->x.get(m), x_m = x.get(m);
            if (t_m > x_m) {
                swap(t->x, x);
                if (x_l >= t_l)
                    t->l = add_line(t->l, x, l, m, t_l, t_m);
                else
                    t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);
            } else {
                if (t_l >= x_l)
                    t->l = add_line(t->l, x, l, m, x_l, x_m);
                else
                    t->r = add_line(t->r, x, m + 1, r, x_m + x.a, x_r);
            }
            return t;
        }
    }

    void add_line(const T &a, const T &b) {
        Line x(a, b);
        root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
    }

    Node *add_segment(Node *t, Line &x, const T &a, const T &b, const T &l, const T &r, const T &x_l, const T &x_r) {
        if (r < a || b < l)
            return t;
        if (a <= l && r <= b) {
            Line y{x};
            return add_line(t, y, l, r, x_l, x_r);
        }
        if (t) {
            T t_l = t->x.get(l), t_r = t->x.get(r);
            if (t_l <= x_l && t_r <= x_r)
                return t;
        } else {
            t = new Node(Line(0, id));
        }
        T m = (l + r) / 2;
        if (m == r)
            --m;
        T x_m = x.get(m);
        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);
        t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);
        return t;
    }

    void add_segment(const T &l, const T &r, const T &a, const T &b) {
        Line x(a, b);
        root = add_segment(root, x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));
    }

    T query(const Node *t, const T &l, const T &r, const T &x) const {
        if (!t)
            return id;
        if (l == r)
            return t->x.get(x);
        T m = (l + r) / 2;
        if (m == r)
            --m;
        if (x <= m)
            return min(t->x.get(x), query(t->l, l, m, x));
        else
            return min(t->x.get(x), query(t->r, m + 1, r, x));
    }

    T query(const T &x) const {
        return query(root, x_low, x_high, x);
    }
};

struct unko {
    vector<ll> a, b;
    DynamicLiChaoTree<ll, (ll)-1e6, (ll)1e6, (ll)1e18> lct;
    unko(ll _a, ll _b) : a{_a}, b{_b} {
        lct.add_line(_a, _b);
    }
    unko() {}
};

unko f(const unko &x, const unko &y) {
    unko c;
    rep(i, sz(x.a)) c.a.eb(x.a[i]), c.b.eb(x.b[i]), c.lct.add_line(x.a[i], x.b[i]);
    rep(i, sz(y.a)) c.a.eb(y.a[i]), c.b.eb(y.b[i]), c.lct.add_line(y.a[i], y.b[i]);
    return c;
}
ll g(const unko &a, ll x) {
    return a.lct.query(x);
}

template <typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, Monoid M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    ll query(int a, int b, ll x) {
        ll L = 1e18, R = 1e18;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                L = min(L, g(seg[a++], x));
            if (b & 1)
                R = min(g(seg[--b], x), R);
        }
        return min(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<ll> a(n), sum(n + 1, 0);
    rep(i, n) cin >> a[i], sum[i + 1] = sum[i] + a[i];
    int q;
    cin >> q;
    vector<ll> x(q), y(q);
    rep(i, q) cin >> x[i] >> y[i];
    SegmentTree<unko> seg(n, f, unko());
    rep(i, n) seg.set(i, unko(a[i], a[i] * (i + 1) - sum[i + 1]));
    seg.build();
    rep(i, q) cout << seg.query(y[i] - x[i], y[i], x[i] - y[i]) + sum[y[i]] << '\n';
}