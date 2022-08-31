/**
 *    author:  tourist
 *    created: 08.07.2022 18:40:07       
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
    vector<int> b(n);
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      // floor((i + 1) / a[i]) = b[i]
      // b[i] <= (i + 1) / a[i] < b[i] + 1
      // a[i] <= (i + 1) / b[i]
      // a[i] > (i + 1) / (b[i] + 1)
      R[i] = (b[i] == 0 ? n : (i + 1) / b[i]);
      L[i] = (i + 1) / (b[i] + 1) + 1;
    }
    vector<vector<int>> at(n + 1);
    for (int i = 0; i < n; i++) {
      at[L[i]].push_back(i);
    }
    set<pair<int, int>> s;
    vector<int> p(n, -1);
    for (int i = 1; i <= n; i++) {
      for (int j : at[i]) {
        s.emplace(R[j], j);
      }
      assert(!s.empty());
      p[s.begin()->second] = i;
      s.erase(s.begin());
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}