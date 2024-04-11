/**
 *    author:  tourist
 *    created: 30.12.2020 17:36:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    int ans = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && x[end + 1] <= x[end] + 1) {
        ++end;
      }
      ans += min(end - beg + 1, x[end] - x[beg] + 2);
      beg = end + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}