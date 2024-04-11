/**
 *  author: milos
 *  created: 08.01.2021 11:45:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  bool ok = false;
  while (a != -1 || b != -1) {
    if (a == b && a != -1) {
      ok = true;
    }
    if (a == x) {
      a = -1;
    }
    if (b == y) {
      b = -1;
    }
    if (a != -1) {
      a += 1;
      if (a > n) {
        a = 1;
      }
    }
    if (b != -1) {
      b -= 1;
      if (b < 1) {
        b = n;
      }
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}