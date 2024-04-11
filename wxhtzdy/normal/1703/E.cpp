/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:25:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
        a[i][j] = (int) (s[j] - '0');
      }
    }            
    vector<vector<bool>> was(n, vector<bool>(n));
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < n; j++) {
        if (was[i][j]) {
          continue;
        }
        set<pair<int, int>> cells;
        cells.emplace(i, j);
        cells.emplace(n - 1 - j, i);
        cells.emplace(j, n - 1 - i);
        cells.emplace(n - 1 - i, n - j - 1);
        vector<int> cnt(2);
        for (auto& p : cells) {
          cnt[a[p.first][p.second]] += 1;
          was[p.first][p.second] = true;
        }
        ans += min(cnt[0], cnt[1]);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}