#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 998244353;
int n, k, mu[2000001], p[200001], tot;
bool np[2000001];
long long fac[2000001], inv[2000001];
__gnu_pbds::gp_hash_table<int, int> mp;
long long Ksm(long long a, int b) {
  long long s = 1LL;
  while (b) {
    if (b & 1) (s *= a) %= kMod;
    (a *= a) %= kMod;
    b >>= 1;
  }
  return s;
}
void Init(int n) {
  fac[0] = 1LL;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % kMod;
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % kMod;
  np[1] = true, mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = true;
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
}
int Solve(int n) {
  if (mp.find(n) == mp.end()) {
    int lim = std::min(n, k);
    std::vector<long long> f(lim + 1), g(lim + 1);
    for (int i = 0; i <= lim; i++) f[i] = Ksm(i, n) * inv[i] % kMod;
    for (int i = 0; i <= lim; i++) g[i] = i & 1 ? kMod - inv[i] : inv[i];
    std::partial_sum(f.begin(), f.end(), f.begin());
    for (int i = 0; i <= lim; i++) f[i] %= kMod;
    __int128_t s = kMod - 1;
    for (int i = 0; i <= lim; i++) s += g[i] * f[lim - i];
    mp[n] = s % kMod;
  }
  return mp[n];
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> k;
  if (n == 1 || k == 1) {
    std::cout << 1;
    return 0;
  }
  Init(n);
  __int128_t s = 0;
  for (int i = 1; i <= n; i++)
    if (mu[i]) {
      if (mu[i] == 1)
        s += Solve((n + i - 1) / i);
      else
        s -= Solve((n + i - 1) / i);
    }
  int ans = s % kMod + kMod;
  if (ans >= kMod) ans -= kMod;
  std::cout << ans;
  return 0;
}