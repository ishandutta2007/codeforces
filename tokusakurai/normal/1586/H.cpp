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

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n) {}

    int root(int x) {
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator[](int i) { return root(i); }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        cnt--;
        return true;
    }

    int size(int x) { return -data[root(x)]; }

    int count() { return cnt; };

    bool same(int x, int y) { return root(x) == root(y); }

    void clear() {
        cnt = n;
        fill(begin(data), end(data), -1);
    }
};

template <typename Monoid>
struct Segment_Tree {
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;

    // f(f(a,b),c) = f(a,f(b,c)), f(e1,a) = f(a,e1) = a

    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1) {
        int m = v.size();
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Segment_Tree(int m, const Monoid &x, const F &f, const Monoid &e1) : f(f), e1(e1) {
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), begin(seg) + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    void change(int i, const Monoid &x, bool update = true) {
        if (update) {
            seg[i + n] = x;
        } else {
            seg[i + n] = f(seg[i + n], x);
        }
        i += n;
        while (i >>= 1) { seg[i] = f(seg[2 * i], seg[2 * i + 1]); }
    }

    Monoid query(int l, int r) const {
        Monoid L = e1, R = e1;
        l += n, r += n;
        while (l < r) {
            if (l & 1) L = f(L, seg[l++]);
            if (r & 1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator[](int i) const { return seg[n + i]; }

    template <typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const {
        while (i < n) {
            Monoid nxt = type ? f(seg[2 * i + type], M) : f(M, seg[2 * i + type]);
            if (check(nxt, x)) {
                i = 2 * i + type;
            } else {
                M = nxt, i = 2 * i + (type ^ 1);
            }
        }
        return i - n;
    }

    template <typename C>
    int find_first(int l, const C &check, const Monoid &x) const { // check(([l,r]), x)r
        Monoid L = e1;
        int a = l + n, b = n + n;
        while (a < b) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }

    template <typename C>
    int find_last(int r, const C &check, const Monoid &x) const { // check(([l,r)), x)l
        Monoid R = e1;
        int a = n, b = r + n;
        while (a < b) {
            if (b & 1 || a == 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<vector<int>> par; // par[i][j] := j2^i
    vector<int> depth;
    int height;

    vector<int> c;
    vector<int> ls, rs;
    int cnt;

    Graph(int n) : es(n), n(n), m(0), depth(n), c(n, 0), ls(n), rs(n), cnt(0) {
        height = 1;
        while ((1 << height) < n) height++;
        par.assign(height, vector<int>(n));
    }

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void prepare(int now, int pre = -1) {
        if (pre == -1) depth[now] = 0;
        par[0][now] = pre;
        ls[now] = cnt++;
        for (auto &e : es[now]) {
            if (e.to != pre) {
                depth[e.to] = depth[now] + 1;
                prepare(e.to, now);
            }
        }
        rs[now] = cnt;
    }

    void build(int root = 0) { // root
        prepare(root);
        for (int j = 0; j < height - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (par[j][i] == -1) {
                    par[j + 1][i] = -1;
                } else {
                    par[j + 1][i] = par[j][par[j][i]];
                }
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int D = depth[u] - depth[v];
        for (int i = 0; i < height; i++) {
            if ((D >> i) & 1) u = par[i][u];
        }
        if (u == v) return u;
        for (int i = height - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }

    int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<tuple<int, int, int>> es1, es2;
    rep(i, N - 1) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        u--, v--;
        es1.eb(c, u, v);
        es2.eb(t, u, v);
    }

    sort(rall(es1));
    sort(all(es2));

    Graph G1(2 * N - 1), G2(2 * N - 1);
    Union_Find_Tree uf1(N), uf2(N);
    vector<int> p1(N), p2(N);
    iota(all(p1), 0), iota(all(p2), 0);

    rep(i, N - 1) {
        auto [c, u, v] = es1[i];
        G1.c[N + i] = c;
        u = uf1[u], v = uf1[v];
        G1.add_edge(p1[u], N + i), G1.add_edge(p1[v], N + i);
        uf1.unite(u, v);
        p1[uf1[u]] = N + i;
    }
    G1.build(2 * N - 2);

    rep(i, N - 1) {
        auto [t, u, v] = es2[i];
        G2.c[N + i] = t;
        u = uf2[u], v = uf2[v];
        G2.add_edge(p2[u], N + i), G2.add_edge(p2[v], N + i);
        uf2.unite(u, v);
        p2[uf2[u]] = N + i;
    }
    G2.build(2 * N - 2);

    auto f = [](pii a, pii b) { return max(a, b); };
    vector<pii> v1(2 * N - 1), v2(2 * N - 1);
    rep(i, N) {
        v1[G1.ls[i]] = make_pair(a[i], G2.ls[i]);
        v2[G1.ls[i]] = make_pair(a[i], -G2.ls[i]);
    }
    Segment_Tree<pii> seg1(v1, f, pii(-inf, -inf)), seg2(v2, f, pii(-inf, -inf));

    vector<int> ord(2 * N - 1);
    rep(i, N) ord[G2.ls[i]] = i;

    while (Q--) {
        int x, u;
        cin >> x >> u;
        u--;

        int p = u;
        rep3(i, G1.height - 1, 0) {
            int np = G1.par[i][p];
            if (np != -1 && G1.c[np] >= x) p = np;
        }

        pii l = seg1.query(G1.ls[p], G1.rs[p]);
        pii r = seg2.query(G1.ls[p], G1.rs[p]);

        int ans = max(G2.c[G2.lca(u, ord[l.second])], G2.c[G2.lca(u, ord[-r.second])]);
        cout << l.first << ' ' << ans << '\n';
    }
}