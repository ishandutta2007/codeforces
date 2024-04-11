#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 1;

vector<array<int, 2>> prv[N], nxt[N];
vector<int> adj[N];
int dist[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; ++i) {
    fill(dist[i] + 1, dist[i] + n + 1, -1);
    dist[i][i] = 0;

    queue<int> que;
    que.push(i);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto c : adj[u]) {
        if (dist[i][c] == -1) {
          dist[i][c] = dist[i][u] + 1;
          que.push(c);
        }
      }
    }

    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] != -1) {
        nxt[i].push_back({dist[i][j], j});
        prv[j].push_back({dist[i][j], i});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    sort(nxt[i].rbegin(), nxt[i].rend());
    if (nxt[i].size() > 4) {
      nxt[i].resize(4);
    }

    sort(prv[i].rbegin(), prv[i].rend());
    if (prv[i].size() > 4) {
      prv[i].resize(4);
    }
  }

  array<int, 5> ans{};
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j && dist[i][j] != -1) {
        for (auto [x, u] : prv[i]) {
          for (auto [y, v] : nxt[j]) {
            if (u != i && u != j && u != v && v != i && v != j) {
              ans = max(ans, array<int, 5>{x + dist[i][j] + y, u, i, j, v});
            }
          }
        }
      }
    }
  }

  for (int i = 1; i < 5; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}