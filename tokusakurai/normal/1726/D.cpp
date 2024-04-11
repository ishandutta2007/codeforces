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

struct Union_Find_Tree {
    vector<int> data;
    const int n;
    int cnt;

    Union_Find_Tree(int n) : data(n, -1), n(n), cnt(n) {}

    int root(int x) {
        if (data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator[](int i) { return root(i); }

    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        cnt--;
        return true;
    }

    int size(int x) { return -data[root(x)]; }

    int count() { return cnt; };

    bool same(int x, int y) { return root(x) == root(y); }

    void clear() {
        cnt = n;
        fill(begin(data), end(data), -1);
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

    vector<int> used;

    Graph(int n) : es(n), n(n), m(0), used(n) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    vector<int> ret_path;

    bool detect_path(int now, int t, bool use_id = false) {
        used[now] = true;
        if (now == t) {
            if (!use_id) ret_path.push_back(now);
            return true;
        }
        for (auto &e : es[now]) {
            if (used[e.to]) continue;
            if (detect_path(e.to, t, use_id)) {
                ret_path.push_back(use_id ? e.id : now);
                return true;
            }
        }
        return false;
    }

    vector<int> find_path(int s, int t, bool use_id = false) { //  s-t 1
        ret_path.clear(), fill(begin(used), end(used), 0);
        detect_path(s, t, use_id);
        reverse(begin(ret_path), end(ret_path));
        return ret_path;
    }

    vector<int> ret_cycle;

    int detect_cycle(int now, int pre = -1, bool use_id = false) {
        if (used[now]++) return 1;
        for (auto &e : es[now]) {
            if (e.id == pre) continue;
            int k = detect_cycle(e.to, e.id, use_id);
            if (k == 2) return 2;
            if (k == 1) {
                ret_cycle.push_back(use_id ? e.id : now);
                return used[now];
            }
        }
        return 0;
    }

    vector<int> find_cycle(bool use_id = false) { // 1
        ret_cycle.clear(), fill(begin(used), end(used), 0);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            detect_cycle(i, -1, use_id);
            if (!ret_cycle.empty()) {
                reverse(begin(ret_cycle), end(ret_cycle));
                return ret_cycle;
            }
        }
        return {};
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        Union_Find_Tree uf(N);
        vector<int> ids;
        Graph G(N);

        vector<pii> ps;
        string S(M, '0');
        vector<int> id2;

        rep(i, M) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (uf.unite(u, v)) {
                ids.eb(i);
                G.add_edge(u, v);
            } else {
                ps.eb(u, v);
                id2.eb(i);
                S[i] = '1';
            }
        }

        if (M <= N + 1) {
            cout << S << '\n';
            continue;
        } else {
            vector<int> tmp;
            each(e, ps) {
                auto [u, v] = e;
                tmp.eb(u), tmp.eb(v);
            }
            sort(all(tmp));
            // print(tmp);
            if (tmp[0] == tmp[1] && tmp[2] == tmp[3] && tmp[4] == tmp[5]) {
                auto [u, v] = ps[0];
                auto p = G.find_path(u, v, true);
                int a = ids[p[0]], b = id2[0];
                S[a] = '1';
                S[b] = '0';
                cout << S << '\n';
            } else {
                cout << S << '\n';
            }
        }
    }
}