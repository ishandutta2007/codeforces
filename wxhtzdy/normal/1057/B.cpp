/**
 *  author: milos
 *  created: 15.01.2021 01:58:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (sum > (j - i + 1) * 100) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}