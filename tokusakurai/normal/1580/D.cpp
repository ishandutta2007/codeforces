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

template <typename T>
vector<int> cartesian_tree(const vector<T> &a) {
    int n = a.size();
    stack<int> st;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        int pre = -1;
        while (!st.empty() && a[i] < a[st.top()]) {
            pre = st.top();
            st.pop();
        }
        if (pre != -1) p[pre] = i;
        if (!st.empty()) p[i] = st.top();
        st.push(i);
    }
    return p;
}

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<vector<ll>> dp;
    vector<ll> a;

    Graph(int n) : es(n), n(n), m(0), dp(n, vector<ll>(n + 1, -INF)) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    int dfs(int now, int k) {
        int s = 0;
        dp[now][0] = 0;
        each(e, es[now]) {
            int t = dfs(e.to, k);
            rep3(i, s, 0) {
                rep3(j, t, 0) {
                    ll x = i * j;
                    chmax(dp[now][i + j], dp[now][i] + dp[e.to][j] - a[now] * x * 2);
                }
            }
            s += t;
        }
        rep3(i, s, 0) chmax(dp[now][i + 1], dp[now][i] + (k - 2 * i - 1) * a[now]);
        return s + 1;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<int> p = cartesian_tree(a);
    Graph<true> G(N);
    int root = -1;
    rep(i, N) {
        if (p[i] != -1) {
            G.add_edge(p[i], i);
        } else {
            root = i;
        }
    }
    G.a = a;

    G.dfs(root, M);
    cout << G.dp[root][M] << '\n';
}