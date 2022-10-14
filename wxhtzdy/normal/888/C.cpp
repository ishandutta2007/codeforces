/**
 *  author: milos
 *  created: 16.12.2020 09:37:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.length(), ans = n;
  vector<vector<int>> pos(26);
  for (int i = 0; i < n; i++) {
    pos[(int) (s[i] - 'a')].push_back(i);
  }                                     
  for (int i = 0; i < 26; i++) {
    if ((int) pos[i].size() == 0) {
      continue;
    }
    int tmp = max(pos[i][0] + 1, n - pos[i].back());
    for (int j = 1; j < (int) pos[i].size(); j++) {
      tmp = max(tmp, pos[i][j] - pos[i][j - 1]);
    }
    if (tmp > 0) {
      ans = min(ans, tmp);
    }
  }
  cout << ans << '\n';
  return 0;
}