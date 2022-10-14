#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int sz = 0;
set<int> all;
vector<set<int>> g(N);
vector<bool> was(N);

void Dfs(int u) {
  all.erase(all.find(u));
  sz++;
  was[u] = true;
  int v = -1;
  while (true) {
    auto it = all.lower_bound(v + 1);
    if (it == all.end()) {
      break;
    }
    int nxt = *it;
    v = nxt;
    if (g[u].find(v) == g[u].end() && !was[v]) {
      Dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].insert(v);
    g[v].insert(u);
  }
  for (int i = 0; i < n; i++) {
    all.insert(i);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      sz = 0;
      Dfs(i);
      ans.push_back(sz);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
  return 0;
}