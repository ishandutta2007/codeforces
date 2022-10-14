/**
 *  author: milos
 *  created: 07.01.2021 23:18:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(b, a);
    if (b < c) swap(b, c);
    if (a < c) swap(a, c);
    if (a < b) swap(b, a);
    if (b < c) swap(b, c);
    if (a < c) swap(a, c);
    if (a >= b + c) {
      cout << b + c << '\n';
    } else {
      cout << (a + b + c) / 2 << '\n';
    }
  }
  return 0;
}