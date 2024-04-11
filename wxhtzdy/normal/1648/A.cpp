#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  const int MAX = 1e5 + 5;
  vector<vector<int>> cx(MAX);
  vector<vector<int>> cy(MAX);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      cx[x].push_back(i);
      cy[x].push_back(j);
    }
  }
  long long ans = 0;
  {
    for (int i = 0; i < MAX; i++) {
      sort(cx[i].begin(), cx[i].end());
      long long tot = 0;
      long long cnt = 0;
      for (int j : cx[i]) {
        ans += (cnt * 1LL * j - tot);
        tot += j;
        cnt += 1;
      }
    }
  }
  {
    for (int i = 0; i < MAX; i++) {
      sort(cy[i].begin(), cy[i].end());
      long long tot = 0;
      long long cnt = 0;
      for (int j : cy[i]) {
        ans += (cnt * 1LL * j - tot);
        tot += j;
        cnt += 1;
      }
    }
  }
  cout << ans << '\n';                                                                
  return 0;
}