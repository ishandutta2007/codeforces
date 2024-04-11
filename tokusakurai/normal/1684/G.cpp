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

struct Hopcroft_Karp {
    vector<vector<int>> es;
    vector<int> d, match;
    vector<bool> used, used2;
    const int n, m;

    Hopcroft_Karp(int n, int m) : es(n), d(n), match(m), used(n), used2(n), n(n), m(m) {}

    void add_edge(int u, int v) { es[u].push_back(v); }

    void _bfs() {
        fill(begin(d), end(d), -1);
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                que.push(i);
                d[i] = 0;
            }
        }
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            for (auto &e : es[i]) {
                int j = match[e];
                if (j != -1 && d[j] == -1) {
                    que.push(j);
                    d[j] = d[i] + 1;
                }
            }
        }
    }

    bool _dfs(int now) {
        used2[now] = true;
        for (auto &e : es[now]) {
            int u = match[e];
            if (u == -1 || (!used2[u] && d[u] == d[now] + 1 && _dfs(u))) {
                match[e] = now, used[now] = true;
                return true;
            }
        }
        return false;
    }

    int max_matching() { //  i  match[i] 
        fill(begin(match), end(match), -1), fill(begin(used), end(used), false);
        int ret = 0;
        while (true) {
            _bfs();
            fill(begin(used2), end(used2), false);
            int flow = 0;
            for (int i = 0; i < n; i++) {
                if (!used[i] && _dfs(i)) flow++;
            }
            if (flow == 0) break;
            ret += flow;
        }
        return ret;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    Hopcroft_Karp G(N, N);
    int K = 0;

    rep(i, N) {
        if (2 * a[i] >= M) {
            cout << "-1\n";
            return 0;
        } else if (3 * a[i] > M) {
            rep(j, N) {
                if (a[i] % a[j] == 0 && a[j] <= M - 2 * a[i]) {
                    G.add_edge(i, j); //
                }
            }
            K++;
        }
    }

    if (G.max_matching() != K) {
        cout << "-1\n";
        return 0;
    }

    vector<bool> used(N, false);
    vector<pii> ans;

    rep(i, N) {
        int j = G.match[i];
        if (j != -1) {
            used[i] = true;
            used[j] = true;
            ans.eb(a[i] + a[j], a[i] + 2 * a[j]);
        }
    }

    rep(i, N) {
        if (!used[i]) ans.eb(2 * a[i], 3 * a[i]);
    }

    cout << sz(ans) << '\n';
    each(e, ans) cout << e << '\n';
}