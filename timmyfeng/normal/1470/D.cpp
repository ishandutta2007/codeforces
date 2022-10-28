#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

vector<int> adj[N];
bool visited[N], color[N];

void dfs(int u, int p = -1) {
  visited[u] = 1;
  if (p == -1 || !color[p]) {
    color[u] = true;
    for (auto c : adj[u]) {
      if (visited[c] == 1) {
        color[u] &= !color[c];
      }
    }
  }

  for (auto c : adj[u]) {
    if (visited[c] == 0) {
      dfs(c, u);
    }
  }
  visited[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    fill(adj, adj + n, vector<int>());
    fill(visited, visited + n, false);
    fill(color, color + n, false);
    while (m--) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0);
    if (count(visited, visited + n, 0) > 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << count(color, color + n, true) << "\n";
      for (int i = 0; i < n; ++i) {
        if (color[i]) {
          cout << i + 1 << " ";
        }
      }
      cout << "\n";
    }
  }
}