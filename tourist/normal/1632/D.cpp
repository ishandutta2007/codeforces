/**
 *    author:  tourist
 *    created: 30.01.2022 21:01:52       
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int covered = -1;
  vector<array<int, 3>> s;
  for (int i = 0; i < n; i++) {
    for (auto& t : s) {
      t[2] = __gcd(t[2], a[i]);
    }
    s.push_back({i, i, a[i]});
    int cnt = 0;
    for (int j = 0; j < (int) s.size(); j++) {
      if (cnt > 0 && s[j][2] == s[cnt - 1][2]) {
        s[cnt - 1][1] = s[j][1];
      } else {
        s[cnt++] = s[j];
      }
    }
    s.resize(cnt);
    for (auto& t : s) {
      int at = i - t[2] + 1;
      if (t[0] <= at && at <= t[1]) {
        if (at > covered) {
          ans += 1;
          covered = i;
        }
      }
    }
    cout << ans << " \n"[i == n - 1];
  }
  return 0;
}