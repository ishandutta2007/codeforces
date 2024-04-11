/**
 *    author:  milos
 *    created: 14.02.2021 19:06:02       
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
    vector<vector<int>> pos(n);
    set<int> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      --x;
      pos[x].push_back(i);
      b.insert(x); 
    }                 
    if ((int) b.size() == n) {
      cout << -1 << '\n';
      continue;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int) pos[i].size() - 1; j++) {
        ans = min(ans, pos[i][j + 1] - pos[i][j] + 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}