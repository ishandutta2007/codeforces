#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  mt19937 rng(time(0));
  long long ans = 0;
  for (int rep = 0; rep < 10; rep++) {
    int i = rng() % n;
    vector<long long> b;
    for (long long j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        b.push_back(j);
        if (j * j != a[i]) {
          b.push_back(a[i] / j);
        }
      }
    }
    sort(b.begin(), b.end());
    vector<int> cnt((int) b.size());
    for (int j = 0; j < n; j++) {
      long long g = __gcd(a[i], a[j]);
      cnt[lower_bound(b.begin(), b.end(), g) - b.begin()]++;
    }
    for (int j = 0; j < (int) b.size(); j++) {
      for (int k = j + 1; k < (int) b.size(); k++) {
        if (b[k] % b[j] == 0) {
          cnt[j] += cnt[k];
        }
      }
      if (cnt[j] * 2 >= n) {
        ans = max(ans, b[j]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}