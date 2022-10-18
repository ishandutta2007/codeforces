#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vec vector

int main() {
    int N, M;
    cin >> N >> M;
    vec<vec<pair<int, ll>>> edge(N);
    vec<vec<pair<int, ll>>> edgerev(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edge[u - 1].push_back({v - 1, w});
        edgerev[v - 1].push_back({u - 1, w});
    }

    vec<ll> dist(N, 1e15);
    dist[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        d *= -1;
        if (dist[v] < d) {
            continue;
        }
        for (auto [nv, w] : edge[v]) {
            if (dist[nv] > dist[v] + w) {
                dist[nv] = dist[v] + w;
                pq.push({-dist[nv], nv});
            }
        }
    }

    vec<ll> dist2 = {dist.begin(), dist.end()};
    for (int v = 0; v < N; v++) {
        pq.push({-dist[v], v});
    }
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        d *= -1;
        if (dist2[v] < d) {
            continue;
        }
        for (auto [nv, w] : edgerev[v]) {
            if (dist2[nv] > dist2[v] + w) {
                dist2[nv] = dist2[v] + w;
                pq.push({-dist2[nv], nv});
            }
        }
    }

    ll INF = 1e15;

    for (int i = 1; i < N; i++) {
        if (dist2[i] < INF) {
            cout << dist2[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }
}