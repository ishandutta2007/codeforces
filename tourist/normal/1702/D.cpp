/**
 *    author:  tourist
 *    created: 10.07.2022 18:39:11       
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
    string s;
    cin >> s;
    int p;
    cin >> p;
    int n = (int) s.size();
    vector<vector<int>> at(26);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int c = (int) (s[i] - 'a');
      sum += c + 1;
      at[c].push_back(i);
    }
    vector<bool> rem(n, false);
    for (int i = 25; i >= 0; i--) {
      while (sum > p && !at[i].empty()) {
        rem[at[i].back()] = true;
        at[i].pop_back();
        sum -= i + 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!rem[i]) {
        cout << s[i];
      }
    }
    cout << '\n';
  }
  return 0;
}