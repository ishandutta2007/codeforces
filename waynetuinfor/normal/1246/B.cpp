#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map<vector<pair<int, int>>, int> cnt;
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    int v = a[i];
    vector<pair<int, int>> d, e;
    for (int p = 2; p * p <= v; ++p) {
      int cnt = 0;
      while (v % p == 0) {
        v /= p;
        cnt++;
      }
      if (cnt % k > 0) {
        d.emplace_back(p, cnt % k);
        e.emplace_back(p, k - cnt % k);
      }
    }
    if (v > 1) {
      d.emplace_back(v, 1);
      e.emplace_back(v, k - 1);
    }
    ans += cnt[e];
    cnt[d]++;
  }
  cout << ans << "\n";
  return 0;
}