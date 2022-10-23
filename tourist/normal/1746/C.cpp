/**
 *    author:  tourist
 *    created: 15.10.2022 18:40:49       
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> all;
    for (int i = 0; i < n - 1; i++) {
      all.emplace_back(a[i] - a[i + 1], i);
    }
    sort(all.begin(), all.end());
    cout << 1;
    for (auto& p : all) {
      cout << " " << p.second + 2;
    }
    cout << '\n';
  }
  return 0;
}