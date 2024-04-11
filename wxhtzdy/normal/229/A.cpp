#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        pos[i].push_back(j);
      }
    }
  }
  vector<int> sz(n);
  for (int i = 0; i < n; i++) {
    if (pos[i].empty()) {
      cout << -1 << '\n';
      return 0;
    }
    sz[i] = (int) pos[i].size();
  }
  vector<int> nxt(n);
  int ans = 1e9;
  for (int j = 0; j < m; j++) {
    int nans = 0;
    for (int i = 0; i < n; i++) {
      int x = pos[i][nxt[i]];
      int y = pos[i][(nxt[i] - 1 + sz[i]) % sz[i]];
      int tmp = min({abs(x - j), min(x, j) + m - max(x, j), abs(y - j), min(y, j) + m - max(y, j)});
      if (s[i][j] == '1') {
        nxt[i]++;
        nxt[i] %= sz[i];
      }
      nans += tmp;
    }
    ans = min(ans, nans);
  }
  cout << ans << '\n';
  return 0;
}