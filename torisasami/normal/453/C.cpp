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
using Graph = vector<vector<int>>;
template <typename G>
struct HeavyLightDecomposition {
    G &g;
    vector<int> siz, in, out, head, rev, par, dep;

    HeavyLightDecomposition(G &g) : g(g), siz(g.size()), in(g.size()), out(g.size()), head(g.size()), rev(g.size()), par(g.size()), dep(g.size(), 0) {
        build();
    }

    void dfs_sz(int idx, int p) {
        par[idx] = p;
        siz[idx] = 1;
        if (g[idx].size() && g[idx][0] == p)
            swap(g[idx][0], g[idx].back());
        for (auto &to : g[idx]) {
            if (to == p)
                continue;
            dep[to] = dep[idx] + 1;
            dfs_sz(to, idx);
            siz[idx] += siz[to];
            if (siz[g[idx][0]] < siz[to])
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
        if (!k)
            return u;
        int l = lca(u, v), d = dep[u] + dep[v] - dep[l] * 2;
        if (d < k)
            return -1;
        if (dep[u] - dep[l] >= k)
            return la(u, k);
        return la(v, d - k);
    }

    vector<int> path(int u, int v) {
        int l = lca(u, v);
        vector<int> a, b;
        for (; v != l; v = par[v])
            b.eb(v);
        for (; u != l; u = par[u])
            a.eb(u);
        a.emplace_back(l);
        for (int i = (int)b.size() - 1; i >= 0; i--)
            a.eb(b[i]);
        return a;
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
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    Graph g0(n);
    int u, v;
    rep(i, m) {
        cin >> u >> v;
        if (uf.unite(--u, --v))
            g0[u].eb(v), g0[v].eb(u);
    }
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int no = -1;
    rep(i, n) {
        if (!x[i])
            continue;
        if (no != -1 && no != uf.find(i)) {
            cout << -1 << endl;
            return 0;
        }
        no = uf.find(i);
    }
    if (no == -1) {
        cout << 0 << endl;
        return 0;
    }
    int id = 0, cn = uf.size(no);
    vector<int> p(n, -1), q(cn);
    rep(i, n) if (uf.find(i) == no) p[i] = id, q[id++] = i;
    Graph g(cn);
    rep(i, n) {
        if (p[i] != -1) {
            for (auto e : g0[i])
                g[p[i]].eb(p[e]);
        }
    }
    HLD hld(g);
    vector<int> ans;
    vector<int> c(n, 0);
    auto dfs0 = [&](int now, int par, auto &&f) -> void {
        c[q[now]] ^= 1;
        for (auto e : g[now]) {
            if (e != par)
                f(e, now, f), c[q[now]] ^= 1;
        }
    };
    dfs0(0, -1, dfs0);
    bool fo = (accumulate(all(x), 0) % 2 != accumulate(all(c), 0) % 2);
    if (fo)
        c[q[0]] ^= 1;
    auto dfs = [&](int now, int par, int memo, auto &&f) -> int {
        ans.eb(now);
        if (c[q[now]] != x[q[now]]) {
            if (memo == -1)
                memo = now;
            else {
                auto pa = hld.path(now, memo);
                rep2(i, 1, sz(pa)) ans.eb(pa[i]);
                per(i, sz(pa) - 1) ans.eb(pa[i]);
                memo = -1;
            }
        }
        for (auto e : g[now]) {
            if (e == par)
                continue;
            memo = f(e, now, memo, f);
            if (!fo || now != 0 || e != g[now].back())
                ans.eb(now);
        }
        return memo;
    };
    dfs(0, -1, -1, dfs);
    rep(i, sz(ans)) ans[i] = q[ans[i]];
    cout << sz(ans) << endl;
    print(ans, 1);
}