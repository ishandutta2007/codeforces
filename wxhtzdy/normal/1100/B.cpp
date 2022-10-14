#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> pos[n + 1]; 
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  int mn = m;
  for (int i = 1; i <= n; i++) {
    mn = min(mn, (int) pos[i].size());
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < mn; j++) {
      if (i == 1) {
        mp[j] = pos[i][j];
      }
      mp[j] = max(mp[j], pos[i][j]);
    }
  }
  vector<int> ans(m, 0);
  for (int i = 0; i < mn; i++) {
    ans[mp[i]] = 1;    
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i];
  }
  return 0;
}