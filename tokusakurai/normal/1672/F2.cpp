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

template <bool directed = true>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    Graph(int n) : es(n), n(n), m(0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }
};

template <bool directed = true>
struct Strongly_Connected_Components {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es, rs;
    vector<int> vs;
    vector<int> comp;
    const int n;
    int m;

    Strongly_Connected_Components(int n) : es(n), rs(n), comp(n), n(n), m(0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m), rs[to].emplace_back(from, m);
        if (!directed) es[to].emplace_back(from, m), rs[from].emplace_back(to, m);
        m++;
    }

    void _dfs(int now) {
        if (comp[now] != -1) return;
        comp[now] = 1;
        for (auto &e : es[now]) _dfs(e.to);
        vs.push_back(now);
    }

    void _rdfs(int now, int col) {
        if (comp[now] != -1) return;
        comp[now] = col;
        for (auto &e : rs[now]) _rdfs(e.to, col);
    }

    Graph<true> decompose() {
        fill(begin(comp), end(comp), -1);
        for (int i = 0; i < n; i++) {
            if (comp[i] == -1) _dfs(i);
        }
        fill(begin(comp), end(comp), -1);
        reverse(begin(vs), end(vs));
        int cnt = 0;
        for (auto &e : vs) {
            if (comp[e] == -1) _rdfs(e, cnt++);
        }
        Graph<true> G(cnt);
        for (int i = 0; i < n; i++) {
            for (auto &e : es[i]) {
                int u = comp[i], v = comp[e.to];
                if (u != v) G.add_edge(u, v);
            }
        }
        return G;
    }

    int operator[](int k) const { return comp[k]; }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N), b(N);
        rep(i, N) {
            cin >> a[i];
            a[i]--;
        }
        rep(i, N) {
            cin >> b[i];
            b[i]--;
        }

        vector<int> cnt(N, 0);
        rep(i, N) cnt[a[i]]++;
        int K = max_element(all(cnt)) - begin(cnt);

        Strongly_Connected_Components G(N + 1);
        bool flag = true;

        rep(i, N) {
            if (b[i] != K) {
                G.add_edge(a[i], b[i]);
                if (a[i] == b[i]) flag = false;
            } else {
                G.add_edge(a[i], N);
            }
        }

        if (!flag) {
            cout << "WA\n";
            continue;
        }

        cout << (G.decompose().n == N + 1 ? "AC\n" : "WA\n");
    }
}