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

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;

    vector<int> dp;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n), dp(n) {}

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
        int tmp = (dp[x] + 1) / 2 + (dp[y] + 1) / 2 + 1;
        chmax(dp[x], dp[y]);
        chmax(dp[x], tmp);
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

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> d, si;

    Graph(int n) : es(n), n(n), m(0), d(n), si(n) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void calc_depth(int now, vector<int> &vs, int pre = -1) {
        vs.eb(now);
        if (pre == -1) d[now] = 0;
        for (auto &e : es[now]) {
            if (e.to != pre) d[e.to] = d[now] + 1, calc_depth(e.to, vs, now);
        }
    }

    int calc_size(int now, int pre = -1) {
        si[now] = 1;
        for (auto &e : es[now]) {
            if (e != pre) si[now] += calc_size(e.to, now);
        }
        return si[now];
    }

    int farthest_point(int s) {
        vector<int> vs;
        calc_depth(s, vs);
        int max_d = -1, t = -1;
        each(e, vs) {
            if (d[e] > max_d) max_d = d[e], t = e;
        }
        return t;
    }

    pair<int, pair<int, int>> diameter(int u) {
        int a = farthest_point(u), b = farthest_point(a);
        return make_pair(d[b], make_pair(a, b));
    }

    vector<int> ret_path;

    bool detect_path(int now, int t, bool use_id = false, int pre = -1) {
        if (now == t) {
            if (!use_id) ret_path.push_back(now);
            return true;
        }
        for (auto &e : es[now]) {
            if (e.to == pre) continue;
            if (detect_path(e.to, t, use_id, now)) {
                ret_path.push_back(use_id ? e.id : now);
                return true;
            }
        }
        return false;
    }

    vector<int> find_path(int s, int t, bool use_id = false) {
        ret_path.clear();
        detect_path(s, t, use_id);
        reverse(begin(ret_path), end(ret_path));
        return ret_path;
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    Graph G(N);
    Union_Find_Tree uf(N);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.unite(u, v);
        G.add_edge(u, v);
    }

    rep(i, N) {
        if (uf[i] != i) continue;
        uf.dp[i] = G.diameter(i).first;
    }

    while (Q--) {
        int t;
        cin >> t;

        if (t == 2) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            uf.unite(u, v);
        } else {
            int u;
            cin >> u;
            u--;
            cout << uf.dp[uf[u]] << '\n';
        }
    }
}