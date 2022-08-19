/**
 *    author:  tourist
 *    created: 04.11.2018 21:22:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  int min_x = *min_element(x.begin(), x.end());
  int max_x = *max_element(x.begin(), x.end());
  int min_y = *min_element(y.begin(), y.end());
  int max_y = *max_element(y.begin(), y.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int dx = max(max_x - x[i], x[i] - min_x);
    int dy = max(max_y - y[i], y[i] - min_y);
    ans = max(ans, dx + dy);
  }
  cout << 2 * ans;
  for (int i = 4; i <= n; i++) {
    cout << " " << 2 * (max_x - min_x + max_y - min_y);
  }
  cout << '\n';
  return 0;
}