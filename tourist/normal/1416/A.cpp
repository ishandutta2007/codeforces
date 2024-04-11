/**
 *    author:  tourist
 *    created: 27.09.2020 18:03:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
      pos[a[i]].push_back(i);
    }
    const int inf = (int) 1e9;
    vector<int> ans(n + 1, inf);
    for (int i = 0; i < n; i++) {
      if (pos[i].empty()) {
        continue;
      }
      int mx = pos[i][0];
      for (int j = 0; j < (int) pos[i].size() - 1; j++) {
        mx = max(mx, pos[i][j + 1] - pos[i][j] - 1);
      }
      mx = max(mx, n - 1 - pos[i].back());
      ans[mx + 1] = min(ans[mx + 1], i + 1);
    }
    for (int i = 1; i < n; i++) {
      ans[i + 1] = min(ans[i + 1], ans[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) {
        cout << " ";
      }
      cout << (ans[i] == inf ? -1 : ans[i]);
    }
    cout << '\n';
  }
  return 0;
}