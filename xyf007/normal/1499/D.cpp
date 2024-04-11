#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int t, cnt[20000001];
long long c, d, x;
bool not_prime[20000001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  not_prime[1] = true;
  for (int i = 2; i <= 20000000; i++) {
    if (!not_prime[i]) {
      cnt[i]++;
      for (int j = i + i; j <= 20000000; j += i) {
        not_prime[j] = true;
        cnt[j]++;
      }
    }
  }
  std::cin >> t;
  while (t--) {
    std::cin >> c >> d >> x;
    long long ans = 0LL;
    for (int i = 1; i * i <= x; i++) {
      if (!(x % i)) {
        long long g = i, tmp = x + d * g;
        if (!(tmp % (c * g))) {
          tmp /= c * g;
          ans += 1LL << cnt[tmp];
        }
        if (i * i == x) {
          break;
        }
        g = x / i;
        tmp = x + d * g;
        if (!(tmp % (c * g))) {
          tmp /= c * g;
          ans += 1LL << cnt[tmp];
        }
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}