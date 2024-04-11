/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 13:40:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  int c = 0, xa = n, ya = m, xb = 0, yb = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'X') {
        c += 1;
        xa = min(xa, i);
        ya = min(ya, j);
        xb = max(xb, i);
        yb = max(yb, j);
      }
    }
  }
  cout << (c == (xb - xa + 1) * (yb - ya + 1) ? "YES" : "NO") << '\n';                                                                  
  return 0;
}