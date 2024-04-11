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

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    ll cnt = a % b;
    while (cnt != 0) {
        a = b;
        b = cnt;
        cnt = a % b;
    }
    return b;
}

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
};

template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {
    }

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {
    }

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }

    ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }

    ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }

    ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }

    bool operator==(const ModInt &p) const {
        return x == p.x;
    }

    bool operator!=(const ModInt &p) const {
        return x != p.x;
    }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() {
        return mod;
    }
};

ll mpow2(ll x, ll n, ll mod) {
    ll ans = 1;
    while (n != 0) {
        if (n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}
/*
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
    if (u < 0) u += mod;
    return u;
}
*/

constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = ModInt<mod>;

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
template <typename flow_t, typename cost_t>
struct PrimalDual {
    const cost_t INF;
    bool neg_edge;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool isrev;
    };
    vector<vector<edge>> graph;
    vector<cost_t> potential, min_cost;
    vector<int> prevv, preve;

    PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()), neg_edge(false) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        graph[from].emplace_back((edge){to, cap, cost, (int)graph[to].size(), false});
        graph[to].emplace_back((edge){from, 0, -cost, (int)graph[from].size() - 1, true});
        if (cost < 0)
            neg_edge = true;
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int)graph.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        if (neg_edge) {
            potential.assign(V, INF);
            queue<int> que0;
            vector<int> order;
            vector<int> dim(V, 0);
            for (int i = 0; i < V; i++) {
                for (auto e : graph[i]) {
                    if (e.cap > 0)
                        dim[e.to]++;
                }
            }
            for (int i = 0; i < V; i++) {
                if (!dim[i])
                    que0.push(i);
            }
            while (!que0.empty()) {
                int now = que0.front();
                que0.pop();
                order.push_back(now);
                for (auto e : graph[now]) {
                    if (e.cap > 0) {
                        if (!(--dim[e.to]))
                            que0.push(e.to);
                    }
                }
            }
            potential[s] = 0;
            if (order.size() < V) {
                while (1) {
                    bool update = false;
                    for (int i = 0; i < V; i++) {
                        if (potential[i] != INF) {
                            for (int j = 0; j < graph[i].size(); j++) {
                                edge &e = graph[i][j];
                                cost_t nextCost = potential[i] + e.cost;
                                if (e.cap > 0 && potential[e.to] > nextCost) {
                                    potential[e.to] = nextCost;
                                    update = true;
                                }
                            }
                        }
                    }
                    if (!update)
                        break;
                }
            } else {
                for (int i = 0; i < V; i++) {
                    int now = order[i];
                    if (potential[now] != INF) {
                        for (auto e : graph[now]) {
                            if (e.cap > 0 && potential[now] + e.cost < potential[e.to])
                                potential[e.to] = potential[now] + e.cost;
                        }
                    }
                }
            }
        } else
            potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0) {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while (!que.empty()) {
                Pi p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first)
                    continue;
                for (int i = 0; i < graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if (min_cost[t] == INF)
                return -1;
            for (int v = 0; v < V; v++)
                potential[v] += min_cost[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    vector<pair<pair<int, int>, flow_t>> get_edges() {
        vector<pair<pair<int, int>, flow_t>> E;
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev)
                    continue;
                auto &rev_e = graph[e.to][e.rev];
                E.push_back(mp(mp(i, e.to), rev_e.cap));
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
};
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, a, b;
    cin >> n >> a >> b;
    double p[n], u[n];
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> u[i];
    ll cp[n], cu[n];
    rep(i, n) cp[i] = p[i] * 1000 + 1e-3, cu[i] = u[i] * 1000 + 1e-3;
    PrimalDual<int, ll> mcf(n + 4);
    mcf.add_edge(n, n + 1, a, 0);
    mcf.add_edge(n, n + 2, b, 0);
    rep(i, n) mcf.add_edge(n + 1, i, 1, -cp[i] * 1000), mcf.add_edge(n + 2, i, 1, -cu[i] * 1000), mcf.add_edge(i, n + 3, 1, 0), mcf.add_edge(i, n + 3, 1, cp[i] * cu[i]);
    cout << -(double)mcf.min_cost_flow(n, n + 3, a + b) / 1000000 << endl;
}