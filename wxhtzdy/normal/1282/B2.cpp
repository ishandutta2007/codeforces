#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i < k + 1; i++) {
      long long S = sum;
      for (int j = i + k - 1; j < n; j += k) {
        S += a[j];
        if (S > p) {
          break;
        }
        ans = max(ans, j + 1);
      }
      if (sum <= p) {
        ans = max(ans, i);
      }
      if (i < n) {
        sum += a[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}