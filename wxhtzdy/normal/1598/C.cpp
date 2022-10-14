/**
 *    author: m371
 *    created: 10.10.2021 11:06:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // sum / n = (sum - a[i] - a[j]) / (n - 2)
  // sum * (n - 2) = (sum - a[i] - a[j]) * n
  // sum * (n - 2) = sum * n - a[i] * n - a[j] * n
  // - 2 * sum = - a[i] * n - a[j] * n
  // a[i] * n = 2 * sum - a[j] * n
  // a[j] * n = a[i] * n - 2 * sum
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long s = accumulate(a.begin(), a.end(), 0LL);
    map<long long, int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += cnt[2 * s - a[i] * n];
      cnt[a[i] * n]++;
    }
    cout << ans << '\n';
  }
  return 0;
}