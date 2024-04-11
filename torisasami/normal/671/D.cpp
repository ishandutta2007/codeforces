#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define REP(i, l, r) for (int i = l; i < (r); i++)
#define REP2(i, l, r) for (int i = (int)r - 1; i >= (l); i--)
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
    vector<int> data;
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

    int size(int k) {
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
    ans %= mod;
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

ll divide_int(ll a, ll b) {
    return (a >= 0 ? a / b : (a - b + 1) / b);
}

// constexpr int mod = 1000000007;
constexpr int mod = 998244353;
// constexpr int mod = 31607;
using mint = Mod_Int<mod>;

mint mpow(mint x, ll n) {
    bool rev = n < 0;
    n = abs(n);
    mint ans = 1;
    while (n != 0) {
        if (n & 1)
            ans *= x;
        x *= x;
        n = n >> 1;
    }
    return (rev ? ans.inverse() : ans);
}

// ----- library -------
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {
    }

    operator int() const {
        return to;
    }
};

template <typename T = int>
struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }

    inline vector<Edge<T>> &operator[](const int &k) {
        return g[k];
    }

    inline const vector<Edge<T>> &operator[](const int &k) const {
        return g[k];
    }
};

template <typename T = int>
using Edges = vector<Edge<T>>;
template <typename T, bool isMin = true>
struct SkewHeap {
    struct Node {
        T key, lazy;
        Node *l, *r;
        int idx;

        explicit Node(const T &key, int idx) : key(key), idx(idx), lazy(0), l(nullptr), r(nullptr) {
        }
    };

    SkewHeap() = default;

    Node *alloc(const T &key, int idx = -1) {
        return new Node(key, idx);
    }

    Node *propagate(Node *t) {
        if (t && t->lazy != 0) {
            if (t->l)
                t->l->lazy += t->lazy;
            if (t->r)
                t->r->lazy += t->lazy;
            t->key += t->lazy;
            t->lazy = 0;
        }
        return t;
    }

    Node *meld(Node *x, Node *y) {
        propagate(x), propagate(y);
        if (!x || !y)
            return x ? x : y;
        if ((x->key < y->key) ^ isMin)
            swap(x, y);
        x->r = meld(y, x->r);
        swap(x->l, x->r);
        return x;
    }

    Node *push(Node *t, const T &key, int idx = -1) {
        return meld(t, alloc(key, idx));
    }

    Node *pop(Node *t) {
        assert(t != nullptr);
        return meld(t->l, t->r);
    }

    Node *add(Node *t, const T &lazy) {
        if (t) {
            t->lazy += lazy;
            propagate(t);
        }
        return t;
    }

    Node *make_root() {
        return nullptr;
    }
};
template <typename T>
struct MinimumSpanningTree {
    T cost;
    Edges<T> edges;
};

template <typename T>
MinimumSpanningTree<T> directed_mst(int V, int root, Edges<T> edges) {
    vector<vector<int>> li(V);
    for (auto e : edges)
        li[e.from].pb(e.to);
    vector<int> f(V, 0);
    f[root] = 1;
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        auto now = que.front();
        que.pop();
        for (auto e : li[now]) {
            if (!f[e])
                f[e] = 1, que.push(e);
        }
    }
    if (accumulate(all(f), 0) != V)
        return {-1, {}};

    for (int i = 0; i < V; ++i) {
        if (i != root)
            edges.emplace_back(i, root, 0);
    }

    int x = 0;
    vector<int> par(2 * V, -1), vis(par), link(par);

    using Heap = SkewHeap<T, true>;
    using Node = typename Heap::Node;

    Heap heap;
    vector<Node *> ins(2 * V, heap.make_root());

    for (int i = 0; i < (int)edges.size(); i++) {
        auto &e = edges[i];
        ins[e.to] = heap.push(ins[e.to], e.cost, i);
    }
    vector<int> st;
    auto go = [&](int x) {
        x = edges[ins[x]->idx].from;
        while (link[x] != -1) {
            st.emplace_back(x);
            x = link[x];
        }
        for (auto &p : st) {
            link[p] = x;
        }
        st.clear();
        return x;
    };
    for (int i = V; ins[x]; i++) {
        for (; vis[x] == -1; x = go(x))
            vis[x] = 0;
        for (; x != i; x = go(x)) {
            auto w = ins[x]->key;
            auto v = heap.pop(ins[x]);
            v = heap.add(v, -w);
            ins[i] = heap.meld(ins[i], v);
            par[x] = i;
            link[x] = i;
        }
        for (; ins[x] && go(x) == x; ins[x] = heap.pop(ins[x]))
            ;
    }
    T cost = 0;
    Edges<T> ans;
    for (int i = root; i != -1; i = par[i]) {
        vis[i] = 1;
    }
    for (int i = x; i >= 0; i--) {
        if (vis[i] == 1)
            continue;
        cost += edges[ins[i]->idx].cost;
        ans.emplace_back(edges[ins[i]->idx]);
        for (int j = edges[ins[i]->idx].to; j != -1 && vis[j] == 0; j = par[j]) {
            vis[j] = 1;
        }
    }
    return {cost, ans};
}
// ----- library -------

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n, m;
    cin >> n >> m;
    Edges<ll> edges;
    vector<vector<int>> li(n);
    int a, b;
    rep(i, n - 1) cin >> a >> b, li[--a].pb(--b), li[b].pb(a);
    auto dfs = [&](int now, int par, auto f) -> void {
        for (auto e : li[now]) {
            if (e == par)
                continue;
            edges.pb(e, now, 0);
            f(e, now, f);
        }
    };
    dfs(0, -1, dfs);
    int u, v, w;
    rep(i, m) cin >> u >> v >> w, edges.pb(--v, --u, w);
    cout << directed_mst<ll>(n, 0, edges).cost << endl;
}