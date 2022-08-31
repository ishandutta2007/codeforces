/**
 *    author:  tourist
 *    created: 23.05.2022 18:37:07       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = make_pair(a[i], b[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int>> res;
    bool fail = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        if (p[j] == make_pair(a[i], b[i])) {
          swap(p[i], p[j]);
          if (i != j) {
            res.emplace_back(i, j);
          }
          break;
        }
      }
      if (p[i] != make_pair(a[i], b[i])) {
        fail = true;
        break;
      }
    }
    if (fail) {
      cout << -1 << '\n';
    } else {
      cout << res.size() << '\n';
      for (auto& p : res) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
      }
    }
  }
  return 0;
}