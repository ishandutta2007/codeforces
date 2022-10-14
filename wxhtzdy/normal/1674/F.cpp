/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 16:14:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> cnt(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        cnt[j] += 1;
      }
    }
  }
  int t = accumulate(cnt.begin(), cnt.end(), 0);
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (s[x][y] == '*') {
      cnt[y] -= 1;
      t -= 1;
      s[x][y] = '.';
    } else {
      cnt[y] += 1;
      t += 1;
      s[x][y] = '*';
    }         
    int ans = 0;
    for (int i = 0; i < t / n; i++) {
      ans += n - cnt[i];
    }
    for (int i = 0; i < t % n; i++) {
      ans += (s[i][t / n] == '.' ? 1 : 0);  
    }
    cout << ans << '\n';
  }                                                     
  return 0;
}