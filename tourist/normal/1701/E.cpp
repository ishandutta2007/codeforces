/**
 *    author:  tourist
 *    created: 08.07.2022 18:52:09       
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
    cin >> n >> m;
    string s;
    string t;
    cin >> s >> t;
    int ptr = 0;
    int pref = 0;
    for (int i = 0; i < n; i++) {
      if (ptr < m && s[i] == t[ptr]) {
        if (i == ptr) {
          pref += 1;
        }
        ptr += 1;
      }
    }
    if (ptr < m) {
      cout << -1 << '\n';
      continue;
    }
    int ans = n - pref;
    const int inf = (int) 1e9;
    vector<int> d0(m + 1, inf);
    vector<int> d1(m + 1, inf);
    vector<int> d2(m + 1, inf);
    d0[0] = d1[0] = d2[0] = 0;
    for (char c : s) {
      vector<int> f0(m + 1, inf);
      vector<int> f1(m + 1, inf);
      vector<int> f2(m + 1, inf);
      for (int i = 0; i <= m; i++) {
        f0[i] = min(f0[i], d0[i] + 2);
        f2[i] = min(f2[i], d2[i] + 1);
        if (i < m && c == t[i]) {
          f0[i + 1] = min(f0[i + 1], d0[i] + 1);
          f1[i + 1] = min(f1[i + 1], d1[i]);
          f2[i + 1] = min(f2[i + 1], d2[i] + 1);
        }
      }
      for (int i = 0; i <= m; i++) {
        f1[i] = min(f1[i], f0[i]);
        f2[i] = min(f2[i], f1[i]);
      }
      swap(d0, f0);
      swap(d1, f1);
      swap(d2, f2);
    }
    ans = min(ans, d2[m] + 1);
    cout << ans << '\n';
  }
  return 0;
}