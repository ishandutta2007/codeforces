#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

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
    if (v.empty()) cout << '\n';
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

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
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
// const int MOD = 1000000007;
const int MOD = 998244353;

template <bool directed = false>
struct Lowest_Common_Ancestor {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<vector<int>> par; // par[i][j] :=  j  2^i 
    vector<int> depth;
    const int n;
    int height, m;

    vector<vector<int>> ma;
    vector<vector<int>> dp1, dp2;

    Lowest_Common_Ancestor(int n) : es(n), depth(n), n(n), m(0), ma(n, vector<int>(3, 0)) {
        height = 1;
        while ((1 << height) < n) height++;
        height++;
        par.assign(height, vector<int>(n));
        dp1.assign(height, vector<int>(n, -inf));
        dp2.assign(height, vector<int>(n, -inf));
    }

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void prepare(int now, int pre = -1) {
        if (pre == -1) depth[now] = 0;
        par[0][now] = pre;
        for (auto &e : es[now]) {
            if (e.to != pre) {
                depth[e.to] = depth[now] + 1;
                prepare(e.to, now);
            }
        }
    }

    int dfs(int now, int pre = -1) {
        int L = sz(es[now]);
        vector<int> ds(L, 0);
        rep(i, L) {
            auto e = es[now][i];
            if (e.to != pre) ds[i] = dfs(e.to, now);
        }
        vector<int> l = ds, r = ds;
        rep2(i, 1, L) chmax(l[i], l[i - 1]);
        per2(i, 1, L) chmax(r[i - 1], r[i]);
        rep(i, L) {
            auto e = es[now][i];
            if (e.to != pre) {
                int tmp = 0;
                if (i > 0) chmax(tmp, l[i - 1]);
                if (i < L - 1) chmax(tmp, r[i + 1]);
                dp1[0][e.to] = tmp + 1;
                dp2[0][e.to] = tmp;
            }
        }
        sort(rall(ds));
        rep(i, min(L, 3)) ma[now][i] = ds[i];
        return ma[now][0] + 1;
    }

    void build(int root = 0) {
        prepare(root);
        dfs(root);
        for (int j = 0; j < height - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (par[j][i] == -1) {
                    par[j + 1][i] = -1;
                    dp1[j + 1][i] = dp1[j][i];
                    dp2[j + 1][i] = dp2[j][i];
                } else {
                    par[j + 1][i] = par[j][par[j][i]];
                    dp1[j + 1][i] = max(dp1[j][i], (1 << j) + dp1[j][par[j][i]]);
                    dp2[j + 1][i] = max((1 << j) + dp2[j][i], dp2[j][par[j][i]]);
                }
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int i = height - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }

    int dist(int u, int v) { return depth[u] + depth[v] - depth[lca(u, v)] * 2; }

    // u  k 
    int ancestor(int u, int k) {
        if (k > depth[u]) return -1;
        for (int i = 0; i < height; i++) {
            if ((k >> i) & 1) u = par[i][u];
        }
        return u;
    }

    // u  v  k 
    int move(int u, int v, int k) {
        int w = lca(u, v);
        int l = depth[u] + depth[v] - depth[w] * 2;
        if (k > l) return -1;
        if (k <= depth[u] - depth[w]) return ancestor(u, k);
        return ancestor(v, l - k);
    }

    int solve(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int w = lca(u, v);
        int d1 = depth[u] - depth[w], d2 = depth[v] - depth[w];
        int d = d1 + d2;
        int ret = ma[u][0];
        {
            int x = (d - 1) / 2, tmp = 0;
            rep(i, height) {
                if (flg(x, i)) {
                    chmax(ret, tmp + dp1[i][u]);
                    u = par[i][u];
                    tmp += (1 << i);
                }
            }
        }
        assert(u != w);
        if (v != w) {
            chmax(ret, ma[v][0]);
            int x = depth[v] - depth[w] - 1, tmp = 0;
            rep(i, height) {
                if (flg(x, i)) {
                    chmax(ret, tmp + dp1[i][v]);
                    v = par[i][v];
                    tmp += (1 << i);
                }
            }
        }
        {
            int x = depth[u] - depth[w] - 1;
            int tmp = d2 + depth[u] - depth[w];
            rep(i, height) {
                if (flg(x, i)) {
                    tmp -= (1 << i);
                    chmax(ret, tmp + dp2[i][u]);
                    u = par[i][u];
                }
            }
        }
        vector<int> a(2, 0);
        a[0] = ma[u][0] + 1;
        if (v != w) a[1] = ma[v][0] + 1;
        sort(rall(a));
        if (a[0] < ma[w][0]) {
            chmax(ret, ma[w][0] + d2);
        } else if (a[1] < ma[w][1]) {
            chmax(ret, ma[w][1] + d2);
        } else {
            chmax(ret, ma[w][2] + d2);
        }
        chmax(ret, dp1.back()[w] + d2);

        return ret;
    }
};

int main() {
    int N;
    cin >> N;

    Lowest_Common_Ancestor G(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    G.build(0);

    int Q;
    cin >> Q;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << G.solve(u, v) << '\n';
    }
}