#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  int N, M;
  cin >> N >> M;
  vector<string> grid(N);
  for (int i = 0; i < N; ++i) cin >> grid[i];
  vector<int> A(M);
  for (int i = 0; i < M; ++i) cin >> A[i];

  vector<vector<int>> g(N * M), r(N * M);

  auto AddEdge = [&](int u, int v) {
    g[u].push_back(v);
    r[v].push_back(u);
  };

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (i + 1 < N) AddEdge(i * M + j, (i + 1) * M + j);
      if (grid[i][j] == '#' && i - 1 >= 0 && grid[i - 1][j] == '#') AddEdge(i * M + j, (i - 1) * M + j);
      if (j + 1 < M && grid[i][j + 1] == '#') AddEdge(i * M + j, i * M + j + 1);
      if (j - 1 >= 0 && grid[i][j - 1] == '#') AddEdge(i * M + j, i * M + j - 1);
    }
  }

  vector<bool> vis(N * M);
  vector<int> order, scc(N * M, -1);

  auto Dfs = [&](auto dfs, int x) -> void {
    vis[x] = true;
    for (int u : g[x]) {
      if (!vis[u]) dfs(dfs, u);
    }
    order.push_back(x);
  };

  auto RevDfs = [&](auto dfs, int x, int y) -> void {
    scc[x] = y;
    for (int u : r[x]) {
      if (scc[u] == -1) dfs(dfs, u, y);
    }
  };

  for (int i = 0; i < N * M; ++i) {
    if (!vis[i]) Dfs(Dfs, i);
  }
  int S = 0;
  for (int i = order.size() - 1; i >= 0; --i) {
    if (scc[order[i]] == -1) RevDfs(RevDfs, order[i], S++);
  }
  vector<vector<int>> sg(S);
  vector<int> deg(S);

  for (int i = 0; i < N * M; ++i) {
    for (int u : g[i]) {
      if (scc[i] != scc[u]) sg[scc[i]].push_back(scc[u]);
    }
  }
  for (int i = 0; i < S; ++i) {
    sort(sg[i].begin(), sg[i].end());
    sg[i].resize(unique(sg[i].begin(), sg[i].end()) - sg[i].begin());
    for (int u : sg[i]) ++deg[u];
  }
  vector<bool> filled(S);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == '#') filled[scc[i * M + j]] = true;
    }
  }
  vector<int> que;
  for (int i = 0; i < S; ++i) {
    if (deg[i] == 0) que.push_back(i);
  }
  int res = que.size();
  for (int it = 0; it < que.size(); ++it) {
    int x = que[it];
    if (filled[x]) continue;
    --res;
    for (int u : sg[x]) {
      if (--deg[u] == 0) {
        ++res;
        que.push_back(u);
      }
    }
  }
  cout << res << "\n";
  return 0;
}