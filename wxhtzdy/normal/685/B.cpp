#include <bits/stdc++.h>

using namespace std;

const int N = 3e5;

int p[N], sz[N], ans[N];
vector<int> g[N];

void dfs(int u) {
  sz[u] = 1;
  if (g[u].size() == 0) {
    ans[u] = u;
    return;
  }
  int id = -1;
  for (int v : g[u]) {
    dfs(v);
    sz[u] += sz[v];
    if (id == -1 || sz[v] > sz[id]) {
      id = v;
    }
  }
  id = ans[id];
  while (sz[id] <= sz[u] / 2) {
    id = p[id];
  }
  ans[u] = id;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    --p[i];
    g[p[i]].push_back(i);
  }
  dfs(0);
  while (q--) {
    int foo;
    cin >> foo;
    cout << ans[foo - 1] + 1 << '\n';
  }
  return 0;
}