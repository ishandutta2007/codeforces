#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 100 + 1;

vector<int> adj[N];
int cost[N][K];
int dist[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, s;
  cin >> n >> m >> k >> s;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= k; ++i) {
    queue<int> que;
    for (int j = 1; j <= n; ++j) {
      if (a[j] == i) {
        que.push(j);
      }
      dist[j] = (a[j] == i) ? 0 : -1;
    }

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      cost[u][i] = dist[u];
      for (int c : adj[u]) {
        if (dist[c] == -1) {
          dist[c] = dist[u] + 1;
          que.push(c);
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    sort(cost[i] + 1, cost[i] + k + 1);
    long long ans = 0;
    for (int j = 1; j <= s; ++j) {
      ans += cost[i][j];
    }
    cout << ans << " ";
  }
  cout << "\n";
}