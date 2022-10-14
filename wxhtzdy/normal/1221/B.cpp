/**
 *  author: milos
 *  created: 02.01.2021 00:34:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        cout << 'B';
      } else {
        cout << 'W';
      }
    }
    cout << '\n';
  }
  return 0;
}