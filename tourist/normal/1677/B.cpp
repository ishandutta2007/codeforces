/**
 *    author:  tourist
 *    created: 08.05.2022 18:38:06       
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> bal(n * m + 1);
    vector<bool> good(n * m);
    for (int i = 0; i < n * m; i++) {
      good[i] = (s[i] == '1');
      if (i >= m && good[i - m]) {
        good[i] = true;
      }
      if (good[i]) {
        bal[i] += 1;
        if (i + m < n * m) {
          bal[i + m] -= 1;
        }
      }
    }
    vector<int> pref(n * m + 1);
    for (int i = 0; i < n * m; i++) {
      pref[i + 1] = pref[i] + (s[i] == '1');
    }
    vector<int> add(n * m);
    for (int i = 0; i + m <= n * m; i++) {
      if (pref[i + m] - pref[i] > 0) {
        add[i + m - 1] += 1;
      }
    }
    for (int i = 1; i < m; i++) {
      if (pref[i] > 0) {
        add[i - 1] += 1;
      }
    }
    for (int i = 0; i + m < n * m; i++) {
      add[i + m] += add[i];
    }
    for (int i = 0; i < n * m; i++) {
      cout << bal[i] + add[i] << " \n"[i == n * m - 1];
      bal[i + 1] += bal[i];
    }
  }
  return 0;
}