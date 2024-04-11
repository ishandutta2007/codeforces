#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++ i)

#define all(c) std::begin(c), std::end(c)

#ifdef LOCAL
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)

template<class T, class ...Args> void debug_impl(string s, T&& first, Args &&...args) {
    cerr << "(" << s << ") : (" << forward<T>(first);
    ((cerr << ", " << forward<Args>(args)), ..., (cerr << ") " << "\n"));
}

#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T& a, const T& b) {
    return b > a ? (a = b, true) : false;
}

template<class T> bool chmin(T& a, const T& b) {
    return b < a ? (a = b, true) : false;
}

template<class ...Args> void read(Args &...args) {
    (cin >> ... >> args);
}

template<class T> ostream& operator<<(ostream& out, const vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        out << v[i];
        if (i + 1 != n) out << ' ';
    }
    return out;
}

template<class Head, class ...Tails> void print(Head&& h, Tails && ...tail) {
    cout << h, ((cout << ' ' << forward<Tails>(tail)), ..., (cout << '\n'));
}

using cap_type = int;

struct edge {
    int to, rev;
    cap_type cap;
    edge(int t, cap_type c, int r) : to(t), rev(r), cap(c) {}
};
using graph = vector<vector<edge>>;

void add_edge(graph& g, int from, int to, cap_type cap) {
    g[from].emplace_back(to, cap, g[to].size());
    g[to].emplace_back(from, 0, g[from].size() - 1);
}

cap_type augment(graph& g, vector<int> const& level, vector<int>& iter, int v, int t, cap_type f) {
    if (v == t) return f;
    for (int& i = iter[v]; i < int(g[v].size()); ++i) {
        auto& e = g[v][i];
        if (e.cap > 0 and level[v] < level[e.to]) {
            const auto d = augment(g, level, iter, e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

cap_type max_flow(graph& g, int s, int t) {
    const auto inf = numeric_limits<cap_type>::max() / 2;
    cap_type flow = 0;
    while (true) {
        vector<int> level(g.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (not que.empty()) {
            const int v = que.front();
            que.pop();
            for (auto const& e : g[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
        if (level[t] < 0) return flow;
        vector<int> iter(g.size());
        cap_type f{ 0 };
        while ((f = augment(g, level, iter, s, t, inf)) > 0) {
            flow += f;
        }
    }
}

constexpr int N = 500;

int main() {
    int n, m;
    read(n, m);

    vector<bitset<N>> bs(m);
    vector<vector<bool>> a(n, vector<bool>(m));
    rep(i, n) {
        string s;
        read(s);
        rep(j, m) {
            a[i][j] = s[j] == '1';

            bs[j][i] = a[i][j];
        }
    }

    graph g(m + m + 2);
    const int src = m + m, dst = src + 1;

    vector<int8_t> active(m, true);

    rep(i, m) rep(j, m) if (i != j) {
        if (bs[i] == bs[j]) {
            active[max(i, j)] = false;
        } else if ((bs[i] & bs[j]) == bs[j]) {
            add_edge(g, i, m + j, 1);
        }
    }

    rep(i, m) if (active[i]) {
        add_edge(g, src, i, 1);
        add_edge(g, m + i, dst, 1);
    }

    const int k = accumulate(all(active), 0) - max_flow(g, src, dst);

    // debug(k);

    vector<int> nxt(m, -1);
    vector<int> prv(m, -1);

    rep(i, m) if (active[i]) {
        for (auto e : g[i]) {
            int j = e.to - m;
            if (0 <= j and j < m and e.cap == 0) {
                nxt[i] = e.to - m;
                prv[e.to - m] = i;
            }
        }
    }

    vector<vector<int>> paths;

    vector<int> t(m);

    vector<int> gid(m, -1);
    rep(i, m) if (active[i] and prv[i] == -1) {
        const int id = paths.size();
        paths.emplace_back();

        int threshold = 2;
        for (int v = i; v >= 0; v = nxt[v]) {
            paths.back().push_back(v);
            gid[v] = id + 1;
            t[v] = threshold++;
        }
    }

    vector<vector<int>> b(n, vector<int>(k, m + 10));
    rep(i, n) {
        int idx = 0;
        for (const auto& path : paths) {
            int v = 1;
            for (int j : path) {
                if (a[i][j] == 0) {
                    b[i][idx] = v;
                    break;
                }
                ++v;
            }
            ++idx;
        }
    }

    rep(i, m) if (not active[i]) {
        rep(j, m) if (bs[i] == bs[j]) {
            gid[i] = gid[j];
            t[i] = t[j];
            break;
        }
    }

    print(k);
    print(gid);
    print(t);
    rep(i, n) {
        print(b[i]);
    }
}