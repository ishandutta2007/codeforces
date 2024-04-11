#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

vector<int> layer[N];
bool visited[N];
set<int> adj[N];
int par[N];
int dep;

void dfs(int u, int p) {
  visited[u] = true;
  layer[dep].push_back(u);

  vector<int> todo;
  for (int c : adj[u]) {
    if (c != p) {
      if (visited[c]) {
        todo.push_back(c);
      } else {
        ++dep;
        dfs(c, u);
        --dep;
      }
    }
  }

  for (int c : todo) {
    adj[c].erase(u);
    adj[u].erase(c);
  }
}

pair<int, int> dfs_far(int u, int p) {
  pair<int, int> res = {dep, u};
  for (int c : adj[u]) {
    if (c != p) {
      ++dep;
      par[c] = u;
      res = max(res, dfs_far(c, u));
      --dep;
    }
  }
  return res;
}

void solve() {
  int n, m;
  cin >> n >> m;

  fill(layer, layer + n + 1, vector<int>());
  fill(visited, visited + n + 1, false);
  fill(adj, adj + n + 1, set<int>());

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  dfs(1, 0);

  int u = dfs_far(1, 0).second;
  auto [d, v] = dfs_far(u, 0);

  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += int(layer[i].size()) / 2;
  }

  if (2 * cnt >= (n + 1) / 2) {
    cout << "PAIRING\n";
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < int(layer[i].size()) - 1; j += 2) {
        cout << layer[i][j] << " " << layer[i][j + 1] << "\n";
      }
    }
  } else {
    cout << "PATH\n";
    cout << d + 1 << "\n";
    while (v != u) {
      cout << v << " ";
      v = par[v];
    }
    cout << u << "\n";
  }
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