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

template <typename T, bool directed = false>
struct Weighted_Graph {
    struct edge {
        int to;
        T cost;
        int id;
        edge(int to, T cost, int id) : to(to), cost(cost), id(id) {}
    };

    vector<vector<edge>> es;
    const T INF_T = numeric_limits<T>::max() / 2;
    const int n;
    int m;

    vector<vector<int>> par; // par[i][j] :=  j  2^i 
    vector<int> depth;
    vector<bool> used;
    vector<T> d;
    int height;

    Weighted_Graph(int n) : es(n), n(n), m(0), depth(n, 0), used(n, false), d(n, 0) {
        height = 1;
        while ((1 << height) < n) height++;
        par.assign(height, vector<int>(n));
    }

    void add_edge(int from, int to, T cost) {
        es[from].emplace_back(to, cost, m);
        if (!directed) es[to].emplace_back(from, cost, m);
        m++;
    }

    void prepare(int now, int pre = -1) {
        if (pre == -1) depth[now] = 0, d[now] = 0;
        par[0][now] = pre;
        used[now] = true;
        for (auto &e : es[now]) {
            if (e.to != pre) {
                depth[e.to] = depth[now] + 1;
                d[e.to] = d[now] + e.cost;
                prepare(e.to, now);
            }
        }
    }

    void build(int root = 0) {
        rep(i, n) {
            if (!used[i]) prepare(i);
        }
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

    T dist(int u, int v) { return d[u] + d[v] - 2 * d[lca(u, v)]; }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> S(2);
    rep(i, 2) cin >> S[i];

    Union_Find_Tree uf(2 * N);

    Weighted_Graph<int> G(2 * N);
    vector<int> L(2 * N), R(2 * N);
    vector<int> id(2 * N, -1); // 
    vector<bool> used(2 * N, false);

    iota(all(id), 0);

    for (int i = 0; i < N;) {
        if (S[0][i] == 'X' && S[1][i] == 'X') {
            i++;
            continue;
        } else if (S[0][i] == '.' && S[1][i] == '.') {
            int j = 0;
            while (i + j < N && S[0][i + j] == '.' && S[1][i + j] == '.') j++;
            int x = i, y = N + i; // 
            L[x] = i, R[x] = i + j - 1;
            L[y] = i, R[y] = i + j - 1;
            rep(k, j) {
                id[i + k] = x;
                id[N + i + k] = y;
            }
            i += j;
        } else {
            i++;
        }
    }

    // rep(i, 2) {
    //     rep(j, N) cout << id[N * i + j] << ' ';
    //     cout << '\n';
    // }

    rep(i, 2) {
        rep(j, N) {
            if (j < N - 1) {
                if (S[i][j] == '.' && S[i][j + 1] == '.') {
                    int a = N * i + j, b = N * i + j + 1;
                    uf.unite(a, b);
                    if (id[a] != id[b]) G.add_edge(id[a], id[b], 0);
                }
            }
            if (i < 1) {
                if (S[i][j] == '.' && S[i + 1][j] == '.') {
                    int a = N * i + j, b = N * (i + 1) + j;
                    uf.unite(a, b);
                    if (id[a] != id[b] && !used[id[a]]) {
                        G.add_edge(id[a], id[b], 1);
                        used[id[a]] = true;
                        used[id[b]] = true;
                    }
                }
            }
        }
    }

    G.build();

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (!uf.same(u, v)) {
            cout << "-1\n";
            continue;
        }

        cout << G.dist(id[u], id[v]) + abs(u % N - v % N) << '\n';
    }
}