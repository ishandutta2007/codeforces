/**
 *    author:  tourist
 *    created: 04.07.2020 17:47:05       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    bool ok = true;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int limit = 0;
        if (i > 0) ++limit;
        if (i < h - 1) ++limit;
        if (j > 0) ++limit;
        if (j < w - 1) ++limit;
        int x;
        cin >> x;
        if (x > limit) {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (j > 0) {
            cout << " ";
          }
          int limit = 0;
          if (i > 0) ++limit;
          if (i < h - 1) ++limit;
          if (j > 0) ++limit;
          if (j < w - 1) ++limit;
          cout << limit;
        }
        cout << '\n';
      }
    }
  }
  return 0;
}