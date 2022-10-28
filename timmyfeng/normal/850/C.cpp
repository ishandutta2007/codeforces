#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int mex(int mask) {
  if (memo.count(mask) == 0) {
    int ans = 0;
    for (int i = 0; (1 << i) <= mask; ++i) {
      ans |= 1 << mex((mask & ((1 << i) - 1)) | (mask >> (i + 1)));
    }
    memo[mask] = __builtin_ctz(ans + 1);
  }
  return memo[mask];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int> primes;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    for (int p = 2; p * p <= a; ++p) {
      int cnt = 0;
      while (a % p == 0) {
        ++cnt;
        a /= p;
      }

      if (cnt > 0) {
        primes[p] |= 1 << (cnt - 1);
      }
    }

    if (a > 1) {
      primes[a] |= 1;
    }
  }

  int ans = 0;
  memo[0] = 0;
  for (auto [p, mask] : primes) {
    ans ^= mex(mask);
  }
  cout << (ans > 0 ? "Mojtaba" : "Arpa") << "\n";
}