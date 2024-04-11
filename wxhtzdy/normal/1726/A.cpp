#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n; i++) {
      ans = max(ans, a[(i + n - 1) % n] - a[i]);
    }
    for (int i = 1; i < n; i++) {
      ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, a[n - 1] - a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}