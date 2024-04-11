/**
 *    author:  tourist
 *    created: 16.07.2022 18:34:54       
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int low = 0;
    int high = n;
    while (low < high) {
      int mid = (low + high) >> 1;
      int now = q;
      bool ok = true;
      for (int i = mid; i < n; i++) {
        if (now == 0) {
          ok = false;
          break;
        }
        if (a[i] > now) {
          now -= 1;
        }
      }
      if (ok) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    for (int i = 0; i < low; i++) {
      cout << (a[i] <= q ? 1 : 0);
    }
    for (int i = low; i < n; i++) {
      cout << 1;
    }
    cout << '\n';
  }
  return 0;
}