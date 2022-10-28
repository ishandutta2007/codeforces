#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    deque<int> bfs_q;
    bfs_q.push_front(n - 1);

    vector<int> dist(2 * n, -1), parent(2 * n, -1);
    dist[n - 1] = 0;

    int highest = n - 1;
    while (!bfs_q.empty()) {
        int u = bfs_q.front();
        bfs_q.pop_front();

        if (u >= n) {
            while (highest > (u - n) - a[u - n]) {
                if (--highest == -1) {
                    cout << dist[u] + 1 << "\n";
                    vector<int> path;
                    if (dist[u]) path.push_back(parent[u]);
                    while ((int) path.size() < dist[u]) {
                        path.push_back(parent[parent[path.back()]]);
                    }
                    reverse(path.begin(), path.end());
                    path.push_back(-1);
                    for (auto i : path)
                        cout << i + 1 << " ";
                    cout << "\n";
                    exit(0);
                }

                bfs_q.push_back(highest);
                dist[highest] = dist[u] + 1;
                parent[highest] = u;
            }
        } else {
            int v = n + u + b[u];
            if (dist[v] == -1) {
                bfs_q.push_front(v);
                dist[v] = dist[u];
                parent[v] = u;
            }
        }
    }

    cout << -1 << "\n";
}