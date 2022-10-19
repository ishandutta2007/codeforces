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

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> d, p;
    vector<bool> used;

    Graph(int n) : es(n), n(n), m(0), d(n, 0), p(n, -1), used(n, false) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now) {
        used[now] = true;
        each(e, es[now]) {
            if (used[e.to]) continue;
            d[e.to] = d[now] + 1;
            p[e.to] = now;
            dfs(e.to);
        }
    }

    vector<int> find_path(int u, int v) {
        // cout << u + 1 << ' ' << v + 1 << '\n';
        vector<int> a, b;
        while (u != v) {
            if (d[u] > d[v]) {
                a.eb(u);
                u = p[u];
            } else {
                b.eb(v);
                v = p[v];
            }
        }
        // reverse(all(a));
        a.eb(u);
        reverse(all(b));
        each(e, b) a.eb(e);

        // print(a, 1);
        return a;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    G.dfs(0);

    int Q;
    cin >> Q;

    vector<int> c(N, 0);
    vector<vector<int>> ps(Q);

    rep(i, Q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        c[u] ^= 1, c[v] ^= 1;
        ps[i] = G.find_path(u, v);
    }

    int S = accumulate(all(c), 0);

    if (S == 0) {
        cout << "YES\n";
        rep(i, Q) {
            cout << sz(ps[i]) << '\n';
            print(ps[i], 1);
        }
    } else {
        cout << "NO\n";
        cout << S / 2 << '\n';
    }
}