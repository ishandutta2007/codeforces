/**
 *    author:  tourist
 *    created: 22.01.2022 17:34:53       
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
    vector<int> res;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    int i = 0;
    while (i < n) {
      int mex = 0;
      while (cnt[mex] > 0) {
        mex += 1;
      }
      vector<bool> seen(mex);
      int cc = 0;
      while (i < n) {
        if (a[i] < mex && !seen[a[i]]) {
          seen[a[i]] = true;
          cc += 1;
        }
        cnt[a[i]] -= 1;
        i += 1;
        if (cc == mex) {
          break;
        }
      }
      res.push_back(mex);
    }
    cout << res.size() << '\n';
    for (int i = 0; i < (int) res.size(); i++) {
      cout << res[i] << " \n"[i == (int) res.size() - 1];
    }
  }
  return 0;
}