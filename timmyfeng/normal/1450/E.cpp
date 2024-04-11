#include <bits/stdc++.h>
using namespace std;

const int N = 200;

vector<array<int, 2>> adj[N];
int visited[N], dist[N], ans[N];
bool in_que[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    --u, --v;
    adj[u].push_back({v, 1});
    adj[v].push_back({u, (t == 0) ? 1 : -1});
    edges.push_back({u, v, t});
  }

  int delta = -1;
  for (int i = 0; i < n; ++i) {
    fill(visited, visited + n, 0);
    fill(dist, dist + n, INT_MAX);
    in_que[i] = true;
    queue<int> que;
    que.push(i);
    dist[i] = n;

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      in_que[u] = false;
      if (++visited[u] == n) {
        break;
      }

      for (auto [c, w] : adj[u]) {
        if (dist[u] + w < dist[c]) {
          dist[c] = dist[u] + w;
          if (!in_que[c]) {
            in_que[c] = true;
            que.push(c);
          }
        }
      }
    }

    bool ok = true;
    for (auto [u, v, w] : edges) {
      if (w == 0) {
        ok &= abs(dist[v] - dist[u]) == 1;
      } else {
        ok &= dist[v] - dist[u] == 1;
      }
    }

    if (ok) {
      int new_delta = *max_element(dist, dist + n) - *min_element(dist, dist + n);
      if (new_delta > delta) {
        copy(dist, dist + n, ans);
        delta = new_delta;
      }
    }
  }

  if (delta == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << delta << "\n";
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}