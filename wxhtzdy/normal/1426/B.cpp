/**
 *  author: milos
 *  created: 02.01.2021 13:12:24
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
    vector<int> a(2 * n), b(2 * n);
    bool ok = false;
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i] >> b[i];
    }
    for (int i = 1; i < 2 * n; i += 2) {
      if (a[i] == b[i - 1]) {
        ok = true;
      }
    }
    if (m % 2 == 1) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}