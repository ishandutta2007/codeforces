/**
 *    author:  tourist
 *    created: 16.06.2022 19:34:44       
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
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end())) {
      cout << 0 << '\n';
      continue;
    }
    while (true) {
      int k0 = 0;
      int k1 = 0;
      for (int i = 0; i < n; i++) {
        k0 += (s[i] == '0');
        k1 += (s[i] == '1');
      }
      if (k0 < k1) {
        reverse(s.begin(), s.end());
        for (char& c : s) {
          c ^= '0' ^ '1';
        }
        continue;
      }
      vector<int> mx(n + 1, -1);
      int bal = 0;
      for (int i = 0; i < n; i++) {
        bal += (s[i] == '0' ? 1 : -1);
        if (bal >= 0) {
          mx[bal] = max(mx[bal], i);
        }
      }
      int ans = 1;
      int cut = 0;
      int to = mx[0];
      while (true) {
        while (s[cut] == '0' && cut < k0 - k1) {
          cut += 1;
          to = max(to, mx[cut]);
        }
        if (cut == k0 - k1) {
          break;
        }
        for (int i = cut, j = to; i < j; i++, j--) {
          s[i] = '0';
          s[j] = '1';
        }
        ans += 1;
      }
      cout << ans << '\n';
      break;
    }
  }
  return 0;
}