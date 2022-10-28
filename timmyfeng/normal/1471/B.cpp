#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      int y = a[i];
      while (y % x == 0) {
        y /= x;
        ++b[i];
      }
    }
    int j = min_element(b.begin(), b.end()) - b.begin();
    long long ans = accumulate(a.begin(), a.end(), 0LL) * (b[j] + 1);
    for (int i = 0; i < j; ++i) {
      ans += a[i];
    }
    cout << ans << "\n";
  }
}