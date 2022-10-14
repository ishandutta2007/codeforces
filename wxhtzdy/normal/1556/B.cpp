/**
 *    author:  milos
 *    created: 28.08.2021 21:02:21       
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
    vector<int> a(n);
    vector<vector<int>> x(2);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      x[a[i] % 2].push_back(i);
    }
    if (abs((int) x[0].size() - (int) x[1].size()) > 1) {
      cout << -1 << '\n';
      continue;
    }      
    const long long inf = 1e18;
    long long ans = inf;
    for (int j = 0; j < 2; j++) {
      if ((int) x[j].size() != (n + 1) / 2) {
        continue;  
      }
      long long cnt = 0;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          cnt += abs(i - x[j][i / 2]);
        } else {
          cnt += abs(i - x[j ^ 1][i / 2]);
        }
      }
      ans = min(ans, cnt / 2);
    }                 
    cout << ans << '\n';
  }
  return 0;
}