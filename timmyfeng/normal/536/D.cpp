#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int N = 2000 + 1;

vector<array<int, 2>> adj[N];
long long dist[N], temp[N];

void dijkstra(int src, int n, int *rank) {
    fill(dist, dist + n, LLONG_MAX);
    dist[src] = 0;

    min_queue<array<long long, 2>> que;
    que.push({0, src});

    while (!que.empty()) {
        auto [d, u] = que.top();
        que.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto [c, w] : adj[u]) {
            if (d + w < dist[c]) {
                dist[c] = d + w;
                que.push({d + w, c});
            }
        }
    }

    copy(dist, dist + n, temp);
    sort(temp, temp + n);
    int m = unique(temp, temp + n) - temp;

    for (int i = 0; i < n; ++i) {
        rank[i] = lower_bound(temp, temp + m, dist[i]) - temp + 1;
    }
}

int points[N], x[N], y[N];
vector<int> grid[N][N];

long long tavas[N][N], nafas[N][N], sum_r[N], sum_c[N];
bool any_r[N], any_c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;

    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(s, n, x);
    dijkstra(t, n, y);

    for (int i = 0; i < n; ++i) {
        grid[x[i]][y[i]].push_back(i);
    }

    for (int i = n; i >= 0; --i) {
        for (int j = n; j >= 0; --j) {
            if (i > 0) {
                tavas[i - 1][j] = sum_r[i] +
                    max(tavas[i][j], any_r[i] ? -nafas[i][j] : LLONG_MIN);
            }

            if (j > 0) {
                nafas[i][j - 1] = sum_c[j] +
                    max(nafas[i][j], any_c[j] ? -tavas[i][j] : LLONG_MIN);
            }

            if (!grid[i][j].empty()) {
                any_r[i] = any_c[j] = true;
                for (auto k : grid[i][j]) {
                    sum_r[i] += points[k];
                    sum_c[j] += points[k];
                }
            }
        }
    }

    if (tavas[0][0] < 0) {
        cout << "Cry\n";
    } else if (tavas[0][0] == 0) {
        cout << "Flowers\n";
    } else {
        cout << "Break a heart\n";
    }
}