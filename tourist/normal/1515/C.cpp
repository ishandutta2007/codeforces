/**
 *    author:  tourist
 *    created: 02.05.2021 17:38:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++) {
      s.emplace(0, i);
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      auto it = s.begin();
      int w = it->first;
      int id = it->second;
      cout << id + 1;
      w += h[i];
      s.erase(it);
      s.emplace(w, id);
    }
    cout << '\n';
  }
  return 0;
}