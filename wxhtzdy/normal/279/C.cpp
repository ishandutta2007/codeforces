#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> x(n), y(n);
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || a[i] > a[i + 1]) x[i] = i;
    else x[i] = x[i + 1];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i] > a[i - 1]) y[i] = i;
    else y[i] = y[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << (x[l] >= y[r] ? "Yes" : "No") << '\n';
  }
  return 0;
}