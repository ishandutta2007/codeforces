#include <bits/stdc++.h>
using namespace std;

const int N = 2000, I[] = {0, 1, 0, -1}, J[] = {1, 0, -1, 0};

long long a[N][N], from[N][N], to[N][N];

void bfs(int r, int c, long long dist[N][N], int n, int m, int w) {
    for (int i = 0; i < n; ++i) {
        fill(dist[i], dist[i] + m, LLONG_MAX);
    }

    queue<array<int, 2>> que;
    que.push({r, c});
    dist[r][c] = 0;

    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (int d = 0; d < 4; ++d) {
            int i_new = i + I[d];
            int j_new = j + J[d];
            if (0 <= i_new && i_new < n && 0 <= j_new && j_new < m) {
                if (dist[i_new][j_new] == LLONG_MAX && a[i_new][j_new] != -1) {
                    dist[i_new][j_new] = dist[i][j] + w;
                    que.push({i_new, j_new});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, w;
    cin >> n >> m >> w;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    bfs(0, 0, from, n, m, w);
    bfs(n - 1, m - 1, to, n, m, w);

    long long ans = from[n - 1][m - 1];
    long long min_from = LLONG_MAX;
    long long min_to = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0) {
                if (from[i][j] < LLONG_MAX) {
                    min_from = min(min_from, from[i][j] + a[i][j]);
                }
                if (to[i][j] < LLONG_MAX) {
                    min_to = min(min_to, to[i][j] + a[i][j]);
                }
            }
        }
    }

    if (min_from < LLONG_MAX && min_to < LLONG_MAX) {
        ans = min(ans, min_from + min_to);
    }

    cout << (ans < LLONG_MAX ? ans : -1) << "\n";
}