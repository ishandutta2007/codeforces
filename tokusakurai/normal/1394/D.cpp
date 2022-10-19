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

    vector<int> a, c;
    vector<ll> t;
    vector<bool> used;
    ll ans = 0;

    Graph(int n) : es(n), n(n), m(0), a(n), c(n, 0), t(n), used(n, false) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void calc(int now) {
        each(e, es[now]) {
            if (a[now] > a[e.to]) {
                c[now]++;
            } else {
                c[now]--;
            }
        }
        ans += (sz(es[now]) + 1) / 2 * t[now];
    }

    pll dfs(int now) {
        used[now] = true;
        vector<ll> d;
        ll s = 0;
        each(e, es[now]) {
            if (used[e.to]) continue;
            if (a[e.to] != a[now]) continue;
            auto [p, q] = dfs(e.to);
            s += p;
            d.eb(q - p);
        }
        sort(all(d));
        int K = sz(d);
        ll np = INF, nq = INF;
        rep2(i, 0, K) {
            chmin(np, s + abs(c[now] + 2 * (K - i)) / 2 * t[now]);
            chmin(nq, s + abs(c[now] + 2 * (K - i + 1)) / 2 * t[now]);
            if (i < K) s += d[i];
        }
        // cout << now << ' ' << np << ' ' << nq << '\n';
        return pll(np, nq);
    }

    void solve() {
        rep(i, n) calc(i);
        // print(c);
        // cout << ans << '\n';
        rep(i, n) {
            if (!used[i]) ans += dfs(i).first;
        }
        cout << ans << '\n';
    }
};

int main() {
    int N;
    cin >> N;

    Graph G(N);

    rep(i, N) cin >> G.t[i];
    rep(i, N) cin >> G.a[i];

    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    G.solve();
}