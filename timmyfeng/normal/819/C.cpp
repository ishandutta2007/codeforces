#include <bits/stdc++.h>
using namespace std;

const int A = 1'000'000 + 1;

int sieve[A];

pair<long long, vector<array<int, 2>>> read() {
  long long n = 1;
  map<int, int> factors;
  for (int i = 0; i < 3; ++i) {
    int a;
    cin >> a;
    n *= a;
    while (a > 1) {
      ++factors[sieve[a]];
      a /= sieve[a];
    }
  }

  vector<array<int, 2>> flat;
  for (auto [p, a] : factors) {
    flat.push_back({p, a});
  }

  return make_pair(n, flat);
}

int dfs(const vector<array<int, 2>>& factors, long long p, long long x, int i) {
  if (i == int(factors.size())) {
    return p <= x;
  }

  int cnt = 0;
  for (int j = 0; j <= factors[i][1]; ++j) {
    cnt += dfs(factors, p, x, i + 1);
    p *= factors[i][0];
  }
  return cnt;
}

void solve() {
  auto [n, factors_n] = read();
  auto [m, factors_m] = read();
  auto [s, factors_s] = read();

  if (factors_s.empty() || factors_s[0][0] != 2) {
    factors_s.insert(factors_s.begin(), array<int, 2>{2, 0});
  }
  ++factors_s[0][1];
  s *= 2;

  long long ans = dfs(factors_s, 1, n, 0);

  vector<long long> bad;
  for (auto [p, a] : factors_n) {
    long long pp = p;
    long long ss = s;
    int aa = 0;
    while (ss % p == 0) {
      ss /= p;
      pp *= p;
      ++aa;
    }

    if (aa < a) {
      bad.push_back(pp);
    }
  }

  int cnt = bad.size();
  for (int i = 0; i < (1 << cnt); ++i) {
    long long p = 1;
    for (int j = 0; j < cnt; ++j) {
      if ((i & (1 << j)) > 0) {
        p *= bad[j];
      }
    }

    if (__builtin_popcount(i) % 2 == 1) {
      ans -= m / p;
    } else {
      ans += m / p;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < A; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}