#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstring>

typedef long long LL;

int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 100;
const int mod = 1000000007;

LL n, f[N], inv[N];
int m;

LL pow_mod(LL a, LL b) {
  LL ans = 1;
  for (a %= mod; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}

LL calc(LL p, int k) {
  f[0] = 1;
  for (int i = 1; i <= k; ++i) f[i] = f[i - 1] * p % mod;
  for (int i = 1; i <= m; ++i) {
    LL S = 0;
    for (int j = 0; j <= k; ++j) {
      S = (S + f[j]) % mod;
      f[j] = S * inv[j + 1] % mod;
    }
  }
  return f[k];
}

int main() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) inv[i] = -(mod / i) * inv[mod % i] % mod;
  scanf("%I64d%d", &n, &m);
  LL ans = 1;
  for (LL i = 2; i * i <= n; ++i) if (n % i == 0) {
    int k = 0;
    while (n % i == 0) n /= i, ++k;
    ans = ans * calc(i, k) % mod;
  }
  if (n > 1) ans = ans * calc(n, 1) % mod;
  printf("%I64d\n", (ans + mod) % mod);
  return 0;
}