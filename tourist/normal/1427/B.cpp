/**
 *    author:  tourist
 *    created: 10.10.2020 17:53:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ls = 0;
    for (char c : s) {
      if (c == 'L') {
        ls += 1;
      }
    }
    vector<int> a;
    int beg = 0;
    int ans = 0;
    while (beg < n) {
      if (s[beg] == 'W') {
        if (beg > 0 && s[beg - 1] == 'W') {
          ans += 2;
        } else {
          ans += 1;
        }
        ++beg;
        continue;
      }
      int end = beg;
      while (end + 1 < n && s[end + 1] == 'L') {
        ++end;
      }
      if (beg != 0 && end != n - 1) {
        a.push_back(end - beg + 1);
      }
      beg = end + 1;
    }
    if (ans == 0) {
      for (int i = 0; i < k; i++) {
        if (i == 0) {
          ans += 1;
        } else {
          ans += 2;
        }
      }
    } else {
      ans += 2 * min(ls, k);
      sort(a.begin(), a.end());
      int take = 0;
      for (int x : a) {
        if (take + x <= k) {
          take += x;
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}