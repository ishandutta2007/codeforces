/**
 *    author:  tourist
 *    created: 27.12.2021 17:34:45       
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
    if (a == b + c || b == c + a || c == a + b) {
      cout << "YES" << '\n';
    } else {
      if ((a == b && c % 2 == 0) || (a == c && b % 2 == 0) || (b == c && a % 2 == 0)) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}