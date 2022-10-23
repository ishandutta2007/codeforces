/**
 *    author:  tourist
 *    created: 07.10.2022 18:41:37       
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
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int r, c;
    cin >> r >> c;
    int r0 = (r1 ^ r2 ^ r3);
    int c0 = (c1 ^ c2 ^ c3);
    vector<pair<int, int>> corners = {{1, 1}, {1, n}, {n, 1}, {n, n}};
    bool found = false;
    for (auto& p : corners) {
      int i = p.first;
      int j = p.second;
      if ((r1 == i && c1 == j) || (r2 == i && c2 == j) || (r3 == i && c3 == j)) {
        if (r0 != i && c0 != j) {
          cout << (r == i || c == j ? "YES" : "NO") << '\n';
          found = true;
          break;
        }
      }
    }
    if (found) {
      continue;
    }
    if (r0 % 2 == r % 2 && c0 % 2 == c % 2) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}