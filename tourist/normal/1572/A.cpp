/**
 *    author:  tourist
 *    created: 18.09.2021 17:31:31       
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
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      while (x--) {
        int j;
        cin >> j;
        --j;
        g[j].push_back(i);
        deg[i] += 1;
      }
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        s.insert(i);
      }
    }
    int last = -1;
    int ans = 1;
    for (int iter = 0; iter < n; iter++) {
      if (s.empty()) {
        ans = -1;
        break;
      }
      auto it = s.lower_bound(last);
      if (it == s.end()) {
        ans += 1;
        it = s.begin();
      }
      int i = *it;
      s.erase(it);
      for (int j : g[i]) {
        --deg[j];
        if (deg[j] == 0) {
          s.insert(j);
        }
      }
      last = i;
    }
    cout << ans << '\n';
  }
  return 0;
}