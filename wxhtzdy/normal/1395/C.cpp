/**
 *  author: milos
 *  created: 27.12.2020 18:40:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < (1 << 9); i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      bool f = false;
      for (int k = 0; k < m; k++) {
        if (((a[j] & b[k]) | i) == i) {
          f = true;
        }
      }
      if (!f) {
        ok = false;
      }
    }
    if (ok) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 512 << '\n';
  return 0;
}