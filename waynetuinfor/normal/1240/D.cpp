#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  constexpr int kP1 = 1'000'000'000 + 87;
  constexpr int kP2 = 1'000'000'000 + 123;
  constexpr int kQ1 = 131;
  constexpr int kQ2 = 7122;

  auto DivideConquer = [&](int l, int r) {
    auto Impl = [&](auto self, int l, int r) {
      if (r - l == 1) return 0LL;
      int m = (l + r) >> 1;
      vector<tuple<int, int, int>> s;
      s.emplace_back(0, 0, -1);
      map<pair<int, int>, int> cnt;
      for (int i = m - 1; i >= l; --i) {
        if (!s.empty() && get<2>(s.back()) == a[i]) {
          s.pop_back();
        } else {
          int h1 = (1LL * kQ1 * get<0>(s.back()) + a[i]) % kP1;
          int h2 = (1LL * kQ2 * get<1>(s.back()) + a[i]) % kP2;
          s.emplace_back(h1, h2, a[i]);
        }
        cnt[make_pair(get<0>(s.back()), get<1>(s.back()))]++;
      }
      s.clear();
      s.emplace_back(0, 0, -1);
      int64_t res = 0;
      for (int i = m; i < r; ++i) {
        if (!s.empty() && get<2>(s.back()) == a[i]) {
          s.pop_back();
        } else {
          int h1 = (1LL * kQ1 * get<0>(s.back()) + a[i]) % kP1;
          int h2 = (1LL * kQ2 * get<1>(s.back()) + a[i]) % kP2;
          s.emplace_back(h1, h2, a[i]);
        }
        // cnt[make_pair(get<0>(s.back()), get<1>(s.back()))]++;
        if (cnt.find(make_pair(get<0>(s.back()), get<1>(s.back()))) != cnt.end()) res += cnt[make_pair(get<0>(s.back()), get<1>(s.back()))];
      }
      res += self(self, l, m) + self(self, m, r);
      return res;
    };
    return Impl(Impl, l, r);
  };

  cout << DivideConquer(0, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) Solve();
}