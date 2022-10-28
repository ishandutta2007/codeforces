#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

set<array<int, 2>> adj[N];
bool ok[N], visited[N];
set<int> clause[N];
int prv[N], ans[N];

void dfs_true(int u) {
  ok[u] = true;
  while (!adj[u].empty()) {
    auto [v, x] = *adj[u].begin();
    adj[u].erase(adj[u].begin());
    ans[x] = clause[v].count(x);
    adj[v].erase({u, x});
    dfs_true(v);
  }
}

array<int, 3> dfs_cycle(int u, int p = 0) {
  visited[u] = true;
  for (auto [c, x] : adj[u]) {
    if (c != p) {
      if (visited[c]) {
        return {u, c, x};
      } else {
        array<int, 3> child = dfs_cycle(c, u);
        if (child[0] != 0) {
          return child;
        }
      }
    }
  }
  return {0, 0, 0};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;

    while (k--) {
      int v;
      cin >> v;
      clause[i].insert(v);

      v = abs(v);
      if (prv[v] == 0) {
        prv[v] = i;
      } else {
        adj[prv[v]].insert({i, v});
        adj[i].insert({prv[v], v});
        prv[v] = 0;
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    if (prv[i] != 0) {
      dfs_true(prv[i]);
      ans[i] = clause[prv[i]].count(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    int u = 0, v = 0, x = 0;
    for (auto [j, y] : adj[i]) {
      if (clause[i].count(y) == clause[j].count(y)) {
        u = i, v = j, x = y;
        break;
      }
    }

    if (u != 0) {
      ans[x] = clause[u].count(x);
      adj[u].erase({v, x});
      adj[v].erase({u, x});
      dfs_true(u);
      dfs_true(v);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!ok[i]) {
      auto [u, v, x] = dfs_cycle(i);
      if (x == 0) {
        cout << "NO\n";
        exit(0);
      }

      ans[x] = clause[u].count(x);
      adj[u].erase({v, x});
      adj[v].erase({u, x});
      dfs_true(u);
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= m; ++i) {
    cout << ans[i];
  }
  cout << "\n";
}