/**
 *    author:  tourist
 *    created: 23.02.2020 19:32:07       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<vector<pair<int, int>>>> inter(n);
  for (int i = 0; i < n; i++) {
    inter[i].resize(n);
    for (int j = 0; j < n; j++) {
      for (int t = 0; t < n; t++) {
        if (i != t && t != j) {
          inter[i][j].emplace_back(a[i][t] + a[t][j], t);
        }
      }
      sort(inter[i][j].begin(), inter[i][j].end());
    }
  }
  vector<int> used(n, 0);
  vector<int> seq(k / 2 + 1, -1);
  seq[0] = seq[k / 2] = 0; 
  int cnt = 1;
  used[0] = 1;
  int ans = (int) 2e9;
  function<void(int)> Dfs = [&](int v) {
    if (v == k / 2) {
      if (cnt == n) {
        return;
      }
      int cur = 0;
      for (int i = 0; 2 * i < k; i++) {
        for (auto& p : inter[seq[i]][seq[i + 1]]) {
          if (!used[p.second]) {
            cur += p.first;
            break;
          }
        }
      }
      ans = min(ans, cur);
      return;
    }
    for (int i = 0; i < n; i++) {
      cnt += !used[i];
      used[i] += 1;
      seq[v] = i;
      Dfs(v + 1);
      seq[v] = -1;
      used[i] -= 1;
      cnt -= !used[i];
    }
  };
  Dfs(1);
  cout << ans << '\n';
  return 0;
}