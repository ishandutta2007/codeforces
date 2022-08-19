/**
 *    author:  tourist
 *    created: 16.08.2022 17:39:54       
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
  vector<long long> f = {1, 1};
  while (f.back() < (int) 1e9) {
    auto nxt = f.back() + f[f.size() - 2];
    f.push_back(nxt);
  }
  int sz = (int) f.size();
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long pref = 0;
    int len = -1;
    for (int i = 0; i < sz; i++) {
      pref += f[i];
      if (pref == sum) {
        len = i + 1;
        break;
      }
    }
    if (len == -1) {
      cout << "NO" << '\n';
      continue;
    }
    int last = -1;
    bool ok = true;
    for (int i = len - 1; i >= 0; i--) {
      long long mx = *max_element(a.begin(), a.end());
      if (mx < f[i]) {
        ok = false;
        break;
      }
      int nxt = -1;
      for (int j = 0; j < n; j++) {
        if (a[j] == mx && j != last) {
          nxt = j;
          break;
        }
      }
      if (nxt == -1) {
        ok = false;
        break;
      }
      a[nxt] -= f[i];
      last = nxt;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}