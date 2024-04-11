/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 17:28:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int>> g(n);
  vector<bool> can(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (y == p[n - 1]) {
      can[x] = true;
    }
    g[y].push_back(x);
  }
  int ans = 0;
  vector<int> cnt(n);
  int cc = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (can[p[i]] && cnt[p[i]] == cc) {
      ans += 1;
    } else {
      cc += 1;
      for (int j : g[p[i]]) {
        cnt[j]++;
      }
    }   
  }
  cout << ans << '\n';                                     
  return 0;
}