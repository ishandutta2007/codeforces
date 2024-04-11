#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>

template <class Cap, bool isDirect>
struct MaxFlow {
    struct Edge {
        int src, dst, id;
        Cap cap;
        Edge(int src, int dst, int id, Cap cap)
            : src(src), dst(dst), id(id), cap(cap){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<int> dist, iter;

    explicit MaxFlow(int n)
        : graph(n), dist(n), iter(n) {}

    void span(int u, int v, int id, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, id, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, -1, (isDirect ? 0 : cap));
    }

    void bfs(int s) {
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int eidx : graph[v]) {
                const auto& edge = edges[eidx];

                if (edge.cap > 0 && dist[edge.dst] < 0) {
                    dist[edge.dst] = dist[v] + 1;
                    que.push(edge.dst);
                }
            }
        }
    }

    int dfs(int v, int g, Cap f) {
        if (v == g) return f;

        for (int& itr = iter[v]; itr < (int)graph[v].size(); ++itr) {
            int eidx = graph[v][itr];
            auto& edge = edges[eidx];

            if (edge.cap > 0 && dist[v] < dist[edge.dst]) {
                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));

                if (df > 0) {
                    edge.cap -= df;
                    auto& redge = edges[eidx ^ 1];
                    redge.cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    Cap exec(int s, int g) {
        const Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            bfs(s);
            if (dist[g] < 0) return ret;

            std::fill(iter.begin(), iter.end(), 0);
            while (true) {
                Cap flow = dfs(s, g, INF);
                if (flow == 0) break;
                ret += flow;
            }
        }
    }
};

void solve() {
    int na, nb, m;
    std::cin >> na >> nb >> m;

    std::vector<int> adeg(na, 0), bdeg(nb, 0);
    std::vector<std::pair<int, int>> edges(m);
    for (auto& e : edges) {
        std::cin >> e.first >> e.second;
        --e.first, --e.second;
        ++adeg[e.first], ++bdeg[e.second];
    }

    int mindeg = std::min(*std::min_element(adeg.begin(), adeg.end()),
                          *std::min_element(bdeg.begin(), bdeg.end()));

    for (int k = 0; k <= mindeg; ++k) {
        int s = na + nb, g = na + nb + 1;
        MaxFlow<int, true> mf(na + nb + 2);

        for (int va = 0; va < na; ++va) {
            mf.span(s, va, -1, adeg[va] - k);
        }
        for (int vb = 0; vb < nb; ++vb) {
            mf.span(vb + na, g, -1, bdeg[vb] - k);
        }

        for (int i = 0; i < m; ++i) {
            mf.span(edges[i].first, edges[i].second + na, i, 1);
        }

        mf.exec(s, g);
        std::vector<int> ans;
        for (auto e : mf.edges) {
            if (e.id < 0) continue;
            if (e.cap > 0) ans.push_back(e.id);
        }

        std::cout << ans.size() << " ";
        for (auto i : ans) std::cout << i + 1 << " ";
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}