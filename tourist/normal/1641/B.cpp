/**
 *    author:  tourist
 *    created: 23.02.2022 13:49:47       
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
    vector<pair<int, int>> ops;
    vector<int> lens;
    bool fail = false;
    while (!a.empty()) {
      int n = (int) a.size();
      int i = n - 1;
      int j = i - 1;
      while (j >= 0 && a[j] != a[i]) {
        j -= 1;
      }
      if (j == -1) {
        fail = true;
        break;
      }
      int ptr = j;
      for (int k = i - 1; k >= j + 1; k--) {
        ops.emplace_back(ptr, a[k]);
        ptr += 1;
      }
      lens.push_back(2 * (i - j));
      a.erase(a.begin() + i);
      a.erase(a.begin() + j);
      reverse(a.begin() + j, a.end());
    }
    if (fail) {
      cout << -1 << '\n';
      continue;
    }
    cout << ops.size() << '\n';
    for (auto& op : ops) {
      cout << op.first << " " << op.second << '\n';
    }
    reverse(lens.begin(), lens.end());
    cout << lens.size() << '\n';
    for (int i = 0; i < (int) lens.size(); i++) {
      cout << lens[i] << " \n"[i == (int) lens.size() - 1];
    }
  }
  return 0;
}