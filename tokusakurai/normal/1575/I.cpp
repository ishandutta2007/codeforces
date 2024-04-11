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

template <typename T>
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
        bit.resize(n + 1);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n) {
        bit.resize(n + 1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T &x) { add(i, x - query(i, i + 1)); }

    T sum(int i) const {
        T ret = 0;
        for (; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }

    T query(int l, int r) const { return sum(r) - sum(l); }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }

    int upper_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }
};

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<int> par, si, depth;
    vector<int> root;       // 
    vector<int> id_v, id_e; // 
    const int n;
    int m;

    Graph(int n) : es(n), par(n), si(n), depth(n), root(n), id_v(n), id_e(n - 1), n(n), m(0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    int _dfs1(int now, int pre = -1) {
        par[now] = pre;
        if (pre == -1) depth[now] = 0;
        si[now] = 1;
        for (auto &e : es[now]) {
            if (e.to != pre) {
                depth[e.to] = depth[now] + 1;
                si[now] += _dfs1(e.to, now);
            }
        }
        return si[now];
    }

    void _dfs2(int now, bool st, int &s, int pre = -1) {
        root[now] = (st ? now : root[pre]);
        id_v[now] = s++;
        edge heavy = {-1, -1};
        int M = 0;
        for (auto &e : es[now]) {
            if (e.to == pre) continue;
            if (M < si[e.to]) M = si[e.to], heavy = e;
        }
        if (heavy.id != -1) {
            id_e[heavy.id] = s;
            _dfs2(heavy.to, false, s, now);
        }
        for (auto &e : es[now]) {
            if (e.to != pre && e.id != heavy.id) {
                id_e[e.id] = s;
                _dfs2(e.to, true, s, now);
            }
        }
    }

    void decompose(int root = 0) {
        _dfs1(root);
        int s = 0;
        _dfs2(root, true, s);
    }

    vector<pair<int, int>> get_path(int u, int v, bool use_edge = false) { //
        vector<pair<int, int>> ret;
        while (root[u] != root[v]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            ret.emplace_back(id_v[root[v]], id_v[v] + 1);
            v = par[root[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        ret.emplace_back(id_v[u] + use_edge, id_v[v] + 1);
        return ret;
    }

    vector<pair<int, int>> get_path_noncommutative(int u, int v, bool use_edge = false) { // 
        vector<pair<int, int>> l, r;
        while (root[u] != root[v]) {
            if (depth[root[u]] > depth[root[v]]) {
                l.emplace_back(id_v[u] + 1, id_v[root[u]]);
                u = par[root[u]];
            } else {
                r.emplace_back(id_v[root[v]], id_v[v] + 1);
                v = par[root[v]];
            }
        }
        if (depth[u] > depth[v]) {
            l.emplace_back(id_v[u] + 1, id_v[v] + use_edge);
        } else {
            r.emplace_back(id_v[u] + use_edge, id_v[v] + 1);
        }
        reverse(begin(r), end(r));
        for (auto &e : r) l.push_back(e);
        return l;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> a(N);
    rep(i, N) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    Graph G(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    G.decompose();

    Binary_Indexed_Tree<ll> bit(N, 0);
    rep(i, N) bit.change(G.id_v[i], a[i]);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            ll c;
            cin >> u >> c;
            c = abs(c);
            u--;
            bit.change(G.id_v[u], c);
            a[u] = c;
        } else {
            int u, v;
            cin >> u >> v;
            u--, v--;
            ll ans = -a[u] - a[v];
            each(e, G.get_path(u, v)) {
                auto [l, r] = e;
                ans += bit.query(l, r) * 2;
            }
            cout << ans << '\n';
        }
    }
}