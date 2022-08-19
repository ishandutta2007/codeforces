/**
 *    author:  tourist
 *    created: 31.05.2022 18:43:59       
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
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<int> p(n);
    bool ok = true;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && s[end + 1] == s[end]) {
        end += 1;
      }
      if (beg == end) {
        ok = false;
        break;
      }
      p[beg] = end;
      for (int i = beg + 1; i <= end; i++) {
        p[i] = i - 1;
      }
      beg = end + 1;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}