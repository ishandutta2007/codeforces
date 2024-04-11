/**
 *  author: milos
 *  created: 16.12.2020 01:55:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  for (auto c : a) {
    if (c.first >= m) {
      cout << "NO" << '\n';
      return 0;
    }
    m += c.second;
  }
  cout << "YES" << '\n';
  return 0;
}