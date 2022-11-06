#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t x;
  cin >> x;
  vector<pair<int64_t, int>> dv;
  for (int64_t p = 2; p * p <= x; ++p) {
    int cnt = 0;
    while (x % p == 0) {
      x /= p;
      cnt++;
    }
    if (cnt > 0) {
      dv.emplace_back(p, cnt);
    }
  }
  if (x > 1) {
    dv.emplace_back(x, 1);
  }
  
  vector<int> cnt(dv.size(), 0);
  map<int64_t, vector<int>> dp;

  auto Dfs = [&](auto self, int i, int64_t v) -> void {
    if (i == dv.size()) {
      dp[v] = cnt;
      return;
    }
    for (int j = 0; j <= dv[i].second; ++j) {
      cnt[i] = j;
      self(self, i + 1, v);
      cnt[i] = 0;
      v *= dv[i].first;
    }
  };

  Dfs(Dfs, 0, 1);
  int q;
  cin >> q;

  constexpr int kMod = 998244353;
  vector<int> fc(100, 1), iv(100, 1);

  auto fpow = [&](int a, int n) {
    int res = 1;
    while (n > 0) {
      if (n & 1) res = 1LL * res * a % kMod;
      a = 1LL * a * a % kMod;
      n >>= 1;
    }
    return res;
  };

  for (int i = 1; i < 100; ++i) {
    fc[i] = 1LL * fc[i - 1] * i % kMod;
    iv[i] = fpow(fc[i], kMod - 2);
  }

  while (q--) {
    int64_t u, v;
    cin >> u >> v;
    assert(dp.find(u) != dp.end());
    assert(dp.find(v) != dp.end());
    vector<int> base(cnt.size());
    for (int i = 0; i < cnt.size(); ++i) {
      base[i] = min(dp[u][i], dp[v][i]);
    }
    int sum = 0, res = 1;
    for (int i = 0; i < cnt.size(); ++i) {
      sum += dp[u][i] - base[i];
      res = 1LL * res * iv[dp[u][i] - base[i]] % kMod;
    }
    res = 1LL * res * fc[sum] % kMod;
    sum = 0;
    for (int i = 0; i < cnt.size(); ++i) {
      sum += dp[v][i] - base[i];
      res = 1LL * res * iv[dp[v][i] - base[i]] % kMod;
    }
    res = 1LL * res * fc[sum] % kMod;
    cout << res << "\n";
  }
}