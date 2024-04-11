/**
 *    author:  milos
 *    created: 04.02.2021 14:13:58       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    vector<pair<int, int>> z;
    for (int i = 0; i < m; i++) {
      cin >> x[i] >> y[i];
      z.emplace_back(y[i], x[i]);
    }
    bool ok = true;
    if (m % 2 == 1) {
      ok = false;
    }
    sort(z.begin(), z.end());
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0) {
        continue;
      }
      if (i < m - 1 && z[i].first == z[i + 1].first) {
        ok = false;
      }
      int dx = z[i].first - z[i - 1].first;
      int dy = z[i].second - z[i - 1].second;
      if ((dx + dy + 2) % 2 == 0) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}