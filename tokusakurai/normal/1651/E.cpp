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

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> used;

    Graph(int n) : es(n), n(n), m(0), used(n, 0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    vector<int> ret_path;

    bool detect_path(int now, int t, bool use_id = false) {
        used[now] = true;
        if (now == t) {
            if (!use_id) ret_path.push_back(now);
            return true;
        }
        for (auto &e : es[now]) {
            if (used[e.to]) continue;
            if (detect_path(e.to, t, use_id)) {
                ret_path.push_back(use_id ? e.id : now);
                return true;
            }
        }
        return false;
    }

    vector<int> find_path(int s, int t, bool use_id = false) { //  s-t 1
        ret_path.clear(), fill(begin(used), end(used), 0);
        detect_path(s, t, use_id);
        reverse(begin(ret_path), end(ret_path));
        return ret_path;
    }

    vector<int> ret_cycle;

    int detect_cycle(int now, int pre = -1, bool use_id = false) {
        if (used[now]++) return 1;
        for (auto &e : es[now]) {
            if (e.id == pre) continue;
            int k = detect_cycle(e.to, e.id, use_id);
            if (k == 2) return 2;
            if (k == 1) {
                ret_cycle.push_back(use_id ? e.id : now);
                return used[now];
            }
        }
        return 0;
    }

    vector<int> find_cycle(int s, bool use_id = false) { // 1
        ret_cycle.clear();
        detect_cycle(s, -1, use_id);
        if (!ret_cycle.empty()) {
            reverse(begin(ret_cycle), end(ret_cycle));
            return ret_cycle;
        }
        return {};
    }
};

int main() {
    int N;
    cin >> N;

    Graph G(2 * N);
    rep(i, 2 * N) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G.add_edge(x, y);
    }

    vector<bool> used(2 * N, false);
    ll ans = 0;

    rep(i, N) {
        if (used[i]) continue;
        vector<int> v = G.find_cycle(i);
        int K = sz(v);

        for (int s = 0; s < K; s += 2) {
            int a = inf, b = -inf, c = inf, d = -inf;
            for (int j = 0; j < K; j++) {
                int t = (s + j) % K;
                if (j & 1) {
                    chmin(c, v[t]), chmax(d, v[t]);
                } else {
                    chmin(a, v[t]), chmax(b, v[t]);
                    ll tmp = (a + 1) * (N - b);
                    int l = v[(s + K - 1) % K], r = v[(t + 1) % K];
                    if (l > r) swap(l, r);

                    if (j == 0) {
                        ll d1 = l - N, d2 = r - l - 1, d3 = 2 * N - r - 1;
                        ans -= tmp * (d1 * (d1 + 1) / 2 + d2 * (d2 + 1) / 2 + d3 * (d3 + 1) / 2);
                    } else {
                        if (d < l) ans -= tmp * (c - N + 1) * (l - d);
                        if (l < c && d < r) ans -= tmp * (c - l) * (r - d);
                        if (r < c) ans -= tmp * (c - r) * (2 * N - d);
                    }
                }
            }
        }

        // print(v);
        each(e, v) used[e] = true;
    }

    rep2(i, 0, N - 1) {
        rep2(j, i, N - 1) {
            ll tmp = N * (N + 1) / 2;
            ans += tmp * (j - i + 1);
        }
    }

    cout << ans << '\n';
}