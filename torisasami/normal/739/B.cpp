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
/*
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
    if (u < 0) u += mod;
    return u;
}
*/

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
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
using UnWeightedGraph = vector<vector<int>>;
template <typename G>
struct HeavyLightDecomposition {
    G &g;
    vector<int> sz, in, out, head, rev, par;

    HeavyLightDecomposition(G &g) : g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()) {
    }

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if (g[idx].size() && g[idx][0] == p)
            swap(g[idx][0], g[idx].back());
        for (auto &to : g[idx]) {
            if (to == p)
                continue;
            dfs_sz(to, idx);
            sz[idx] += sz[to];
            if (sz[g[idx][0]] < sz[to])
                swap(g[idx][0], to);
        }
    }

    void dfs_hld(int idx, int par, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for (auto &to : g[idx]) {
            if (to == par)
                continue;
            head[to] = (g[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times);
        }
        out[idx] = times;
    }

    void build() {
        dfs_sz(0, -1);
        int t = 0;
        dfs_hld(0, -1, t);
    }

    int la(int v, int k) {
        while (1) {
            int u = head[v];
            if (in[v] - k >= in[u])
                return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v])
                swap(u, v);
            if (head[u] == head[v])
                return u;
        }
    }

    template <typename T, typename Q, typename F>
    T query(int u, int v, const T &ti, const Q &q, const F &f, bool edge = false) {
        T l = ti, r = ti;
        for (;; v = par[head[v]]) {
            if (in[u] > in[v])
                swap(u, v), swap(l, r);
            if (head[u] == head[v])
                break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
        //  return {f(q(in[u] + edge, in[v] + 1), l), r};
    }

    template <typename Q>
    void add(int u, int v, const Q &q, bool edge = false) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v])
                swap(u, v);
            if (head[u] == head[v])
                break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }
};
template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid OM0) : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while (sz < n)
            sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if (lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid reflect(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while (k >>= 1)
            data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--)
            propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                lazy[l] = h(lazy[l], x), ++l;
            if (r & 1)
                --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                L = f(L, reflect(l++));
            if (r & 1)
                R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            propagate(a);
            Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, reflect(1))))
                return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, reflect(a));
                if (check(nxt))
                    return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(reflect(1), R)))
                return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(reflect(--b), R);
                if (check(nxt))
                    return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    UnWeightedGraph g(n);
    vector<vector<pair<ll, ll>>> li(n);
    ll p, w;
    rep(i, n - 1) cin >> p >> w, p--, g[p].pb(i + 1), li[p].pb(i + 1, w);
    HeavyLightDecomposition<UnWeightedGraph> hld(g);
    hld.build();
    auto func = [](ll a, ll b) { return a + b; };
    LazySegmentTree<ll, ll> seg(n, func, func, func, 0, 0);
    seg.build();
    vector<ll> d(n);
    d[0] = 0;
    function<void(int)> dfs = [&](int now) {
        for(auto [dst, dis] : li[now]){
            d[dst] = d[now] + dis;
            dfs(dst);
        }
    };
    dfs(0);
    vector<pair<ll, pair<ll, ll>>> ev;
    rep(i, n) ev.push_back({d[i] - a[i], {0, i}}), ev.push_back({d[i], {1, i}});
    sort(all(ev));
    ll ans[n];
    for(auto e: ev){
        auto [f, idx] = e.second;
        // cout << f << " " << idx << endl;
        if (!f)
            hld.add(0, idx, [&](ll a, ll b) { return seg.update(a, b, 1); });
        else
            ans[idx] = hld.query(idx, idx, 0, [&](ll a, ll b) { return seg.query(a, b); }, [](ll a, ll b) { return a + b; }) - 1;
    }
    rep(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
}