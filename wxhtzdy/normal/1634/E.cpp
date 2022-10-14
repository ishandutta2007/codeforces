#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int m;
  cin >> m;
  vector<vector<int>> a(m);
  vector<int> n(m);
  map<int, int> cnt;
  for (int i = 0; i < m; i++) {
    cin >> n[i];
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      cnt[a[i][j]] += 1;
    }
  }
  for (auto x : cnt) {
    if (x.second & 1) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  vector<int> v;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      v.push_back(a[i][j]);
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
    }
  } 
  int k = (int) v.size();
  vector<vector<pair<int, int>>> g(m + k);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n[i]; j++) {
      g[i].emplace_back(a[i][j] + m, g[a[i][j] + m].size());
      g[a[i][j] + m].emplace_back(i, g[i].size() - 1);  
    }
  } 
  vector<string> ans(m);
  for (int i = 0; i < m; i++) {
    ans[i] = string(n[i], 'L');
  }
  vector<int> nxt(m + k);
  function<void(int)> Dfs = [&](int u) {
    while (nxt[u] < (int) g[u].size()) {
      if (g[u][nxt[u]].first == -1) {
        nxt[u] += 1;
        continue;
      } 
      int to = g[u][nxt[u]].first;
      int pos = g[u][nxt[u]].second;
      g[to][pos].first = -1;
      g[to][pos].second = -1;
      nxt[u] += 1;
      if (to < m) {
        ans[to][pos] = 'R';
      }
      Dfs(to);
    }
  };
  for (int i = 0; i < m; i++) {
    Dfs(i);
  }
  cout << "YES" << '\n';
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }                                                   
  return 0;
}