/**
 *  author: milos
 *  created: 29.09.2020 20:39:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << '\n';
    } else {
      if (a < b) {
        int cnt = 0;
        while (a < b) {
          a *= 2;
          cnt++;  
        }
        if (a == b) {
          cout << (cnt + 2) / 3 << '\n';
        } else {
          cout << -1 << '\n';
        }
      } else {
        int cnt = 0;
        while (a > b && a % 2 == 0) {
          a /= 2;
          cnt++;  
        }
        if (a == b) {
          cout << (cnt + 2) / 3 << '\n';
        } else {
          cout << -1 << '\n';
        }
      }
    }
  }
  return 0;
}