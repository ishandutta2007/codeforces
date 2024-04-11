/**
 *    author:  tourist
 *    created: 25.12.2020 14:55:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
      cin >> s[i];
    }
    sort(s.begin(), s.end());
    int cnt = abs(a - b) - 1;
    int total = (a < b ? b - 1 : n - b) - 1;
    int u = total - cnt;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      u = max(u + 1, s[i]);
      if (u > total) {
        break;
      }
      ans += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}