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
struct DoublingLowestCommonAncestor {
    const int LOG;
    vector<int> dep;
    const G &g;
    vector<vector<int>> table;

    DoublingLowestCommonAncestor(const G &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
        build();
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for (auto &to : g[idx]) {
            if (to != par)
                dfs(to, idx, d + 1);
        }
    }

    void build(int root = 0) {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1)
                    table[k + 1][i] = -1;
                else
                    table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if (dep[u] > dep[v])
            swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1)
                v = table[i][v];
        }
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int ancestor(int u, int k) {
        if (k < 0)
            return u;
        int res = u;
        for (int i = 0; i < LOG; i++)
            if ((k >> i) & 1)
                res = table[i][res];
        return res;
    }

    int distance(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[query(u, v)];
    }

    int depth(int u) {
        return dep[u];
    }

    int move(int u, int v, int k) {
        int anc = query(u, v);
        if (anc == u)
            return ancestor(v, dep[v] - dep[u] - k);
        else if (dep[u] - dep[anc] >= k)
            return ancestor(u, k);
        else
            return ancestor(v, dep[u] + dep[v] - 2 * dep[anc] - k);
    }

    int par(int u) {
        return table[0][u];
    }
};
using LCA = DoublingLowestCommonAncestor<UnWeightedGraph>;
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    UnWeightedGraph g(n);
    UnionFind uf(n);
    int x, y;
    rep(i, m) {
        cin >> x >> y;
        if (uf.unite(--x, --y)) {
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    LCA lca(g);
    int q;
    cin >> q;
    vector<int> f(n, 0);
    vector<vector<int>> way;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int now = a;
        vector<int> w;
        while (1) {
            w.pb(now);
            if (now == b)
                break;
            now = lca.move(now, b, 1);
        }
        way.pb(w);
        f[a] ^= 1, f[b] ^= 1;
    }
    function<pair<int, int>(int, int)> dfs = [&](int now, int par) {
        int val = 0, fl = 0;
        for (auto e : g[now]) {
            if (e != par) {
                auto ret = dfs(e, now);
                val += ret.first;
                if (fl & ret.second)
                    val--;
                fl ^= ret.second;
            }
        }
        fl ^= f[now];
        if (fl & f[now])
            val++;
        return mp(val, fl);
    };
    int res = dfs(0, -1).first;
    if (!res) {
        cout << "YES" << '\n';
        rep(i, way.size()) {
            cout << way[i].size() << '\n';
            rep(j, way[i].size()) cout << way[i][j] + 1 << (j + 1 == way[i].size() ? '\n' : ' ');
        }
    } else
        cout << "NO\n" << res << endl;
}