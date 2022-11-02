#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;

    Edge() = default;
    Edge(int src, int dst, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }
};

template <class Cost = int>
struct Graph : public std::vector<std::vector<Edge<Cost>>> {
    using std::vector<std::vector<Edge<Cost>>>::vector;

    void span(bool direct, int src, int dst, Cost cost = 1) {
        (*this)[src].emplace_back(src, dst, cost);
        if (!direct) (*this)[dst].emplace_back(dst, src, cost);
    }
};

using namespace std;
using lint = long long;
using P = pair<lint, lint>;

P elim(lint x, lint y) {
    auto g = gcd(x, y);
    return {x / g, y / g};
}

void solve() {
    int m;
    cin >> m;

    vector<pair<P, P>> es(m);
    vector<P> ps;
    for (auto& [p, q] : es) {
        lint a, b, c, d;
        cin >> a >> b >> c >> d;

        p = elim(b * c, (a + b) * d);
        q = elim(b * (c + d), a * d);

        ps.push_back(p), ps.push_back(q);
    }

    auto prev = compress(ps);
    int n = ps.size();

    Graph<int> graph(n);
    for (int i = 0; i < m; ++i) {
        auto [p, q] = es[i];
        graph.span(false, prev[p], prev[q], i);
    }

    vector<bool> visited(n, false), used(m, false);
    vector<pair<int, int>> ans;

    auto dfs = [&](auto&& f, int v, int p) -> void {
        visited[v] = true;

        int pi = -1;
        vector<int> es;
        for (auto e : graph[v]) {
            int u = e.dst;

            if (u == p) {
                pi = e.cost;
            } else {
                if (!visited[u]) f(f, u, v);
                if (!used[e.cost]) es.push_back(e.cost);
            }
        }

        while (es.size() >= 2) {
            int i = es.back();
            es.pop_back();
            int j = es.back();
            es.pop_back();

            ans.emplace_back(i, j);
            used[i] = used[j] = true;
        }

        if (es.size() == 1 && pi != -1) {
            int i = es.back();
            es.pop_back();

            ans.emplace_back(i, pi);
            used[i] = used[pi] = true;
        }
    };

    for (int v = 0; v < n; ++v) {
        if (!visited[v]) dfs(dfs, v, -1);
    }

    cout << ans.size() << "\n";
    for (auto [i, j] : ans) cout << i + 1 << " " << j + 1 << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}