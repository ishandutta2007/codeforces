/**
 *  author: milos
 *  created: 13.12.2020 17:42:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n + 1; i++) {
    int diff = abs(n + 1 - i), x = 0;
    for (int j = 1; j <= 2 * n + 1; j++) {
      if (j <= diff) {
        cout << "  ";
      } else {
        cout << x;
        if (j >= n + 1) x--;
        else x++;
        if (x >= 0) cout << " ";
      }
      if (x < 0) break;
    }
    cout << '\n';
  }
  return 0;
}