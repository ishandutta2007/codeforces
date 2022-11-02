
#include <algorithm>
#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>

using namespace std;
using lint = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, lint>> es(m);
    vector<int> ids(n);
    int k;
    {
        atcoder::scc_graph graph(n);
        for (auto& [u, v, l] : es) {
            cin >> u >> v >> l;
            --u, --v;
            graph.add_edge(u, v);
        }

        auto sccs = graph.scc();
        k = sccs.size();
        for (int i = 0; i < k; ++i) {
            for (auto v : sccs[i]) ids[v] = i;
        }
    }

    vector<vector<pair<int, lint>>> graph(n);
    for (auto [u, v, l] : es) {
        if (ids[u] != ids[v]) continue;
        graph[u].emplace_back(v, l);
    }

    vector<lint> gs(k, 0);
    {
        vector<lint> ds(n, -1);
        for (int v = 0; v < n; ++v) {
            if (ds[v] != -1) continue;

            int i = ids[v];
            auto dfs = [&](auto&& f, int v) -> void {
                for (auto [u, l] : graph[v]) {
                    if (ds[u] == -1) {
                        ds[u] = ds[v] + l;
                        f(f, u);
                    } else {
                        auto len = abs(ds[v] + l - ds[u]);
                        gs[i] = gcd(gs[i], len);
                    }
                }
            };
            ds[v] = 0;
            dfs(dfs, v);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int v;
        lint s, t;
        cin >> v >> s >> t;
        --v;

        auto g = gs[ids[v]];
        cout << (s == 0 || (g != 0 && s % gcd(g, t) == 0)
                     ? "YES"
                     : "NO")
             << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}