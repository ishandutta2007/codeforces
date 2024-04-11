/**
 *    author:  tourist
 *    created: 19.05.2022 18:38:12       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> a[i][j];
      }
    }
    int x = -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w - 1; j++) {
        if (a[i][j] > a[i][j + 1]) {
          x = j;
        }
      }
    }
    if (x == -1) {
      cout << "1 1" << endl;
      continue;
    }
    auto Flag = [&](int i, int j) {
      if (i >= 0 && j >= 0 && i < h && j < w - 1 && a[i][j] > a[i][j + 1]) {
        return 1;
      }
      return 0;
    };
    vector<int> cnt(h);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w - 1; j++) {
        cnt[i] += Flag(i, j);
      }
    }
    int a0 = -1, a1 = -1;
    for (int j0 = x; j0 <= x + 1; j0++) {
      for (int j1 = 0; j1 < w; j1++) {
        if (j0 == j1) {
          continue;
        }
        bool inv = false;
        if (j0 > j1) {
          swap(j0, j1);
          inv = true;
        }
        bool ok = true;
        for (int i = 0; i < h; i++) {
          int cc = cnt[i];
          if (j0 + 1 == j1) {
            cc -= Flag(i, j0 - 1);
            cc -= Flag(i, j0);
            cc -= Flag(i, j0 + 1);
            swap(a[i][j0], a[i][j1]);
            cc += Flag(i, j0 - 1);
            cc += Flag(i, j0);
            cc += Flag(i, j0 + 1);
            swap(a[i][j0], a[i][j1]);
          } else {
            cc -= Flag(i, j0 - 1);
            cc -= Flag(i, j0);
            cc -= Flag(i, j1 - 1);
            cc -= Flag(i, j1);
            swap(a[i][j0], a[i][j1]);
            cc += Flag(i, j0 - 1);
            cc += Flag(i, j0);
            cc += Flag(i, j1 - 1);
            cc += Flag(i, j1);
            swap(a[i][j0], a[i][j1]);
          }
          assert(cc >= 0);
          if (cc > 0) {
            ok = false;
            break;
          }
        }
        if (ok) {
          a0 = j0;
          a1 = j1;
        }
        if (inv) {
          swap(j0, j1);
        }
      }
    }
    if (a0 == -1) {
      cout << -1 << '\n';
    } else {
      cout << a0 + 1 << " " << a1 + 1 << '\n';
    }
  }
  return 0;
}