#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int N = 200000;
const int L = __lg(N) + 1;
const int M = 998244353;

vector<int> adj[N][2];
int trans[N][2];
int dist[N][L];
int n;

int bfs() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      dist[i][j] = -1;
    }
  }

  deque<array<int, 2>> que;
  que.push_back({0, 0});
  dist[0][0] = 0;

  while (!que.empty()) {
    auto [u, t] = que.front();
    que.pop_front();

    for (auto c : adj[u][t]) {
      if (dist[c][t] == -1) {
        dist[c][t] = dist[u][t];
        que.push_front({c, t});
      }
    }

    if (dist[u][1 - t] == -1) {
      dist[u][1 - t] = dist[u][t] + 1;
      que.push_back({u, 1 - t});
    }
  }

  return min(dist[n - 1][0], dist[n - 1][1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u][0].push_back(v);
    adj[v][1].push_back(u);
  }

  if (bfs() <= __lg(n)) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= __lg(n); ++j) {
        dist[i][j] = -1;
      }
    }

    deque<array<int, 2>> que;
    que.push_back({0, 0});
    dist[0][0] = 0;

    while (!que.empty()) {
      auto [u, t] = que.front();
      que.pop_front();

      for (auto c : adj[u][t % 2]) {
        if (dist[c][t] == -1) {
          dist[c][t] = dist[u][t] + 1;
          que.push_back({c, t});
        }
      }

      if (t + 1 <= __lg(n) && dist[u][t + 1] == -1) {
        dist[u][t + 1] = dist[u][t];
        que.push_front({u, t + 1});
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j <= __lg(n); ++j) {
      if (dist[n - 1][j] != -1) {
        ans = min(ans, dist[n - 1][j] + (1 << j) - 1);
      }
    }
    cout << ans << "\n";
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        trans[i][j] = INT_MAX;
        dist[i][j] = INT_MAX;
      }
    }

    min_queue<array<int, 4>> que;
    que.push({0, 0, 0, 0});
    trans[0][0] = 0;
    dist[0][0] = 0;

    while (!que.empty()) {
      auto [d1, d2, u, t] = que.top();
      que.pop();
      if (make_pair(d1, d2) > make_pair(trans[u][t], dist[u][t])) {
        continue;
      }

      for (auto c : adj[u][t % 2]) {
        if (make_pair(d1, d2 + 1) < make_pair(trans[c][t], dist[c][t])) {
          trans[c][t] = d1;
          dist[c][t] = d2 + 1;
          que.push({d1, d2 + 1, c, t});
        }
      }

      if (make_pair(d1 + 1, d2) < make_pair(trans[u][1 - t], dist[u][1 - t])) {
        trans[u][1 - t] = d1 + 1;
        dist[u][1 - t] = d2;
        que.push({d1 + 1, d2, u, 1 - t});
      }
    }

    int color = make_pair(trans[n - 1][0], dist[n - 1][0]) > make_pair(trans[n - 1][1], dist[n - 1][1]);

    int ans = 1;
    for (int i = 0; i < trans[n - 1][color]; ++i) {
      ans = ans * 2 % M;
    }
    ans = (ans + dist[n - 1][color] - 1) % M;

    cout << ans << "\n";
  }
}