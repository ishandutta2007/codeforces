/**
 *    author:  tourist
 *    created: 16.07.2022 18:37:22       
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    reverse(a.begin(), a.end());
    int k0 = 0;
    while (true) {
      while (!a.empty() && a.back() == 0) {
        a.pop_back();
        k0 += 1;
      }
      if (a.size() == 0) {
        cout << 0 << '\n';
        break;
      }
      if (a.size() == 1) {
        cout << a[0] << '\n';
        break;
      }
      vector<int> b;
      for (int i = 0; i < (int) a.size() - 1; i++) {
        b.push_back(a[i] - a[i + 1]);
      }
      if (k0 > 0) {
        b.push_back(a.back());
        k0 -= 1;
      }
      sort(b.rbegin(), b.rend());
      swap(a, b);
    }
  }
  return 0;
}