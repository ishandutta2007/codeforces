/**
 *    author:  tourist
 *    created: 06.09.2022 17:36:50       
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
    if (m < n) {
      cout << "No" << '\n';
      continue;
    }
    if (n % 2 == 1) {
      cout << "Yes" << '\n';
      cout << m - n + 1;
      for (int i = 1; i < n; i++) {
        cout << " " << 1;
      }
      cout << '\n';
      continue;
    }
    if (m % 2 == 1) {
      cout << "No" << '\n';
      continue;
    }
    cout << "Yes" << '\n';
    cout << 1 + (m - n) / 2 << " " << 1 + (m - n) / 2;
    for (int i = 2; i < n; i++) {
      cout << " " << 1;
    }
    cout << '\n';
  }
  return 0;
}