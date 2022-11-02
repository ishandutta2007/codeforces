
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;
using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
    }

    auto status = vector(n, vector(2, false));
    // vout(in)

    // 
    auto calc_num = [&] {
        atcoder::mf_graph<int> mf_graph(n * 2 + 2);
        int s = n * 2, g = s + 1;

        for (int i = 0; i < n; ++i) {
            mf_graph.add_edge(s, i, 1);
            mf_graph.add_edge(i + n, g, 1);
        }
        for (int v = 0; v < n; ++v) {
            if (status[v][0]) continue;
            for (auto u : graph[v]) {
                if (status[u][1]) continue;
                mf_graph.add_edge(u, v + n, 1);
            }
        }
        return n - mf_graph.flow(s, g);
    };

    auto f = calc_num();

    vector<lint> xs(k), ys(k);
    for (int i = 0; i < k; ++i) cin >> xs[i] >> ys[i];

    vector<int> req(k + 1, 0);
    // icnt[i]
    for (int i = 1; i <= k; ++i) {
        req[i] = req[i - 1];
        while (f <= i) {
            ++req[i];
            ++f;
        }
    }

    auto dp = vector(k + 1, vector(k + 1, -INF));
    auto prev = vector(k + 1, vector(k + 1, -1));
    prev[0][0] = 0, dp[0][0] = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = req[i]; j <= k; ++j) {
            if (prev[i][j] == -1) continue;

            for (int d = 0; j + d <= k; ++d) {
                lint score = dp[i][j] + max(0LL, xs[i] - ys[i] * d);
                if (score > dp[i + 1][j + d]) {
                    dp[i + 1][j + d] = score;
                    prev[i + 1][j + d] = d;
                }
            }
        }
    }

    vector<int> cnt(k, 0);
    // icnt[i]
    {
        int j = req[k];
        for (int i = k - 1; i >= 0; --i) {
            assert(prev[i + 1][j] != -1);
            cnt[i] = prev[i + 1][j];
            j -= cnt[i];
        }
        assert(j == 0);
    }

    vector<int> ans;
    auto pf = calc_num();
    for (int i = 0; i < k; ++i) {
        while (cnt[i]--) {
            bool chosen = false;
            for (int v = 0; v < n && !chosen; ++v) {
                for (int t = 0; t < 2 && !chosen; ++t) {
                    if (status[v][t]) continue;
                    status[v][t] = true;

                    if (calc_num() > pf) {
                        chosen = true;
                        ans.push_back((v + 1) * (t == 0 ? 1 : -1));
                        pf = calc_num();
                    } else {
                        status[v][t] = false;
                    }
                }
            }
            assert(chosen);
        }
        ans.push_back(0);
    }

    cout << ans.size() << "\n";
    for (auto a : ans) cout << a << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}