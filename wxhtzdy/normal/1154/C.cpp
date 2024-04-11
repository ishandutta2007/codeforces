#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  vector<int> b;
  b.push_back(0);
  b.push_back(1);
  b.push_back(2);
  b.push_back(0);
  b.push_back(2);
  b.push_back(1);
  b.push_back(0);
  int ans = 0;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      vector<int> cnt(3, 0);
      if (i <= j) {
        for (int k = i; k <= j; k++) {
          cnt[b[k]] += 1;
        }
        vector<int> x(3, 0);
        bool ok = true;
        for (int k = 0; k < 3; k++) {
          x[k] = a[k] - cnt[k];
          if (x[k] < 0) {
            ok = false;
          }
        }
        if (!ok) {
          continue;
        }
        ans = max(ans, min({x[0] / 3, x[1] / 2, x[2] / 2}) * 7 + j - i + 1);
      } else {
        for (int k = i; k < 7; k++) {
          cnt[b[k]] += 1;
        }
        for (int k = 0; k <= j; k++) {
          cnt[b[k]] += 1;
        }
        vector<int> x(3, 0);
        bool ok = true;
        for (int k = 0; k < 3; k++) {
          x[k] = a[k] - cnt[k];
          if (x[k] < 0) {
            ok = false;
          }
        }
        if (!ok) {
          continue;
        }
        ans = max(ans, min({x[0] / 3, x[1] / 2, x[2] / 2}) * 7 + 7 - i + j + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}