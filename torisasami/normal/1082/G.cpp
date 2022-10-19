#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define REP(i, l, r) for (ll i = l; i < (r); i++)
#define REP2(i, l, r) for (ll i = (ll)r - 1; i >= (l); i--)
#define siz(x) (ll) x.size()
template <class T>
using rque = priority_queue<T, vector<T>, greater<T>>;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
void print(vector<T> a) {
    if (a.empty())
        cout << '\n';
    else {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 == a.size() ? '\n' : ' ');
    }
}

// __int128_t gcd(__int128_t a, __int128_t b) {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
//     __int128_t cnt = a % b;
//     while (cnt != 0) {
//         a = b;
//         b = cnt;
//         cnt = a % b;
//     }
//     return b;
// }

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

struct UnionFind {
    vector<ll> data;
    int num;

    UnionFind(int sz) {
        data.assign(sz, -1);
        num = sz;
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        num--;
        return (true);
    }

    int find(int k) {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    ll size(int k) {
        return (-data[find(k)]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int operator[](int k) {
        return find(k);
    }
};

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {
    }

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    static int get_mod() {
        return mod;
    }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() {
        return *this += Mod_Int(1);
    }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() {
        return *this -= Mod_Int(1);
    }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const {
        return Mod_Int(-x);
    }

    Mod_Int operator+(const Mod_Int &p) const {
        return Mod_Int(*this) += p;
    }

    Mod_Int operator-(const Mod_Int &p) const {
        return Mod_Int(*this) -= p;
    }

    Mod_Int operator*(const Mod_Int &p) const {
        return Mod_Int(*this) *= p;
    }

    Mod_Int operator/(const Mod_Int &p) const {
        return Mod_Int(*this) /= p;
    }

    bool operator==(const Mod_Int &p) const {
        return x == p.x;
    }

    bool operator!=(const Mod_Int &p) const {
        return x != p.x;
    }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1)
                ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

ll mpow2(ll x, ll n, ll mod) {
    ll ans = 1;
    x %= mod;
    while (n != 0) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}

ll modinv2(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0)
        u += mod;
    return u;
}

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = Mod_Int<mod>;

mint mpow(mint x, ll n) {
    mint ans = 1;
    while (n != 0) {
        if (n & 1)
            ans *= x;
        x *= x;
        n = n >> 1;
    }
    return ans;
}

// ----- library -------
template <typename flow_t>
struct Dinic {
    const flow_t INF;

    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> min_cost, iter;

    Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {
    }

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back((edge){to, cap, (int)graph[to].size(), false, idx});
        graph[to].emplace_back((edge){from, 0, (int)graph[from].size() - 1, true, idx});
    }

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for (auto &e : graph[p]) {
                if (e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if (idx == t)
            return flow;
        for (int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while (bfs(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
        return flow;
    }

    vector<pair<pair<int, int>, int>> get_edges() {
        vector<pair<pair<int, int>, int>> E;
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev)
                    continue;
                auto &rev_e = graph[e.to][e.rev];
                E.emplace_back(mp(mp(i, e.to), rev_e.cap));
            }
        }
        return E;
    }

    void output() {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev)
                    continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }

    vector<pair<int, int>> get_cut() {
        int n = graph.size();
        vector<vector<int>> li(n);
        for (int i = 0; i < n; i++) {
            for (auto &e : graph[i]) {
                if (e.cap)
                    li[i].emplace_back(e.to);
            }
        }
        vector<int> fv(n, 0);
        queue<int> que;
        que.push(0);
        fv[0] = 1;
        while (!que.empty()) {
            auto q = que.front();
            que.pop();
            for (auto e : li[q]) {
                if (!fv[e]) {
                    que.push(e);
                    ;
                    fv[e] = 1;
                }
            }
        }
        vector<pair<int, int>> ret;
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev)
                    continue;
                if (fv[i] && !fv[e.to])
                    ret.emplace_back(i, e.to);
            }
        }
        return ret;
    }
};

template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using phi_ls_t = vv<pair<int, vv<T>>>;

// O((kN)^4)
template <typename flow_t>
flow_t k_Option_ProjectSelectionProblem(const vv<flow_t> &theta, const vv<vv<flow_t>> &phi) {
    int n = theta.size();
    vector<int> ks(n), sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        ks[i] = theta[i].size();
        sum[i + 1] = sum[i] + ks[i] - 1;
    }
    Dinic<flow_t> mf(sum[n] + 2);
    flow_t ans = 0;
    const flow_t INF = numeric_limits<flow_t>::max();
    map<pair<int, int>, flow_t> md;
    for (int i = 0; i < n; i++)
        ans += theta[i][ks[i] - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ks[i] - 2; j++)
            md[{sum[i] + j + 1, sum[i] + j}] += INF;
        for (int j = 0; j < ks[i] - 1; j++) {
            if (theta[i][j] > theta[i][j + 1])
                md[{sum[n], sum[i] + j}] += theta[i][j] - theta[i][j + 1];
            else {
                ans -= theta[i][j + 1] - theta[i][j];
                md[{sum[i] + j, sum[n] + 1}] += theta[i][j + 1] - theta[i][j];
            }
        }
        for (int j = i + 1; j < n; j++) {
            ans += phi[i][j][0][0];
            for (int s = 0; s < ks[i] - 1; s++) {
                flow_t d = phi[i][j][s + 1][0] - phi[i][j][s][0];
                if (d > 0)
                    md[{sum[i] + s, sum[n] + 1}] += d;
                else {
                    ans += d;
                    md[{sum[n], sum[i] + s}] += -d;
                }
            }
            for (int s = 0; s < ks[j] - 1; s++) {
                flow_t d = phi[i][j][0][s + 1] - phi[i][j][0][s];
                if (d > 0)
                    md[{sum[j] + s, sum[n] + 1}] += d;
                else {
                    ans += d;
                    md[{sum[n], sum[j] + s}] += -d;
                }
            }
            for (int s = 0; s < ks[i] - 1; s++) {
                for (int t = 0; t < ks[j] - 1; t++) {
                    flow_t d = phi[i][j][s + 1][t] + phi[i][j][s][t + 1] - phi[i][j][s + 1][t + 1] - phi[i][j][s][t];
                    assert(d >= 0);
                    ans -= d;
                    md[{sum[n], sum[i] + s}] += d;
                    md[{sum[i] + s, sum[j] + t}] += d;
                }
            }
        }
    }
    for (auto &e : md) {
        if (e.second > 0)
            mf.add_edge(e.first.first, e.first.second, e.second);
    }
    ans += mf.max_flow(sum[n], sum[n] + 1);
    return ans;
}

// O(k^3N^2(N + kM))  (M : 2)
template <typename flow_t>
flow_t k_Option_ProjectSelectionProblem(const vv<flow_t> &theta, const phi_ls_t<flow_t> &phi_ls) {
    int n = theta.size();
    vector<int> ks(n), sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        ks[i] = theta[i].size();
        sum[i + 1] = sum[i] + ks[i] - 1;
    }
    Dinic<flow_t> mf(sum[n] + 2);
    flow_t ans = 0;
    const flow_t INF = numeric_limits<flow_t>::max();
    map<pair<int, int>, flow_t> md;
    for (int i = 0; i < n; i++)
        ans += theta[i][ks[i] - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ks[i] - 2; j++)
            md[{sum[i] + j + 1, sum[i] + j}] += INF;
        for (int j = 0; j < ks[i] - 1; j++) {
            if (theta[i][j] > theta[i][j + 1])
                md[{sum[n], sum[i] + j}] += theta[i][j] - theta[i][j + 1];
            else {
                ans -= theta[i][j + 1] - theta[i][j];
                md[{sum[i] + j, sum[n] + 1}] += theta[i][j + 1] - theta[i][j];
            }
        }
        for (auto &[j, phi] : phi_ls[i]) {
            ans += phi[0][0];
            for (int s = 0; s < ks[i] - 1; s++) {
                flow_t d = phi[s + 1][0] - phi[s][0];
                if (d > 0)
                    md[{sum[i] + s, sum[n] + 1}] += d;
                else {
                    ans += d;
                    md[{sum[n], sum[i] + s}] += -d;
                }
            }
            for (int s = 0; s < ks[j] - 1; s++) {
                flow_t d = phi[0][s + 1] - phi[0][s];
                if (d > 0)
                    md[{sum[j] + s, sum[n] + 1}] += d;
                else {
                    ans += d;
                    md[{sum[n], sum[j] + s}] += -d;
                }
            }
            for (int s = 0; s < ks[i] - 1; s++) {
                for (int t = 0; t < ks[j] - 1; t++) {
                    flow_t d = phi[s + 1][t] + phi[s][t + 1] - phi[s + 1][t + 1] - phi[s][t];
                    assert(d >= 0);
                    ans -= d;
                    md[{sum[n], sum[i] + s}] += d;
                    md[{sum[i] + s, sum[j] + t}] += d;
                }
            }
        }
    }
    for (auto &e : md) {
        if (e.second > 0)
            mf.add_edge(e.first.first, e.first.second, e.second);
    }
    ans += mf.max_flow(sum[n], sum[n] + 1);
    return ans;
}
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    vv<ll> a(n + m, vector<ll>(2, 0));
    rep(i, n) cin >> a[i][1];
    phi_ls_t<ll> phi(n + m);
    rep(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        phi[u].push_back({n + i, {{0, (ll)1e15}, {0, 0}}});
        phi[v].push_back({n + i, {{0, (ll)1e15}, {0, 0}}});
        a[n + i][1] = -w;
    }
    cout << -k_Option_ProjectSelectionProblem<ll>(a, phi) << endl;
}