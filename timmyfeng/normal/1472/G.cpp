#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

int dist[N], memo[N][2];
vector<int> adj[N];

int solve(int i, int j) {
  if (memo[i][j] == -1) {
    memo[i][j] = dist[i];
    for (auto k : adj[i]) {
      if (dist[k] > dist[i]) {
        memo[i][j] = min(memo[i][j], solve(k, j));
      } else if (j == 1) {
        memo[i][j] = min(memo[i][j], solve(k, 0));
      }
    }
  }
  return memo[i][j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    fill(adj + 1, adj + 1 + n, vector<int>());
    while (m--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    fill(dist + 2, dist + 1 + n, -1);
    queue<int> que;
    que.push(1);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (auto c : adj[u]) {
        if (dist[c] == -1) {
          dist[c] = dist[u] + 1;
          que.push(c);
        }
      }
    }

    for (int i = 2; i <= n; ++i) {
      memo[i][0] = memo[i][1] = -1;
    }

    for (int i = 1; i <= n; ++i) {
      cout << min(solve(i, 0), solve(i, 1)) << " ";
    }
    cout << "\n";
  }
}