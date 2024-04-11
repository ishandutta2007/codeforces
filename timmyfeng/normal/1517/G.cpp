#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dinic {
    vector<pair<int, T>> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n, s, t;

    dinic(int n) : n(n), s(n - 1), t(n - 2) {
        adj.resize(n);
    }

    int add(int u, int v, T w) {
        adj[u].push_back(edges.size());
        adj[v].push_back(edges.size() + 1);
        edges.push_back({v, w});
        edges.push_back({u, 0});
        return edges.size() - 1;
    }

    bool bfs() {
        level.assign(n, -1);
        level[s] = 0;

        queue<int> que;
        que.push(s);

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (auto e : adj[u]) {
                auto [c, w] = edges[e];
                if (w > 0 && level[c] == -1) {
                    level[c] = level[u] + 1;
                    if (c == t) {
                        return true;
                    }
                    que.push(c);
                }
            }
        }

        return false;
    }

    T dfs(int u, T flow) {
        if (u == t) {
            return flow;
        }

        T initial = flow;
        for ( ; ptr[u] < (int) adj[u].size() && flow > 0; ++ptr[u]) {
            int e = adj[u][ptr[u]];
            auto [c, w] = edges[e];
            if (w > 0 && level[c] == level[u] + 1) {
                T pushed = dfs(c, min(flow, w));
                edges[e ^ 1].second += pushed;
                edges[e].second -= pushed;
                flow -= pushed;
            }
        }

        return initial - flow;
    }

    T max_flow() {
        T ans = 0;
        while (bfs()) {
            ptr.assign(n, 0);
            ans += dfs(s, numeric_limits<T>::max());
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    map<array<int, 2>, int> tents;
    dinic<long long> flower(2 * n + 2);
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        flower.add(i, n + i, w);
        tents[{x, y}] = i;
        sum += w;
    }

    for (auto [p, i] : tents) {
        auto [x, y] = p;
        if (x % 2 == 0) {
            for (auto d : {1, -1}) {
                if (tents.count({x + d, y})) {
                    if (y % 2 == 0) {
                        flower.add(n + tents[{x + d, y}], i, LLONG_MAX);
                    } else {
                        flower.add(n + i, tents[{x + d, y}], LLONG_MAX);
                    }
                }

                if (y % 2 == 0 && tents.count({x, y + d})) {
                    flower.add(n + i, tents[{x, y + d}], LLONG_MAX);
                }
            }
        } else {
            if (y % 2 == 0) {
                flower.add(flower.s, i, LLONG_MAX);
            } else {
                flower.add(n + i, flower.t, LLONG_MAX);
            }
        }
    }

    cout << sum - flower.max_flow() << "\n";
}