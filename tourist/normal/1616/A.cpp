/**
 *    author:  tourist
 *    created: 29.12.2021 18:35:15       
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
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a = abs(a);
      int limit = (a == 0 ? 1 : 2);
      if (mp[a] == limit) {
        continue;
      }
      mp[a] += 1;
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}