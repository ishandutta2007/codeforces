/**
 *    author:  tourist
 *    created: 01.08.2022 17:38:11       
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
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int len = (int) t.size();
    vector<int> R(len + 1, -1);
    vector<int> who(len + 1, -1);
    for (int id = 0; id < n; id++) {
      string& w = s[id];
      for (int i = 0; i <= (int) t.size() - (int) w.size(); i++) {
        if (t.substr(i, w.size()) == w) {
          if (i + (int) w.size() > R[i]) {
            R[i] = i + (int) w.size();
            who[i] = id;
          }
        }
      }
    }
    int ans = 0;
    int p = 0;
    vector<pair<int, int>> res;
    while (p < len) {
      int pos = (int) (max_element(R.begin(), R.begin() + p + 1) - R.begin());
      int to = R[pos];
      if (to <= p) {
        ans = -1;
        break;
      }
      res.emplace_back(who[pos], pos);
      ans += 1;
      p = to;
    }
    cout << ans << '\n';
    if (ans != -1) {
      for (auto& u : res) {
        cout << u.first + 1 << " " << u.second + 1 << '\n';
      }
    }
  }
  return 0;
}