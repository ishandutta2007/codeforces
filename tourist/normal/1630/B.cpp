/**
 *    author:  tourist
 *    created: 27.01.2022 17:43:09       
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto b = a;
    sort(b.begin(), b.end());
    int in = (n + k + 1) / 2;
    int x = -1, y = n + 1;
    for (int i = 0; i <= n - in; i++) {
      int L = b[i];
      int R = b[i + in - 1];
      if (R - L < y - x) {
        x = L;
        y = R;
      }
    }
    cout << x << " " << y << '\n';
    int last = -1;
    int mx = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur += (x <= a[i] && a[i] <= y ? +1 : -1);
      if (cur > mx) {
        mx = cur;
        if (cur >= 1 && cur <= k - 1) {
          cout << last + 2 << " " << i + 1 << '\n';
          last = i;
        }
      }
    }
    cout << last + 2 << " " << n << '\n';
  }
  return 0;
}