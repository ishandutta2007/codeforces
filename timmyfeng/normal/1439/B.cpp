#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

unordered_set<int> adj[N];
bool visited[N];
int degree[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  fill(adj, adj + n, unordered_set<int>());
  fill(visited, visited + n, false);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  set<array<int, 2>> nodes;
  for (int i = 0; i < n; ++i) {
    degree[i] = adj[i].size();
    nodes.insert({degree[i], i});
  }

  vector<vector<int>> todo;
  while (!nodes.empty()) {
    auto [d, u] = *nodes.begin();
    nodes.erase(nodes.begin());

    if (d == k - 1) {
      vector<int> v = {u};
      for (auto c : adj[u]) {
        if (!visited[c]) {
          v.push_back(c);
        }
      }
      todo.push_back(v);
    } else if (d >= k) {
      cout << 1 << " " << count(visited, visited + n, false) << "\n";
      for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
          cout << i + 1 << " ";
        }
      }
      cout << "\n";
      return;
    }

    visited[u] = true;
    for (auto c : adj[u]) {
      if (!visited[c]) {
        nodes.erase({degree[c], c});
        nodes.insert({--degree[c], c});
      }
    }
  }

  for (auto &v : todo) {
    bool ok = true;
    for (int i = 0; i < (int) v.size() && ok; ++i) {
      for (int j = i + 1; j < (int) v.size() && ok; ++j) {
        ok &= adj[v[i]].count(v[j]) > 0;
      }
    }

    if (ok) {
      cout << 2 << "\n";
      for (auto i : v) {
        cout << i + 1 << " ";
      }
      cout << "\n";
      return;
    }
  }

  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}