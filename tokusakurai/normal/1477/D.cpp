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

    vector<int> a, b;
    int c;
    vector<bool> used;

    Graph(int n) : es(n), n(n), m(0), a(n, -1), b(n, -1), c(0), used(n, false) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    int dfs(int now, int pre = -1) {
        vector<int> tmp;
        int last = -1;
        used[now] = true;

        each(e, es[now]) {
            if (e.to == pre) continue;
            if (dfs(e.to, now)) tmp.eb(e.to);
            last = e.to;
        }

        if (empty(tmp)) {
            if (pre == -1) {
                if (last == -1) {
                    a[now] = c, b[now] = c;
                    c++;
                } else {
                    a[now] = c, b[now] = c;
                    swap(b[now], b[last]);
                    c++;
                }
                return 0;
            }
            return 1;
        }

        int k = sz(tmp);

        a[now] = c, b[now] = c + k;
        rep(i, k) a[tmp[i]] = c + 1 + i, b[tmp[i]] = c + i;
        c += k + 1;

        return 0;
    }

    void solve() {
        rep(i, n) {
            if (!used[i]) dfs(i);
        }
        print(a, 1), print(b, 1);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> es(N);
        rep(i, M) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            es[u].eb(v), es[v].eb(u);
        }

        rep(i, N) sort(all(es[i]));

        set<int> s;
        rep(i, N) s.emplace(i);
        Graph G(N);

        rep(i, N) {
            if (!s.count(i)) continue;
            s.erase(i);
            queue<int> que;
            que.emplace(i);
            while (!empty(que)) {
                int j = que.front();
                que.pop();
                int ptr = 0;
                for (auto it = begin(s); it != end(s);) {
                    int e = *it;
                    while (ptr < sz(es[j]) && es[j][ptr] < e) ptr++;
                    if (ptr < sz(es[j]) && es[j][ptr] == e) {
                        it++;
                    } else {
                        // cout << j << ' ' << e << '\n';
                        G.add_edge(j, e);
                        que.emplace(e);
                        it = s.erase(it);
                    }
                }
            }
        }

        G.solve();
    }
}