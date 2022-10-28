#include <bits/stdc++.h>
using namespace std;

template <class T>
struct dinic {
    vector<pair<int, T>> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n, s, t;

    dinic(int n, int s, int t) : n(n), s(s), t(t) {
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

const int N = 200;

int fox[N], edge[N][N];
vector<int> adj[N];
bool visited[N];

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> dfs(int u) {
    vector<int> cycle;
    visited[u] = true;
    for (auto c : adj[u]) {
        if (!visited[c]) {
            cycle = dfs(c);
        }
    }
    cycle.push_back(u);
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (auto &i : fox) {
        cin >> i;
    }

    dinic<int> flower(n + 2, n, n + 1);

    for (int i = 0; i < n; ++i) {
        if (fox[i] % 2 == 0) {
            flower.add(flower.s, i, 2);
        } else {
            flower.add(i, flower.t, 2);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (fox[i] % 2 == 0 && fox[j] % 2 == 1 && prime(fox[i] + fox[j])) {
                edge[i][j] = flower.add(i, j, 1);
            }
        }
    }

    if (flower.max_flow() < n) {
        cout << "Impossible\n";
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flower.edges[edge[i][j]].second == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ans.push_back(dfs(i));
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i.size() << " ";
        for (auto j : i) {
            cout << j + 1 << " ";
        }
    }
}