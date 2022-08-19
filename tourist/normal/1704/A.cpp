/**
 *    author:  tourist
 *    created: 31.07.2022 17:04:37       
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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    bool ok = true;
    for (int i = 0; i < m - 1; i++) {
      if (b.back() != a.back()) {
        ok = false;
        break;
      }
      b.pop_back();
      a.pop_back();
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    if (b == "0" && a == string(n - m + 1, '1')) {
      cout << "NO" << '\n';
      continue;
    }
    if (b == "1" && a == string(n - m + 1, '0')) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
  return 0;
}