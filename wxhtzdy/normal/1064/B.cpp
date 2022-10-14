/**
 *  author: milos
 *  created: 15.01.2021 03:20:28
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
    int cnt = 0;
    for (int i = 0; i < 30; i++) {
      if (n & (1 << i)) {
        cnt += 1;
      }
    }
    cout << (1 << cnt) << '\n';
  }
  return 0;
}