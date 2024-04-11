#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n, -1);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    g[p[i]].push_back(i);
  }

  vector<int> dp(n), deg(n);
  vector<set<pair<int, int>>> s(n);

  function<void(int, int)> Dfs = [&](int x, int p) {
    dp[x] = 0;
    deg[x] = g[x].size();
    for (int u : g[x]) {
      Dfs(u, x);
      s[x].insert(make_pair(dp[u], u));
      dp[x] = max(dp[x], dp[u] + 1);
    }
  };

  vector<int> ans, fa(p.begin(), p.end());

  constexpr int kInf = 1'000'000'000;

  Dfs(0, -1);
  int x = 0;
  set<pair<int, int>> ph;
  while (true) {
    ph.insert(make_pair(deg[x], x));
    if (s[x].empty()) break;
    x = s[x].rbegin()->second;
  }

  while (true) {
    if (ph.rbegin()->first == 1) break;
    int x = ph.rbegin()->second;
    int y = s[x].rbegin()->second;
    int z = s[x].begin()->second;
    ans.push_back(y);
    ph.erase(make_pair(deg[x], x));
    deg[x]--;
    ph.insert(make_pair(deg[x], x));
    fa[y] = z;
    s[x].erase(make_pair(dp[y], y));
    s[x].erase(make_pair(dp[z], z));
    s[z].insert(make_pair(dp[y], y));
    dp[z] = s[z].empty() ? 0 : s[z].rbegin()->first + 1;
    s[x].insert(make_pair(dp[z], z));
    deg[z]++;
    ph.insert(make_pair(deg[z], z));
  }
  assert(ph.size() == n);

  vector<vector<int>> g2(n);
  for (int i = 0; i < n; ++i) {
    if (fa[i] >= 0) g2[fa[i]].push_back(i);
  }

  vector<int> ord;
  for (int i = 0, x = 0; i < n; ++i) {
    ord.push_back(x);
    if (!g2[x].empty()) {
      assert(g2[x].size() == 1);
      x = g2[x][0];
    }
  }
  
  // assert(ans.size() == dp[0]);
  for (int i = 0; i < n; ++i) cout << ord[i] << ' ';
  cout << "\n";
  cout << ans.size() << "\n";
  reverse(ans.begin(), ans.end());
  for (int u : ans) cout << u << ' ';
  cout << "\n";
}