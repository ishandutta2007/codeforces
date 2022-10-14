#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  const int MAX = 2e5 + 5;
  vector<vector<int>> pref(MAX, vector<int>(25));
  for (int i = 1; i < MAX; i++) {
    for (int j = 0; j < 25; j++) {
      pref[i][j] = pref[i - 1][j];
      if (i & (1 << j)) {
        pref[i][j] += 1;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    for (int i = 0; i < 25; i++) {
      ans = min(ans, r - l + 1 - pref[r][i] + pref[l - 1][i]);
    }
    cout << ans << '\n';
  }                                             
  return 0;
}