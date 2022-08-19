/**
 *    author:  tourist
 *    created: 24.07.2020 17:42:08       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      x ^= a[i];
    }
    if (x == 0) {
      cout << "DRAW" << '\n';
      continue;
    }
    int bit = 30;
    while (!(x & (1 << bit))) {
      --bit;
    }
    int k0 = 0, k1 = 0;
    for (int y : a) {
      if (y & (1 << bit)) {
        k1 += 1;
      } else {
        k0 += 1;
      }
    }
    assert(k1 % 2 == 1);
    if (k0 % 2 == 0 && k1 % 4 == 3) {
      cout << "LOSE" << '\n';
    } else {
      cout << "WIN" << '\n';
    }
  }
  return 0;
}