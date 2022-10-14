#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      ans[i] = max(ans[i], a[i][j]);
    }
  }
  int pos = max_element(ans.begin(), ans.end()) - ans.begin();
  ans[pos] += 1;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}