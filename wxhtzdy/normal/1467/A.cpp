/**
 *  author: milos
 *  created: 08.01.2021 19:40:52
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
    if (n == 1) {
      cout << 9;
    } else {
      if (n == 2) {
        cout << 98;
      } else {
        cout << 989;
      }
    }
    for (int i = 0; i < n - 3; i++) {
      cout << i % 10;
    }
    cout << '\n';
  }
  return 0;
}