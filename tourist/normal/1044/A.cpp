/**
 *    author:  tourist
 *    created: 04.11.2018 21:13:46       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.push_back((int) 1e9);
  vector<int> cut(n + 2, 0);
  for (int i = 0; i < m; i++) {
    int xa, xb, y;
    cin >> xa >> xb >> y;
    if (xa == 1) {
      int to = (int) (upper_bound(a.begin(), a.end(), xb) - a.begin());
      cut[to]++;
    }
  }
  for (int i = n + 1; i > 0; i--) {
    cut[i - 1] += cut[i];
  }
  int ans = (int) 1e9;
  for (int i = 1; i <= n + 1; i++) {
    ans = min(ans, i - 1 + cut[i]);
  }
  cout << ans << '\n';
  return 0;
}