#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
      pos[s[i] - 'a'].push_back(i);
    }
    int lst = n;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      int c = (int) (t[i] - 'a');
      if (pos[c].empty()) {
        ans = -1;
        break;
      }
      if (pos[c].back() > lst) {
        lst = *lower_bound(pos[c].begin(), pos[c].end(), lst + 1);
      } else {
        lst = pos[c][0];
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}