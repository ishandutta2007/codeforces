#include <iostream>
#include <vector>
#include <set>
#include <functional>

struct Edge {
    int src, dst, id;
    bool used;
    explicit Edge(int src, int dst, int id)
        : src(src), dst(dst), id(id), used(false) {}
};

std::vector<Edge> edges;
std::vector<std::vector<int>> graph;
std::vector<int> trail;

void dfs(int v) {
    while (!graph[v].empty()) {
        int ei = graph[v].back();
        graph[v].pop_back();

        auto& e = edges[ei];
        if (e.used) continue;

        auto& re = edges[ei ^ 1];

        e.used = true;
        re.used = true;

        dfs(e.dst);

        trail.push_back(re.id);
        trail.push_back(e.id);
    }
}

bool build(std::vector<std::pair<int, int>> es, int k) {
    int mask = ((1 << k) - 1);
    int n = es.size();

    edges.clear();
    graph.clear();
    graph.resize(1 << k);

    for (int i = 0; i < n; ++i) {
        auto [u, v] = es[i];
        u &= mask;
        v &= mask;

        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, i * 2 + 0);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, i * 2 + 1);
    }

    for (const auto& vs : graph) {
        if (vs.size() % 2 != 0) return false;
    }

    trail.clear();
    for (int v = 0; v < (1 << k); ++v) {
        if (graph[v].empty()) continue;
        dfs(v);
        break;
    }

    return (int)trail.size() == n * 2;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> es(n);
    for (auto& e : es) {
        std::cin >> e.first >> e.second;
    }

    int ok = 0, ng = 21;
    while (ng - ok > 1) {
        int k = (ok + ng) / 2;
        if (build(es, k)) {
            ok = k;
        } else {
            ng = k;
        }
    }

    std::cout << ok << "\n";
    build(es, ok);
    for (auto e : trail) std::cout << e + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}