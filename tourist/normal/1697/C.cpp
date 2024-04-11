/**
 *    author:  tourist
 *    created: 12.06.2022 18:37:06       
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
    string s, t;
    cin >> s >> t;
    vector<int> ns(1, 0);
    vector<int> nt(1, 0);
    string cs, ct;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'b') {
        cs += s[i];
        ns.push_back(0);
      } else {
        ns.back() += 1;
      }
      if (t[i] != 'b') {
        ct += t[i];
        nt.push_back(0);
      } else {
        nt.back() += 1;
      }
    }
    int sum = 0;
    bool ok = true;
    if (cs == ct) {
      for (int i = 0; i < (int) ns.size() - 1; i++) {
        sum += ns[i] - nt[i];
        if (sum > 0 && cs[i] == 'a') {
          ok = false;
          break;
        }
        if (sum < 0 && cs[i] == 'c') {
          ok = false;
          break;
        }
      }
    }
    cout << (ok && cs == ct ? "YES" : "NO") << '\n';
  }
  return 0;
}