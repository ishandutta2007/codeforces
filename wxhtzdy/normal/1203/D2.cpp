#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = (int) s.size(), m = (int) t.size();
  vector<int> pos(m);
  int j = n;
  for (int i = m - 1; i >= 0; i--) {
    --j;
    while (s[j] != t[i]) {
      --j;
    }
    pos[i] = j;
  }
  //for (int i = 0; i < m; i++) cout << pos[i] << " ";
  int ans = 0;
  j = 0;
  for (int i = 0; i < n; i++) {
    if (j < m) {
      ans = max(ans, pos[j] - i);
    } else {
      ans = max(ans, n - i);
    }
    if (j < m && t[j] == s[i]) {
      ++j;
    }
  }
  cout << ans << '\n';
  return 0;
}