#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

vector<int> adj[N];
bool bipartite[N];
int group[N];
bool visited[N];
int parity[N];
int color[N];

void dfs(int u, int j) {
  visited[u] = true;
  group[u] = j;
  for (auto c : adj[u]) {
    if (color[c] == color[u]) {
      if (!visited[c]) {
        parity[c] = parity[u] ^ 1;
        dfs(c, j);
      } else {
        bipartite[color[u]] &= parity[c] != parity[u];
      }
    }
  }
}

vector<array<int, 2>> comp[N];
int parity2[N];

bool dfs_check(int u) {
  visited[u] = true;
  for (auto [c, w] : comp[u]) {
    if (!visited[c]) {
      parity2[c] = parity2[u] ^ w ^ 1;
      if (!dfs_check(c)) {
        return false;
      }
    } else if (parity2[c] != (parity2[u] ^ w ^ 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  for (int i = 0; i < n; ++i) {
    cin >> color[i];
    --color[i];
  }

  map<array<int, 2>, vector<array<int, 2>>> edges;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (color[--u] > color[--v]) {
      swap(u, v);
    }
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges[{color[u], color[v]}].push_back({u, v});
  }

  fill(bipartite, bipartite + t, true);
  for (int i = 0, j = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, j++);
    }
  }

  long long ans = count(bipartite, bipartite + t, true);
  ans = ans * (ans - 1) / 2;

  fill(visited, visited + n, false);
  for (auto &[c, e] : edges) {
    if (!bipartite[c[0]] || !bipartite[c[1]] || c[0] == c[1]) {
      continue;
    }

    set<int> todo;
    for (auto [u, v] : e) {
      comp[group[u]].push_back({group[v], parity[u] ^ parity[v]});
      comp[group[v]].push_back({group[u], parity[u] ^ parity[v]});
      todo.insert(group[u]);
      todo.insert(group[v]);
    }

    bool ok = true;
    for (auto i : todo) {
      if (!visited[i]) {
        ok &= dfs_check(i);
      }
    }

    for (auto i : todo) {
      visited[i] = false;
      comp[i].clear();
    }

    ans -= !ok;
  }

  cout << ans << "\n";
}