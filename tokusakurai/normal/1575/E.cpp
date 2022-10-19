#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

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

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
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

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

mint tw = mint(2).inverse();

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id, col;
        edge(int to, int id, int col) : to(to), id(id), col(col) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> si;
    vector<bool> used;
    vector<mint> a;
    int K;

    Graph(int n) : es(n), n(n), m(0), si(n), used(n, false), a(n) {}

    void add_edge(int from, int to, int col) {
        es[from].emplace_back(to, m, col);
        if (!directed) es[to].emplace_back(from, m, col);
        m++;
    }

    int calc_size(int now, int pre = -1) {
        si[now] = 1;
        for (auto &e : es[now]) {
            if (e.to == pre || used[e.to]) continue;
            si[now] += calc_size(e.to, now);
        }
        return si[now];
    }

    pair<int, int> search_centroid(int now, int sz, int pre = -1) { // ()
        pair<int, int> ret = make_pair(INT_MAX, -1);
        int M = 0, S = 1;
        for (auto &e : es[now]) {
            if (e.to == pre || used[e.to]) continue;
            ret = min(ret, search_centroid(e.to, sz, now));
            M = max(M, si[e.to]);
            S += si[e.to];
        }
        M = max(M, sz - S);
        ret = min(ret, make_pair(M, now));
        return ret;
    }

    void dfs(int now, int pre, int k, int p, mint s, vector<mint> &c, vector<mint> &d) {
        while (sz(c) <= k) c.eb(0), d.eb(0);
        c[k] += s, d[k]++;
        each(e, es[now]) {
            if (e.to == pre || used[e.to]) continue;
            dfs(e.to, now, k + (p != e.col), e.col, s + a[e.to], c, d);
        }
    }

    mint solve(int u) {
        vector<vector<mint>> c(2), d(2);
        each(e, es[u]) {
            if (used[e.to]) continue;
            dfs(e.to, u, 1, e.col, a[e.to], c[e.col], d[e.col]);
        }
        rep(i, 2) {
            int k = sz(c[i]);
            rep2(j, 1, k - 1) c[i][j] += c[i][j - 1], d[i][j] += d[i][j - 1];
        }
        // print(c[0]), print(c[1]);
        mint ret = a[u];
        each(e, es[u]) {
            if (used[e.to]) continue;
            vector<mint> tc, td;
            dfs(e.to, u, 1, e.col, a[e.to], tc, td);
            int k = sz(tc);
            vector<mint> sc = tc, sd = td;
            int l = sz(c[e.col]);
            sc.resize(l), sd.resize(l);
            rep2(j, 1, l - 1) sc[j] += sc[j - 1], sd[j] += sd[j - 1];
            rep(j, l) c[e.col][j] -= sc[j], d[e.col][j] -= sd[j];
            rep(j, k) {
                if (j <= K + 1) ret += tc[j] + td[j] * a[u];
            }
            rep(i, 2) {
                rep(j, k) {
                    int m = K + 1 - j + (e.col == i);
                    chmin(m, sz(c[i]) - 1);
                    if (m < 0) continue;
                    // assert(m >= 0), assert(m < sz(c[i])), assert(m < sz(d[i]));
                    ret += (c[i][m] * td[j] + tc[j] * d[i][m] + a[u] * d[i][m] * td[j]) * tw;
                }
            }
            // cout << ret << '\n';
            rep(j, l) c[e.col][j] += sc[j], d[e.col][j] += sd[j];
        }
        return ret;
    }

    int centroid(int s) { // s
        calc_size(s);
        return search_centroid(s, si[s]).second;
    }

    mint decompose(int root = 0) {
        mint ret = 0;
        int c = centroid(root);
        used[c] = true;
        ret += solve(c);
        // cout << c << ' ' << ret << '\n';
        for (auto &e : es[c]) {
            if (!used[e.to]) ret += decompose(e.to);
        }
        return ret;
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    Graph G(N);
    rep(i, N) cin >> G.a[i];
    G.K = K;

    rep(i, N - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G.add_edge(u, v, c);
    }

    cout << G.decompose() << '\n';
}