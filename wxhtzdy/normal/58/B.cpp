/**
 *  author: milos
 *  created: 13.12.2020 14:40:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n > 1) {
    bool ok = 0;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        ok = 1;
        cout << n << " ";
        n /= i;
        break;
      }
    }
    if (!ok) {
      cout << n << " ";
      n = 1;
      break;
    }
  }
  cout << 1 << '\n';
  return 0;
}