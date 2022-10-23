/**
 *    author:  tourist
 *    created: 07.10.2022 18:22:53       
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
      cnt[(int) (c - 'a')] += 1;
    }
    string res = "";
    for (int i = 0; i < k; i++) {
      int c = 0;
      while (c < n / k && cnt[c] > 0) {
        cnt[c] -= 1;
        c += 1;
      }
      res += (char) (c + 'a');
    }
    cout << res << '\n';
  }
  return 0;
}