/**
 *    author:  tourist
 *    created: 25.12.2020 14:45:59       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> c(3);
    for (int i = 0; i < 3; i++) {
      cin >> c[i];
    }
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
      cin >> a[i];
    }
    c[0] -= a[0];
    c[1] -= a[1];
    c[2] -= a[2];
    if (c[0] < 0 || c[1] < 0 || c[2] < 0) {
      cout << "NO" << '\n';
      continue;
    }
    int x = min(c[0], a[3]);
    c[0] -= x;
    a[3] -= x;
    int y = min(c[1], a[4]);
    c[1] -= y;
    a[4] -= y;
    if (a[3] + a[4] <= c[2]) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}