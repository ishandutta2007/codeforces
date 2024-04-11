/**
 *    author:  tourist
 *    created: 25.12.2020 15:03:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> x(n + 1);
    vector<int> y(n + 1);
    for (int i = 0; i < n; i++) {
      x[i + 1] = x[i] + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
      y[i + 1] = y[i] + (s[i] == 'D' ? -1 : (s[i] == 'U' ? 1 : 0));
    }
    int bx = 0;
    int by = 0;
    for (int cell = 1; cell <= n; cell++) {
      int mx = 0;
      int my = 0;
      for (char c : s) {
        if (c == 'U') my += 1;
        if (c == 'D') my -= 1;
        if (c == 'L') mx -= 1;
        if (c == 'R') mx += 1;
        if (mx == x[cell] && my == y[cell]) {
          if (c == 'U') my -= 1;
          if (c == 'D') my += 1;
          if (c == 'L') mx += 1;
          if (c == 'R') mx -= 1;
        }
      }
      if (mx == 0 && my == 0) {
        bx = x[cell];
        by = y[cell];
        break;
      }
    }
    cout << bx << " " << by << '\n';
  }
  return 0;
}