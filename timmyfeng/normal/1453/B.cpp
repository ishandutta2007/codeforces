#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
      sum += abs(a[i] - a[i + 1]);
    }

    long long ans = sum;
    for (int i = 0; i < n; ++i) {
      long long res = sum;
      if (i > 0) {
        res -= abs(a[i] - a[i - 1]);
      }
      if (i < n - 1) {
        res -= abs(a[i] - a[i + 1]);
      }
      if (i > 0 && i < n - 1) {
        res += abs(a[i - 1] - a[i + 1]);
      }
      ans = min(ans, res);
    }

    cout << ans << "\n";
  }
}