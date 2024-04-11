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
struct Warshall_Floyd {
    vector<vector<T>> es;
    const T zero_T, INF_T;
    const int n;

    inline const vector<T> &operator[](int k) const { return es[k]; }

    inline vector<T> &operator[](int k) { return es[k]; }

    Warshall_Floyd(int n, T zero_T = 0, T INF_T = numeric_limits<T>::max() / 2) : es(n, vector<T>(n)), zero_T(zero_T), INF_T(INF_T), n(n) {
        for (int i = 0; i < n; i++) fill(begin(es[i]), end(es[i]), INF_T);
        for (int i = 0; i < n; i++) es[i][i] = zero_T;
    }

    void add_edge(int from, int to, T cost = 1) {
        es[from][to] = min(es[from][to], cost);
        if (!directed) es[to][from] = min(es[to][from], cost);
    }

    vector<vector<T>> shortest_path() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (es[i][k] == INF_T || es[k][j] == INF_T) continue;
                    es[i][j] = min(es[i][j], es[i][k] + es[k][j]);
                }
            }
        }
        return es;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<tuple<ll, int, int>> es;
        vector<vector<int>> d(N, vector<int>(N, inf));
        rep(i, N) d[i][i] = 0;
        rep(i, M) {
            int u, v;
            ll c;
            cin >> u >> v >> c;
            u--, v--;
            d[u][v] = 1, d[v][u] = 1;
            es.eb(c, u, v);
        }

        rep(k, N) {
            rep(i, N) {
                rep(j, N) {
                    if (d[i][k] == inf || d[k][j] == inf) continue;
                    chmin(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        // rep(i, N) print(d[i]);

        ll ans = INF;
        each(e, es) {
            auto [c, u, v] = e;
            chmin(ans, c * (d[0][u] + d[v][N - 1] + 1));
            chmin(ans, c * (d[0][v] + d[u][N - 1] + 1));
            rep(i, N) {
                chmin(ans, c * (d[0][i] + d[i][N - 1] + max(d[i][u], d[i][v]) + 1)); //
            }
        }

        cout << ans << '\n';
    }
}