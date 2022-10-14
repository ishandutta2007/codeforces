#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = -1e18;
    for (int i = n - 1; i >= max(0, n - k - 5); i--) {
      for (int j = i - 1; j >= max(0, n - k - 5); j--) {
        ans = max(ans, (i + 1) * 1LL * (j + 1) - k * (a[i] | a[j]));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}