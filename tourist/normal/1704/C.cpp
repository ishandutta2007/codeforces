/**
 *    author:  tourist
 *    created: 31.07.2022 17:11:44       
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
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 0; i < n; i++) {
      int diff = a[(i + 1) % n] - a[i];
      if (diff <= 0) {
        diff += m;
      }
      b.push_back(diff - 1);
    }
    sort(b.rbegin(), b.rend());
    debug(b);
    int safe = 0;
    for (int i = 0; i < n; i++) {
      int num = b[i] - 4 * i;
      if (num >= 1) {
        safe += max(1, num - 1);
      }
    }
    cout << m - safe << '\n';
  }
  return 0;
}