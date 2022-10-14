#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<bool> ok(4, false);
    for (int j = 0; j < n; j++) {
      if (x[i] == x[j] && y[i] > y[j]) ok[0] = 1;
      if (x[i] == x[j] && y[i] < y[j]) ok[1] = 1;
      if (x[i] < x[j] && y[i] == y[j]) ok[2] = 1;
      if (x[i] > x[j] && y[i] == y[j]) ok[3] = 1;
    }
    bool valid = true;
    for (int j = 0; j < 4; j++) {
      if (!ok[j]) {
        valid = false;
      }
    }
    if (valid) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}