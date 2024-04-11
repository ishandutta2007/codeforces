/**
 *  author: milos
 *  created: 13.09.2020 18:32:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long ans = (long long) n * n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> a(m);
    for (int j = 0; j < m; j++) {
      cin >> a[j];
    }
    bool ok = true;
    for (int j = 0; j < m - 1; j++) {
      ok &= a[j] >= a[j + 1];
    }
    if (ok) {
      v.emplace_back(a[0], -1);
      v.emplace_back(a[m - 1], 1);
    }
  }
  sort(v.begin(), v.end());
  int balance = 0;
  for (auto p : v) {
    if (p.second == -1) {
      balance++;
    } else {
      ans -= balance;
    }
  }
  cout << ans << '\n';
  return 0;
}