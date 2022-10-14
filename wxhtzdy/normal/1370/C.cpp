/**
 *  author: milos
 *  created: 27.09.2020 13:34:31
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
    bool ok = false;
    if (n == 1) {
      ok = true;
    }                      
    for (int i = 2; i < 31; i++) {
      if ((1 << i) == n) {
        ok = true;
        break;
      }
    }
    auto Prime = [&](int k) {
      if (k < 3 || k % 2 == 0) {
        return false;
      }
      for (int i = 3; i <= sqrt(k); i++) {
        if (k % i == 0) {
          return false;
        }
      }
      return true;
    };
    if (n % 2 == 0 && Prime(n / 2)) {
      ok = true;  
    }
    if (ok) {
      cout << "FastestFinger" << '\n';
    } else {
      cout << "Ashishgup" << '\n';
    }
  }
  return 0;
}