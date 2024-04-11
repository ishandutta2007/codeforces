#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  mt19937 rng(7122);
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int64_t> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[v].push_back(u);
    }
    map<vector<int>, int64_t> p;
    for (int i = 0; i < n; ++i) {
      if (g[i].empty()) continue;
      sort(g[i].begin(), g[i].end());
      p[g[i]] += c[i];
    }
    int64_t res = 0;
    for (auto it : p) res = __gcd(res, it.second);
    cout << res << "\n";
  }
}