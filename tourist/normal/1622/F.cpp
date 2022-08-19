/**
 *    author:  tourist
 *    created: 27.12.2021 18:29:33       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Print = [&](vector<int> rem) {
    vector<bool> use(n + 1, true);
    for (int x : rem) {
      assert(1 <= x && x <= n && use[x]);
      use[x] = false;
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
      if (use[i]) {
        res.push_back(i);
      }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < (int) res.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << res[i];
    }
    cout << '\n';
  };
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (p[i] == i) {
      for (int j = i + i; j <= n; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  vector<unsigned long long> c(n + 1);
  for (int i = 2; i <= n; i++) {
    if (p[i] == i) {
      c[i] = rng();
    }
  }
  vector<unsigned long long> num(n + 1);
  num[1] = 0;
  for (int i = 2; i <= n; i++) {
    num[i] = num[i / p[i]] ^ c[p[i]];
  }
  vector<unsigned long long> f(n + 1);
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] ^ num[i];
  }
  unsigned long long all = 0;
  for (int i = 1; i <= n; i++) {
    all ^= f[i];
  }
  if (all == 0) {
    Print({});
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (all == f[i]) {
      Print({i});
      return 0;
    }
  }
  vector<pair<unsigned long long, int>> ps(n);
  for (int i = 1; i <= n; i++) {
    ps[i - 1] = make_pair(f[i], i);
  }
  sort(ps.begin(), ps.end());
  for (int i = 1; i <= n; i++) {
    auto need = all ^ f[i];
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(need, -1));
    if (it != ps.end() && it->first == need) {
      Print({i, it->second});
      return 0;
    }
  }
  assert(n % 2 == 1);
  all ^= f[n];
  for (int i = 1; i <= n - 1; i++) {
    auto need = all ^ f[i];
    auto it = lower_bound(ps.begin(), ps.end(), make_pair(need, -1));
    if (it != ps.end() && it->first == need && it->second < n) {
      Print({i, it->second, n});
      return 0;
    }
  }
  assert(false);
  return 0;
}