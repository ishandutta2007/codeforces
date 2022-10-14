#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, long long>> graph[N];

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        graph[u - 1].push_back({v - 1, w * 2});
        graph[v - 1].push_back({u - 1, w * 2});
    }

    vector<long long> dist(N);
    for (auto& i : dist) cin >> i;

    set<pair<long long, int>> que;
    for (int i = 0; i < N; i++) {
        que.insert({dist[i], i});
    }

    while (!que.empty()) {
        auto it = que.begin();
        int u = it -> second;
        que.erase(it);

        for (auto& edge : graph[u]) {
            if (dist[edge.first] > dist[u] + edge.second) {
                que.erase({dist[edge.first], edge.first});
                dist[edge.first] = dist[u] + edge.second;
                que.insert({dist[edge.first], edge.first});
            }
        }

    }

    for (int i = 0; i < N; i++)
        cout << dist[i] << " ";
    return 0;
}