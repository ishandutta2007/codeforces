/**
 *    author:  tourist
 *    created: 03.04.2021 18:02:15       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += c[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int mx = 0;
  for (int i = 0; i < n - 1; i++) {
    mx = max(mx, a[order[i]] + c[order[i]]);
    if (mx < a[order[i + 1]]) {
      ans += a[order[i + 1]] - mx;
    }
  }
  cout << ans << '\n';
  return 0;
}