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
struct BFS {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<int> d;
    vector<int> pre_v, pre_e;
    const int INF_T = (1 << 30) - 1;
    const int n;
    int m;

    BFS(int n) : es(n), d(n), pre_v(n), pre_e(n), n(n), m(0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        if (!directed) es[to].emplace_back(from, m);
        m++;
    }

    int shortest_path(int s, int t = 0) {
        fill(begin(d), end(d), INF_T);
        queue<int> que;
        d[s] = 0;
        que.emplace(s);
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            for (auto &e : es[i]) {
                if (d[i] + 1 < d[e.to]) {
                    d[e.to] = d[i] + 1;
                    pre_v[e.to] = i, pre_e[e.to] = e.id;
                    que.push(e.to);
                }
            }
        }
        return d[t];
    }

    vector<int> restore_path(int s, int t, bool use_id = false) {
        if (d[t] == INF_T) return {};
        vector<int> ret;
        for (int now = t; now != s; now = pre_v[now]) ret.push_back(use_id ? pre_e[now] : now);
        if (!use_id) ret.push_back(s);
        reverse(begin(ret), end(ret));
        return ret;
    }
};

void solve() {
    int N;
    cin >> N;

    vector<vector<vector<int>>> ok(N, vector<vector<int>>(N, vector<int>(N, 0)));
    rep(i, N) rep(j, N) ok[i][i][j] = 1;
    rep(i, N - 1) {
        rep(j, N - i - 1) {
            string S;
            cin >> S;
            int x = i, y = i + j + 1;
            rep(k, N) {
                if (S[k] == '0') {
                    ok[x][y][k] = 0;
                    ok[y][x][k] = 0;
                } else {
                    ok[x][y][k] = 1;
                    ok[y][x][k] = 1;
                }
            }
        }
    }

    int r = 0;

    Union_Find_Tree uf(N);
    rep(i, N) {
        rep(j, i) {
            if (ok[i][j][r]) uf.unite(i, j);
        }
    }
    vector<vector<int>> ids(N);
    rep(i, N) ids[uf[i]].eb(i);
    rep(i, N) { // 0 
        if (uf.same(i, r)) continue;
        vector<int> used(N, 0);
        used[r] = 1;
        BFS G(N);
        vector<pii> ps;

        function<void(int, int)> dfs = [&](int now, int pre) {
            used[now] = 1;
            rep(nxt, N) {
                if (used[nxt]) continue;
                if (ok[nxt][pre][now]) {
                    G.add_edge(now, nxt);
                    dfs(nxt, now);
                    ps.eb(now, nxt);
                }
            }
        };

        each(e, ids[i]) {
            G.add_edge(r, e);
            dfs(e, r);
            ps.eb(r, e);
        }
        if (accumulate(all(used), 0) != N) continue;
        vector<vector<int>> d(N);
        rep(j, N) {
            G.shortest_path(j);
            d[j] = G.d;
        }

        bool flag = true;
        rep(x, N) {
            rep2(y, x + 1, N - 1) {
                rep(z, N) {
                    if (ok[x][y][z] && d[x][z] != d[y][z]) {
                        flag = false;
                    } else if (!ok[x][y][z] & d[x][z] == d[y][z]) {
                        flag = false;
                    }
                }
            }
        }

        if (flag) {
            cout << "Yes\n";
            each(e, ps) {
                auto [u, v] = e;
                cout << u + 1 << ' ' << v + 1 << '\n';
            }
            return;
        }
    }

    cout << "No\n";

    // if (sz(ids[r]) != 1) {
    //     cout << "No\n";
    //     return;
    // }
    // rep(i, N) {
    //     each(u, ids[i]) {
    //         each(v, ids[i]) {
    //             if (ok[u][v][r] == 0) {
    //                 cout << "No\n";
    //                 return;
    //             }
    //         }
    //     }
    // }
}

int main() {
    int T;
    cin >> T;

    while (T--) solve();
}