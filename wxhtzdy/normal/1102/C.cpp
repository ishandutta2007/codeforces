#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    cout << n << '\n';
    return 0;
  }
  int ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) {
      ans += 1;
    }
  }
  cout << (ans + 1) / 2 << '\n';
  return 0;
}