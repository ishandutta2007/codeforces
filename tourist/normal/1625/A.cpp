/**
 *    author:  tourist
 *    created: 12.01.2022 17:39:39       
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
    int n, l;
    cin >> n >> l;
    vector<vector<int>> cnt(l, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < l; j++) {
        int bit = (x >> j) & 1;
        cnt[j][bit] += 1;
      }
    }
    int y = 0;
    for (int i = 0; i < l; i++) {
      if (cnt[i][1] > cnt[i][0]) {
        y += 1 << i;
      }
    }
    cout << y << '\n';
  }
  return 0;
}