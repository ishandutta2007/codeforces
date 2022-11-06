#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> a(n);
  vector<int> cnt(2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i] % 2]++;
  }
  int ans = cnt[1];
  constexpr int kIter = 20;
  mt19937 rng(7122);
  uniform_int_distribution<int> dis(0, n - 1);
  vector<bool> used(n);

  unordered_set<int64_t> s;

  auto Count = [&](int64_t p) {
    if (s.count(p)) return;
    s.insert(p);
    int64_t cur = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < p) cur += p - a[i];
      else cur += min(a[i] % p, p - a[i] % p);
      if (cur >= ans) break;
    }
    if (cur < ans) ans = cur;
  };

  auto Try = [&](int64_t v) {
    for (int64_t p = 2; p * p <= v; ++p) {
      if (v % p == 0) {
        while (v % p == 0) v /= p;
        Count(p);
      }
      if (v > 1) Count(v);
    }
  };

  for (int it = 0; it < kIter; ++it) {
    int p = dis(rng);
    if (a[p] > 1) Try(a[p] - 1);
    Try(a[p]);
    Try(a[p] + 1);
  }
  cout << ans << "\n";
}