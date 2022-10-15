#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
constexpr int kMod = 1073741824;
int a, b, c, p[2001], tot, mu[2001];
long long fa[2001][2001], fb[2001][2001];
bool not_prime[2001], vis[2001][2001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  not_prime[1] = true;
  mu[1] = 1;
  for (int i = 2; i <= 2000; i++) {
    if (!not_prime[i]) {
      p[++tot] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= tot && i * p[j] <= 2000; j++) {
      not_prime[i * p[j]] = true;
      if (!(i % p[j])) {
        break;
      }
      mu[i * p[j]] = -mu[i];
    }
  }
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= 2000; j++) {
      vis[i][j] = std::__gcd(i, j) == 1;
    }
  }
  std::cin >> a >> b >> c;
  for (int k = 1; k <= c; k++) {
    for (int d = 1; d <= a && d <= b; d++) {
      for (int i = 1; i <= a / d; i++) {
        if (vis[i * d][k]) {
          fa[k][d] = (fa[k][d] + a / (i * d)) % kMod;
        }
      }
      for (int i = 1; i <= b / d; i++) {
        if (vis[i * d][k]) {
          fb[k][d] = (fb[k][d] + b / (i * d)) % kMod;
        }
      }
    }
  }
  long long ans = 0LL;
  for (int k = 1; k <= c; k++) {
    long long tmp = 0LL;
    for (int d = 1; d <= a && d <= b; d++) {
      tmp = (tmp + fa[k][d] * fb[k][d] * mu[d]) % kMod;
    }
    ans = (ans + c / k * tmp) % kMod;
  }
  std::cout << (ans % kMod + kMod) % kMod;
  return 0;
}