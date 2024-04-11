#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << a[l] - 1 + k - a[r] + (a[r] - a[l] - r + l) * 2 << '\n';
  }
  return 0;
}