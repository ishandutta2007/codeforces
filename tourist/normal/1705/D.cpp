/**
 *    author:  tourist
 *    created: 15.07.2022 18:05:04       
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
    string a;
    cin >> a;
    string b;
    cin >> b;
    auto Process = [&](string s) {
      vector<int> ret;
      for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
          ret.push_back(i);
        }
      }
      return ret;
    };
    vector<int> x = Process(a);
    vector<int> y = Process(b);
    if (x.size() != y.size() || a[0] != b[0] || a[n - 1] != b[n - 1]) {
      cout << -1 << '\n';
      continue;
    }
    long long ans = 0;
    for (int i = 0; i < (int) x.size(); i++) {
      ans += abs(x[i] - y[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}