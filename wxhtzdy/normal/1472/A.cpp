/**
 *  author: milos
 *  created: 04.01.2021 15:35:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w, n;
    cin >> h >> w >> n;
    int cnt = 1;
    while (h >= 1 || w >= 1) {
      if (h % 2 == 0) {
        h /= 2, cnt *= 2;
      } else {
        if (w % 2 == 0) {
          w /= 2, cnt *= 2;
        } else {
          break;
        }
      }
      if (cnt >= n) {
        break;
      }
    }
    cout << (cnt >= n ? "YES" : "NO") << '\n';
  }
  return 0;
}