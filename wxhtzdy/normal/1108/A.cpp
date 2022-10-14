/**
 *  author: milos
 *  created: 06.01.2021 19:50:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 != l2) {
      cout << l1 << " " << l2 << '\n';
    } else {
      if (l1 != r2) {
        cout << l1 << " " << r2 << '\n';
      } else { 
        if (r1 != l2) {
          cout << r1 << " " << l2 << '\n';
        } else {
          if (r1 != r2) {
            cout << r1 << " " << r2 << '\n';
          } else {
            cout << l1 + 1 << " " << r1 << '\n';
          }
        }
      }
    }
  }
  return 0;
}