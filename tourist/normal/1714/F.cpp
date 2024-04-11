/**
 *    author:  tourist
 *    created: 01.08.2022 17:45:53       
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
    int n, d01, d12, d02;
    cin >> n >> d01 >> d12 >> d02;
    int diff = d12 + d02 - d01;
    if (diff < 0 || diff % 2 != 0) {
      cout << "NO" << '\n';
      continue;
    }
    diff /= 2;
    int vers = d01 + 1 + diff;
    if (vers > n) {
      cout << "NO" << '\n';
      continue;
    }
    if (d02 - diff < 0 || d02 - diff > d01) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<int> seq(d01 + 1);
    seq[0] = 0;
    seq[d01] = 1;
    int idx = 3;
    for (int i = 1; i < d01; i++) {
      if (diff == 0 && i == d02) {
        seq[i] = 2;
      } else {
        seq[i] = idx++;
      }
    }
    for (int i = 0; i < d01; i++) {
      cout << seq[i] + 1 << " " << seq[i + 1] + 1 << '\n';
    }
    if (diff > 0) {
      int ver = seq[d02 - diff];
      while (diff > 1) {
        cout << ver + 1 << " " << idx + 1 << '\n';
        ver = idx;
        diff -= 1;
        idx++;
      }
      cout << ver + 1 << " " << 3 << '\n';
    }
    while (idx < n) {
      cout << 3 << " " << idx + 1 << '\n';
      idx += 1;
    }
  }
  return 0;
}