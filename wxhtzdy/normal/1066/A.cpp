/**
 *  author: milos
 *  created: 15.01.2021 02:31:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    cout << L / v - r / v + (l - 1) / v << '\n';
  }
  return 0;
}