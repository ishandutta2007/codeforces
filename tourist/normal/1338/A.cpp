/**
 *    author:  tourist
 *    created: 12.04.2020 17:04:48       
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
    int val = 0;
    int mx = (int) -2e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mx = max(mx, a);
      val = max(val, mx - a);
    }
    long long res = 0;
    while ((1LL << res) - 1 < val) {
      ++res;
    }
    cout << res << '\n';
  }
  return 0;
}