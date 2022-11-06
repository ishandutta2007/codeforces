#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int64_t MOD = 1000000007;
int n;
int64_t x[500000];
int cnt[60];
int64_t pow2[120];

int64_t solve() {
  scanf("%d", &n);
  fill(cnt, cnt + 60, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x[i]);
    for (int j = 0; j < 60; ++j) {
      cnt[j] += (x[i] >> j) & 1;
    }
  }
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    int64_t o = 0;
    for (int j = 0; j < 60; ++j) {
      if ((x[i] & (1ll << j))) continue;
      o += cnt[j] * pow2[j];
      o %= MOD;
    }
    for (int j = 0; j < 60; ++j) {
      if ((x[i] & (1ll << j)) == 0) continue;
      ans += (x[i] % MOD * n + o) % MOD * cnt[j] % MOD * pow2[j];
      ans %= MOD;
    }
  }
  return ans;
}

int main() {
  pow2[0] = 1;
  for (int i = 1; i < 120; ++i) {
    pow2[i] = pow2[i - 1] * 2 % MOD;
  }
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("%lld\n", solve());
  }
}