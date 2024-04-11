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

template <typename T, bool directed = false>
struct Dijkstra {
    struct edge {
        int to;
        T cost;
        int id;
        edge(int to, T cost, int id) : to(to), cost(cost), id(id) {}
    };

    vector<vector<edge>> es;
    vector<T> d;
    vector<int> pre_v, pre_e;
    const T zero_T, INF_T;
    const int n;
    int m;

    Dijkstra(int n, T zero_T = 0, T INF_T = numeric_limits<T>::max() / 2) : es(n), d(n), pre_v(n), pre_e(n), zero_T(zero_T), INF_T(INF_T), n(n), m(0) {}

    void add_edge(int from, int to, T cost) {
        es[from].emplace_back(to, cost, m);
        if (!directed) es[to].emplace_back(from, cost, m);
        m++;
    }

    int shortest_path(int s, vector<T> c) {
        int ans = n - 1;
        vector<int> f(n, 1);
        d = c;
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        rep(i, n) que.emplace(d[i], i);
        while (!que.empty()) {
            auto [p, i] = que.top();
            que.pop();
            if (p > d[i]) continue;
            for (auto &e : es[i]) {
                if (d[i] + e.cost <= d[e.to]) {
                    ans -= f[e.to];
                    f[e.to] = 0;
                }
                if (d[i] + e.cost < d[e.to]) {
                    pre_v[e.to] = i, pre_e[e.to] = e.id;
                    que.emplace(d[e.to] = d[i] + e.cost, e.to);
                }
            }
        }
        return ans;
    }

    vector<int> restore_path(int s, int t, bool use_id = false) {
        if (d[t] == INF_T) return {};
        vector<int> ret;
        for (int now = t; now != s; now = pre_v[now]) ret.push_back(use_id ? pre_e[now] : now);
        if (!use_id) ret.push_back(s);
        reverse(begin(ret), end(ret));
        return ret;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    Dijkstra<ll> G(N);
    rep(i, M) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--, v--;
        G.add_edge(u, v, c);
    }

    vector<ll> d(N, INF);
    rep(i, K) {
        int u;
        ll c;
        cin >> u >> c;
        u--;
        chmin(d[u], c);
    }
    d[0] = 0;

    cout << K - G.shortest_path(0, d) << '\n';
}