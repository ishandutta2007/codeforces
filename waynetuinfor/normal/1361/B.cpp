#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (int i = 0; i < n; ++i) cin >> k[i]; 
    if (p == 1) {
      cout << n % 2 << "\n";
      continue;
    }
    sort(k.rbegin(), k.rend());
    int cnt = 0;
    vector<vector<int>> dist(2);
    vector<int64_t> rp(1, 1);
    int lim = 0;
    int64_t prod = 1;
    while (prod <= n) {
      prod *= p;
      lim++;
      rp.push_back(prod);
    }
    int pv = 1'000'000;
    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && k[i] == k[j]) j++;
      int z = j - i;
      if (cnt > 0 && pv - k[i] >= lim) {
        for (int g = i; g < n; ++g) {
          dist[0].push_back(k[g]);
        }
        break;
      }
      int64_t need = cnt == 0 ? 0 : 1LL * cnt * rp[pv - k[i]];
      if (need > n) {
        for (int g = i; g < n; ++g) {
          dist[0].push_back(k[g]);
        }
        break;
      }
      int64_t got = min(need, 1LL * z);
      for (int j = 0; j < got; ++j) {
        dist[0].push_back(k[i]);
      }
      need -= got;
      z -= got;
      cnt = need;
      if (z > 0) {
        assert(need == 0);
        for (int j = 0; j < z / 2; ++j) {
          dist[0].push_back(k[i]);
          dist[1].push_back(k[i]);
        }
        if (z % 2 == 1) {
          dist[1].push_back(k[i]);
          cnt = 1;
        }
      }
      pv = k[i];
    }

    constexpr int kMod = 1'000'000'000 + 7;

    auto fpow = [&](int a, int n) {
      int res = 1;
      while (n > 0) {
        if (n & 1) res = 1LL * res * a % kMod;
        a = 1LL * a * a % kMod;
        n >>= 1;
      }
      return res;
    };

    int res = 0;
    for (int u : dist[1]) (res += fpow(p, u)) %= kMod;
    for (int u : dist[0]) (res += kMod - fpow(p, u)) %= kMod;
    cout << res << "\n";
  }
  return 0;
}