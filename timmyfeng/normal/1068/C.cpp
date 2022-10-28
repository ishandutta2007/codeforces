#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[i].emplace_back(i, m + i);
  }

  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ans[u].emplace_back(u, i);
    ans[v].emplace_back(v, i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i].size() << "\n";
    for (auto [x, y] : ans[i]) {
      cout << x << " " << y << "\n";
    }
  }
}