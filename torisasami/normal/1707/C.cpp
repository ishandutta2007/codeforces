#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define REP(i, l, r) for (int i = l; i < (r); i++)
#define REP2(i, l, r) for (int i = (int)r - 1; i >= (l); i--)
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

template <class T>
void print(vector<T> a) {
    if (a.empty())
        cout << '\n';
    else {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
    }
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

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = Mod_Int<mod>;

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
using Graph = vector<vector<int>>;
template <typename G>
struct HeavyLightDecomposition {
    G &g;
    vector<int> sz, in, out, head, rev, par, dep;

    HeavyLightDecomposition(G &g) : g(g), sz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()), dep(g.size(), 0) {
        build();
    }

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        sz[idx] = 1;
        if (g[idx].size() && g[idx][0] == p)
            swap(g[idx][0], g[idx].back());
        for (auto &to : g[idx]) {
            if (to == p)
                continue;
            dep[to] = dep[idx] + 1;
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

    int distance(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int depth(int u) {
        return dep[u];
    }

    int move(int u, int v, int k) {
        int anc = lca(u, v);
        if (anc == u)
            return la(v, dep[v] - dep[u] - k);
        else if (dep[u] - dep[anc] >= k)
            return la(u, k);
        else
            return la(v, dep[u] + dep[v] - 2 * dep[anc] - k);
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
using HLD = HeavyLightDecomposition<Graph>;
template <typename Data, typename T>
struct ReRooting {

    struct Node {
        int to, rev;
        Data data;
    };

    using F1 = function<T(T, T)>;
    using F2 = function<T(T, Data)>;

    vector<vector<Node>> g;
    vector<vector<T>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const T ident;
    vector<unordered_map<int, int>> id;

    ReRooting(int n, const F1 &f1, const F2 &f2, const T &ident) : g(n), ldp(n), rdp(n), lptr(n), rptr(n), f1(f1), f2(f2), ident(ident), id(n) {
    }

    void add_edge(int u, int v, const Data &d) {
        id[u][v] = g[u].size();
        id[v][u] = g[v].size();
        g[u].emplace_back((Node){v, (int)g[v].size(), d});
        g[v].emplace_back((Node){u, (int)g[u].size() - 1, d});
    }

    void add_edge_bi(int u, int v, const Data &d, const Data &e) {
        g[u].emplace_back((Node){v, (int)g[v].size(), d});
        g[v].emplace_back((Node){u, (int)g[u].size() - 1, e});
    }

    T dfs(int idx, int par) {
        while (lptr[idx] != par && lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), e.data));
            ++lptr[idx];
        }
        while (rptr[idx] != par && rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), e.data));
            --rptr[idx];
        }
        if (par < 0)
            return rdp[idx][0];
        return f1(ldp[idx][par], rdp[idx][par + 1]);
    }

    vector<T> solve() {
        for (int i = 0; i < g.size(); i++) {
            ldp[i].assign(g[i].size() + 1, ident);
            rdp[i].assign(g[i].size() + 1, ident);
            lptr[i] = 0;
            rptr[i] = (int)g[i].size() - 1;
        }
        vector<T> ret;
        for (int i = 0; i < g.size(); i++) {
            ret.push_back(dfs(i, -1));
        }
        return ret;
    }

    T query(int idx, int par) {
        return dfs(idx, id[idx][par]);
    }
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), fl(m, 0);
    rep(i, m) cin >> u[i] >> v[i], u[i]--, v[i]--;
    Graph g(n);
    map<pair<int, int>, int> f;
    UnionFind uf(n);
    rep(i, m) {
        if (uf.unite(u[i], v[i]))
            g[u[i]].pb(v[i]), g[v[i]].pb(u[i]), fl[i] = 1;
    }
    HLD hld(g);
    rep(i, m) {
        if (!fl[i]) {
            int nu = hld.move(u[i], v[i], 1), nv = hld.move(v[i], u[i], 1);
            f[{nu, u[i]}]++, f[{u[i], nu}]--, f[{nv, v[i]}]++, f[{v[i], nv}]--;
        }
    }
    auto func = [](int a, int b) { return a + b; };
    ReRooting<int, int> r(n, func, func, 0);
    rep(i, m) if (fl[i]) r.add_edge_bi(u[i], v[i], f[{u[i], v[i]}], f[{v[i], u[i]}]);
    auto ret = r.solve();
    rep(i, n) cout << (ret[i] ? '0' : '1');
    cout << endl;
}