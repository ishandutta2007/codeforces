/**
 *  author: milos
 *  created: 05.01.2021 15:39:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v.push_back({a[i], 1});
    }
    long long ans = 0;
    for (int i = 0; i < (int) v.size(); i++) {
      if (v[i].first % x == 0)  {
        v.push_back({v[i].first / x, v[i].second * x});
      } else {
        break;
      }
    }
    for (int i = 0; i < (int) v.size(); i++) {
      ans += v[i].first * (long long) v[i].second;
    }
    cout << ans << '\n';
  }
  return 0;
}