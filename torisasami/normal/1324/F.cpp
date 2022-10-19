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

__int128_t gcd(__int128_t a, __int128_t b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    __int128_t cnt = a % b;
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
template <typename Data, typename T, typename S>
struct ReRooting {

    struct Node {
        int to, rev;
    };

    using F1 = function<S(S, T)>;
    using F2 = function<T(S, Data)>;

    vector<Data> data;
    vector<vector<Node>> g;
    vector<vector<S>> ldp, rdp;
    vector<int> lptr, rptr;
    const F1 f1;
    const F2 f2;
    const S ident;

    ReRooting(vector<Data> v, const F1 &f1, const F2 &f2, const S &ident) : data(v), g(v.size()), ldp(v.size()), rdp(v.size()), lptr(v.size()), rptr(v.size()), f1(f1), f2(f2), ident(ident) {
    }

    void add_edge(int u, int v) {
        g[u].emplace_back((Node){v, (int)g[v].size()});
        g[v].emplace_back((Node){u, (int)g[u].size() - 1});
    }

    S dfs(int idx, int par) {

        while (lptr[idx] != par && lptr[idx] < g[idx].size()) {
            auto &e = g[idx][lptr[idx]];
            ldp[idx][lptr[idx] + 1] = f1(ldp[idx][lptr[idx]], f2(dfs(e.to, e.rev), data[e.to]));
            ++lptr[idx];
        }
        while (rptr[idx] != par && rptr[idx] >= 0) {
            auto &e = g[idx][rptr[idx]];
            rdp[idx][rptr[idx]] = f1(rdp[idx][rptr[idx] + 1], f2(dfs(e.to, e.rev), data[e.to]));
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
};

int f1(int a, int b) {
    return a + b;
}

int f2(int a, int c) {
    a += (c ? 1 : -1);
    return max(a, 0);
}
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ReRooting<int, int, int> g(a, f1, f2, 0);
    int u, v;
    rep(i, n - 1) cin >> u >> v, g.add_edge(--u, --v);
    auto res = g.solve();
    rep(i, n) cout << res[i] + (a[i] ? 1 : -1) << (i + 1 == n ? '\n' : ' ');
}