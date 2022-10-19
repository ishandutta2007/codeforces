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
struct Eulerian_Trail {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<bool> used_e, used_v;
    vector<int> deg;
    const int n;
    int m;

    Eulerian_Trail(int n) : es(n), used_v(n), deg(n, 0), n(n), m(0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m++);
        if (directed) {
            deg[from]++, deg[to]--;
        } else {
            es[to].emplace_back(from, m++);
            deg[from]++, deg[to]++;
        }
    }

    vector<int> trace(int s, bool use_id = false) {
        stack<edge> st;
        vector<int> ret;
        st.emplace(s, -1);
        while (!st.empty()) {
            int now = st.top().to;
            used_v[now] = true;
            if (es[now].empty()) {
                ret.push_back(use_id ? st.top().id : now);
                st.pop();
            } else {
                auto &e = es[now].back();
                es[now].pop_back();
                int id = directed ? e.id : e.id / 2;
                if (used_e[id]) continue;
                used_e[id] = true;
                st.push(e);
            }
        }
        if (use_id) ret.pop_back();
        reverse(begin(ret), end(ret));
        return ret;
    }

    vector<vector<int>> eulerian_trail(bool use_id = false) { // 
        vector<vector<int>> ret;
        fill(begin(used_v), end(used_v), false);
        if (directed) {
            for (auto &e : deg) {
                if (e != 0) return {};
            }
        } else {
            for (auto &e : deg) {
                if (e & 1) return {};
            }
        }
        used_e.assign(directed ? m : m / 2, false);
        for (int i = 0; i < n; i++) {
            if (!used_v[i]) ret.push_back(trace(i, use_id));
        }
        return ret;
    }

    vector<vector<int>> semi_eulerian_trail(bool use_id = false) { // 
        Union_Find_Tree uf(n);
        for (int i = 0; i < n; i++) {
            for (auto &e : es[i]) uf.unite(i, e.to);
        }
        vector<vector<int>> group(n);
        for (int i = 0; i < n; i++) group[uf[i]].push_back(i);
        vector<vector<int>> ret;
        used_e.assign(directed ? m : m / 2, false);
        for (auto &vs : group) {
            if (vs.empty()) continue;
            int s = -1, t = -1;
            if (directed) {
                for (auto &u : vs) {
                    if (abs(deg[u]) > 1) return {};
                    if (deg[u] == 1) {
                        if (s != -1) return {};
                        s = u;
                    }
                }
            } else {
                for (auto &u : vs) {
                    if (deg[u] & 1) {
                        if (s != -1 && t != -1) return {};
                        (s == -1 ? s : t) = u;
                    }
                }
            }
            ret.push_back(trace(s == -1 ? vs.front() : s, use_id));
        }
        return ret;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> u(M), v(M), w(M);
    vector<vector<vector<int>>> es(2, vector<vector<int>>(N));

    rep(i, M) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--, w[i]--;
        es[w[i]][u[i]].eb(i);
        es[w[i]][v[i]].eb(i);
    }

    vector<bool> used(M, false);
    int ans = 0;
    string S(M, '0');
    vector<vector<int>> U(2), V(2);
    vector<vector<vector<int>>> path(2);

    rep(t, 2) {
        vector<int> deg(N, 0);
        rep(i, N) deg[i] = sz(es[t][i]);
        rep(i, N) {
            if (deg[i] % 2 == 0) continue;
            int ptr = i;
            U[t].eb(ptr);
            vector<int> tmp;
            while (deg[ptr] & 1) {
                while (used[es[t][ptr].back()]) es[t][ptr].pop_back();
                int e = es[t][ptr].back();
                tmp.eb(2 * e + (ptr == u[e] ? 0 : 1));
                int nxt = u[e] ^ v[e] ^ ptr;
                used[e] = true;
                deg[ptr]--, deg[nxt]--;
                ptr = nxt;
            }
            path[t].eb(tmp);
            V[t].eb(ptr);
            if (t == 0) ans += 2;
        }

        Eulerian_Trail G(N);
        vector<int> id;
        rep(i, M) {
            if (!used[i] && w[i] == t) {
                G.add_edge(u[i], v[i]);
                id.eb(i);
            }
        }
        vector<vector<int>> cycle = G.eulerian_trail(true);
        each(c, cycle) {
            each(e, c) {
                int x = id[e / 2];
                S[x] = char('1' + (e & 1));
            }
        }
    }

    vector<vector<int>> col(2);
    vector<int> deg2(N, 0);
    vector<vector<vector<int>>> es2(2, vector<vector<int>>(N));

    rep(t, 2) {
        int K = sz(path[t]);
        col[t].assign(K, -1);
        rep(i, K) {
            es2[t][U[t][i]].eb(i);
            es2[t][V[t][i]].eb(i);
        }
    }

    rep(t, 2) {
        int K = sz(path[t]);
        rep(i, K) {
            if (col[t][i] != -1) continue;
            col[t][i] = 0;
            deg2[U[t][i]] -= t + 1;
            deg2[V[t][i]] += t + 1;
            queue<int> que;
            que.emplace(U[t][i]);
            que.emplace(V[t][i]);

            while (!empty(que)) {
                int i = que.front();
                que.pop();
                rep(s, 2) {
                    each(e, es2[s][i]) {
                        if (col[s][e] != -1) continue;
                        if (U[s][e] == i) {
                            col[s][e] = (deg2[i] > 0 ? 0 : 1);
                            que.emplace(V[s][e]);
                        } else {
                            col[s][e] = (deg2[i] > 0 ? 1 : 0);
                            que.emplace(U[s][e]);
                        }
                        if (col[s][e] == 0) {
                            deg2[U[s][e]] -= s + 1;
                            deg2[V[s][e]] += s + 1;
                        } else {
                            deg2[U[s][e]] += s + 1;
                            deg2[V[s][e]] -= s + 1;
                        }
                    }
                }
            }
        }
    }

    // print(deg2);

    rep(t, 2) {
        int K = sz(path[t]);
        rep(i, K) {
            if (col[t][i] == 0) {
                each(e, path[t][i]) {
                    int x = e / 2;
                    S[x] = char('1' + (e & 1));
                }
            } else {
                each(e, path[t][i]) {
                    int x = e / 2;
                    S[x] = char('2' - (e & 1));
                }
            }
        }
    }

    cout << ans << '\n' << S << '\n';

    // vector<int> deg(N, 0);
    // rep(i, M) {
    //     if (S[i] == '1') {
    //         deg[u[i]] -= w[i] + 1;
    //         deg[v[i]] += w[i] + 1;
    //     } else {
    //         deg[u[i]] += w[i] + 1;
    //         deg[v[i]] -= w[i] + 1;
    //     }
    // }
    // print(deg);
}