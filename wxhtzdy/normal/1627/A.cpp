#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    --r; --c;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'B') {
          cnt += 1;
        }
      }
    }
    if (cnt == 0) {
      cout << -1 << '\n';
      continue;
    }
    if (s[r][c] == 'B') {
      cout << 0 << '\n';
      continue;
    }
    int ans = 2;
    for (int i = 0; i < n; i++) {
      if (s[i][c] == 'B') {
        ans = 1;
      }
    }
    for (int i = 0; i < m; i++) {
      if (s[r][i] == 'B') {
        ans = 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}