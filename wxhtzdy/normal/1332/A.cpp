/**
 *  author: milos
 *  created: 02.10.2020 21:13:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    x -= a - b;
    y -= c - d;
    bool ok = true;
    if (a == b && a > 0 && x1 == x && x2 == x) {
      ok = false;
    }
    if (c == d && c > 0 && y1 == y && y2 == y) {
      ok = false;
    }
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && ok) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}