/**
 *  author: milos
 *  created: 14.01.2021 22:49:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n = 9;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    auto ans = s;
    for (int i = 0; i < n; i++) {
      int j = i / 3 + i % 3 * 3;
      if (i == n - 1 && j == n - 1) {
        ans[i][j] = s[i - 1][j];
      } else {
        ans[i][j] = ans[i + 1][j];
      }
    }
    for (auto c : ans) {
      for (auto r : c) {
        cout << r;
      }
      cout << '\n';
    }
  }
  return 0;
}