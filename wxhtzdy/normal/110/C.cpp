/**
 *  author: milos
 *  created: 13.12.2020 15:38:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i <= n / 4; i++) {
    int x = n - i * 4;
    if (x % 7 == 0) {
      for (int j = 0; j < i; j++) {
        cout << 4;
      }
      for (int j = 0; j < x / 7; j++) {
        cout << 7;
      }
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}