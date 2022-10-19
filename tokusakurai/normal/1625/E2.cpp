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

template <typename T>
struct Binary_Indexed_Tree {
    vector<T> bit;
    const int n;

    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
        bit.resize(n + 1);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    Binary_Indexed_Tree(int n, const T &x) : n(n) {
        bit.resize(n + 1);
        vector<T> v(n, x);
        copy(begin(v), end(v), begin(bit) + 1);
        for (int a = 2; a <= n; a <<= 1) {
            for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
        }
    }

    void add(int i, const T &x) {
        for (i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T &x) { add(i, x - query(i, i + 1)); }

    T sum(int i) const {
        T ret = 0;
        for (; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }

    T query(int l, int r) const { return sum(r) - sum(l); }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }

    int upper_bound(T x) const {
        int ret = 0;
        for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
            if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x) x -= bit[ret += (1 << k)];
        }
        return ret;
    }
};

template <bool directed = false>
struct Graph {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> vs;     // DFS 
    vector<int> ls, rs; // i  [ls[i],rs[i]) vs[ls[i]] = i

    Graph(int n) : es(n), n(n), m(0), ls(n), rs(n) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    void euler_tour(int now, int pre = -1) {
        ls[now] = vs.size(), vs.push_back(now);
        for (auto &e : es[now]) {
            if (e.to != pre) euler_tour(e.to, now);
        }
        rs[now] = vs.size();
    }
};

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    vector<int> p(N, -1);
    vector<int> a(N + 1, N);

    stack<int> st;
    rep(i, N) {
        if (S[i] == '(') {
            st.emplace(i);
            a[i + 1] = a[i] + 1;
        } else {
            if (!st.empty()) {
                int x = st.top();
                st.pop();
                p[x] = i, p[i] = x;
            }
            a[i + 1] = a[i] - 1;
        }
    }

    vector<vector<int>> ids(2 * N + 1);
    rep(i, N + 1) ids[a[i]].eb(i);

    int MAX = 200000;

    vector<int> id(N, -1), pre(MAX, -1);
    Graph<true> G(MAX);
    int K = 0, ptr = 0;

    rep(i, N) {
        if (p[i] == -1) continue;
        if (S[i] == '(') {
            K++;
            G.add_edge(ptr, K);
            pre[K] = ptr;
            ptr = K;
            id[i] = ptr;
        } else {
            id[i] = ptr;
            ptr = pre[ptr];
        }
    }

    G.euler_tour(0);

    vector<ll> b(MAX, 0);
    rep(i, MAX) b[i] = sz(G.es[i]);
    vector<ll> c(MAX);
    rep(i, MAX) c[G.ls[i]] = b[i] * (b[i] + 1) / 2;

    Binary_Indexed_Tree<ll> bit(c);

    vector<Binary_Indexed_Tree<int>> bit2;
    rep(i, 2 * N + 1) {
        int L = sz(ids[i]);
        bit2.eb(L, 1);
    }

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;

        if (t == 1) {
            int x = id[l], y = pre[x];
            bit.add(G.ls[y], -b[y]);
            b[y]--;
            int z = lb(ids[a[l]], l);
            bit2[a[l]].add(z, -1);
        } else {
            int L = id[l], R = id[r];
            ll ans = bit.query(G.ls[L], G.rs[R]);
            int L2 = lb(ids[a[l]], l), R2 = lb(ids[a[l]], r);
            ll cnt = bit2[a[l]].query(L2, R2);
            ans += cnt * (cnt + 1) / 2;
            cout << ans << '\n';
        }
    }
}