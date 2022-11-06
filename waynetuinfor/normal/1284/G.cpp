#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
      cin >> grid[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == 'X') continue;
        if (i == 0 && j == 0) continue;
        if (i + 1 < N && grid[i + 1][j] == 'O') {
          edges.emplace_back(i * M + j, (i + 1) * M + j);
        }
        if (j + 1 < M && grid[i][j + 1] == 'O') {
          edges.emplace_back(i * M + j, i * M + (j + 1));
        }
      }
    }
    vector<int> deg(N * M);

    auto Limit = [&](int t) {
      int x = t / M, y = t % M;
      if (x == 0 && y == 0 || (x + y) % 2 == 1) return N * M;
      return 2;
    };

    const int K = edges.size();
    vector<bool> used(K);
    vector<int> dist(K, -1);
    vector<int> uf(N * M);
    vector<int> from(K, -1);

    function<int(int)> Find = [&](int x) {
      if (x == uf[x]) return x;
      return uf[x] = Find(uf[x]);
    };

    auto Merge = [&](int x, int y) {
      x = Find(x);
      y = Find(y);
      uf[x] = y;
    };

    int iter = 0;
    for (iter = 0; ; iter++) {
      iota(uf.begin(), uf.end(), 0);
      fill(deg.begin(), deg.end(), 0);
      for (int i = 0; i < K; ++i) {
        if (used[i]) {
          Merge(edges[i].first, edges[i].second);
          ++deg[edges[i].first];
          ++deg[edges[i].second];
        }
      }
      fill(dist.begin(), dist.end(), -1);
      queue<int> que;
      for (int i = 0; i < K; ++i) {
        if (used[i]) continue;
        if (Find(edges[i].first) != Find(edges[i].second)) {
          from[i] = -1;
          dist[i] = 0;
          que.push(i);
        }
      }
      while (!que.empty()) {
        int x = que.front();
        que.pop();
        if (used[x]) {
          iota(uf.begin(), uf.end(), 0);
          for (int i = 0; i < K; ++i) {
            if (used[i] && i != x) {
              Merge(edges[i].first, edges[i].second);
            }
          }
          for (int i = 0; i < K; ++i) {
            if (used[i]) continue;
            if (Find(edges[i].first) != Find(edges[i].second)) {
              if (dist[i] == -1) {
                from[i] = x;
                dist[i] = dist[x] + 1;
                que.push(i);
              }
            }
          }
        } else {
          ++deg[edges[x].first];
          ++deg[edges[x].second];
          for (int i = 0; i < K; ++i) {
            if (!used[i]) continue;
            --deg[edges[i].first];
            --deg[edges[i].second];
            if (deg[edges[x].first] <= Limit(edges[x].first) &&
                deg[edges[x].second] <= Limit(edges[x].second)) {
              if (dist[i] == -1) {
                from[i] = x;
                dist[i] = dist[x] + 1;
                que.push(i);
              }
            }
            ++deg[edges[i].first];
            ++deg[edges[i].second];
          }
          --deg[edges[x].first];
          --deg[edges[x].second];
        }
      }
      int t = -1;
      for (int i = 0; i < K; ++i) {
        if (used[i]) continue;
        if (dist[i] == -1) continue;
        ++deg[edges[i].first];
        ++deg[edges[i].second];
        if (deg[edges[i].first] <= Limit(edges[i].first) &&
            deg[edges[i].second] <= Limit(edges[i].second)) {
          if (t == -1 || dist[i] < dist[t]) {
            t = i;
          }
        }
        --deg[edges[i].first];
        --deg[edges[i].second];
      }
      if (t == -1) {
        break;
      }
      while (t != -1) {
        if (used[t]) {
          used[t] = false;
        } else {
          used[t] = true;
        }
        t = from[t];
      }
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == 'X') continue;
        if (Limit(i * M + j) == 2 && deg[i * M + j] < 2) {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    if (grid[0][1] == 'O') {
      edges.emplace_back(0, 1);
    }
    if (grid[1][0] == 'O') {
      edges.emplace_back(0, M);
    }
    iota(uf.begin(), uf.end(), 0);
    used.resize(edges.size());
    for (int i = 0; i < edges.size(); ++i) {
      if (used[i]) {
        Merge(edges[i].first, edges[i].second);
      }
    }
    for (int i = 0; i < edges.size(); ++i) {
      if (!used[i]) {
        if (Find(edges[i].first) != Find(edges[i].second)) {
          used[i] = true;
          Merge(edges[i].first, edges[i].second);
        }
      }
    }
    vector<string> ans(2 * N - 1, string(2 * M - 1, ' '));
    for (int i = 0; i < edges.size(); ++i) {
      if (used[i]) {
        int x1 = edges[i].first / M, y1 = edges[i].first % M;
        int x2 = edges[i].second / M, y2 = edges[i].second % M;
        assert(x1 == x2 || y1 == y2);
        assert(x1 <= x2 && y1 <= y2);
        if (x1 == x2) {
          ans[2 * x1][2 * y1 + 1] = 'O';
        } else {
          ans[2 * x1 + 1][2 * y1] = 'O';
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        ans[2 * i][2 * j] = grid[i][j];
      }
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * N - 1; ++i) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}