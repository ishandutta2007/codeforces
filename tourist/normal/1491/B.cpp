/**
 *    author:  tourist
 *    created: 28.02.2021 16:36:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if (abs(a[i] - a[i + 1]) > 1) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 0; i < n - 1; i++) {
      if (abs(a[i] - a[i + 1]) == 1) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << min(u, v) << '\n';
      continue;
    }
    cout << v + min(u, v) << '\n';
  }
  return 0;
}