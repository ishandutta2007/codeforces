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

template <typename F> // 
struct Dinic {
    struct edge {
        int to;
        F cap;
        int rev;
        edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> es;
    vector<int> d, pos;
    const F zero_F, INF_F;
    const int n;

    Dinic(int n, F zero_F = 0, F INF_F = numeric_limits<F>::max() / 2) : es(n), d(n), pos(n), zero_F(zero_F), INF_F(INF_F), n(n) {}

    void add_edge(int from, int to, F cap, bool directed = true) {
        es[from].emplace_back(to, cap, (int)es[to].size());
        es[to].emplace_back(from, directed ? zero_F : cap, (int)es[from].size() - 1);
    }

    bool _bfs(int s, int t) {
        fill(begin(d), end(d), -1);
        queue<int> que;
        d[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            for (auto &e : es[i]) {
                if (e.cap > zero_F && d[e.to] == -1) {
                    d[e.to] = d[i] + 1;
                    que.push(e.to);
                }
            }
        }
        return d[t] != -1;
    }

    F _dfs(int now, int t, F flow) {
        if (now == t) return flow;
        for (int &i = pos[now]; i < (int)es[now].size(); i++) {
            edge &e = es[now][i];
            if (e.cap > zero_F && d[e.to] > d[now]) {
                F f = _dfs(e.to, t, min(flow, e.cap));
                if (f > zero_F) {
                    e.cap -= f;
                    es[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }
        return zero_F;
    }

    F max_flow(int s, int t) { //  d  1 0  s -1  t 
        F flow = zero_F;
        while (_bfs(s, t)) {
            fill(begin(pos), end(pos), 0);
            F f = zero_F;
            while ((f = _dfs(s, t, INF_F)) > zero_F) flow += f;
        }
        return flow;
    }
};

ll calc(ll a, ll b, ll c, ll x) {
    return a * x * x + b * x + c; //
}

int main() {
    int N, M;
    cin >> N >> M;

    int K = 100;
    Dinic<ll> G(2 * N * K + 2);
    int s = 2 * N * K, t = s + 1;

    ll ans = 0;

    rep(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        ans += calc(a, b, c, -K);
        G.add_edge(2 * K * i, s, INF);
        rep(j, 2 * K - 1) G.add_edge(2 * K * i + j + 1, 2 * K * i + j, INF);
        G.add_edge(t, 2 * K * (i + 1) - 1, INF);
        rep(j, 2 * K) {
            ll bonus = calc(a, b, c, -K + j + 1) - calc(a, b, c, -K + j);
            if (bonus > 0) {
                ans += bonus;
                G.add_edge(s, 2 * K * i + j, bonus);
            } else {
                G.add_edge(2 * K * i + j, t, -bonus);
            }
        }
    }

    rep(i, N) {
        int l, r;
        cin >> l >> r;
        if (l > -K) {
            int x = l + K - 1;
            G.add_edge(s, 2 * K * i + x, INF);
        }
        if (r < K) {
            int x = r + K;
            G.add_edge(2 * K * i + x, t, INF);
        }
    }

    rep(i, M) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        rep2(j, 0, 2 * K + 1) {
            if (j - d <= 0) continue;
            int a = (j == 0 ? s : 2 * K * u + j - 1);
            if (j - d > 2 * K) {
                G.add_edge(a, t, INF);
            } else {
                int b = 2 * K * v + j - d - 1;
                G.add_edge(a, b, INF);
            }
        }
    }

    ans -= G.max_flow(s, t);
    cout << ans << '\n';
}