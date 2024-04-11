/**
 *  author: milos
 *  created: 25.08.2020 22:05:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.emplace_back(a[i], i + 1);
  }
  sort(v.rbegin(), v.rend());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += v[i].first * i + 1;
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
  return 0;
}