#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m, p, a[10001], b[100001], c[10001], d[1501], tot, f[1501];
std::unordered_map<int, int> w;
int Ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = s * static_cast<long long>(a) % p;
    a = a * static_cast<long long>(a) % p;
    b >>= 1;
  }
  return s;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  int gcd = b[1];
  for (int i = 2; i <= m; i++) gcd = std::gcd(gcd, b[i]);
  const int phi = p - 1;
  for (int i = 1; i * i <= phi; i++)
    if (phi % i == 0) {
      d[++tot] = i;
      if (i * i != phi) d[++tot] = phi / i;
    }
  std::sort(d + 1, d + tot + 1);
  int tmp = phi;
  for (int i = 2; i * i <= tmp; i++)
    if (tmp % i == 0)
      while (tmp % i == 0) w[i]++, tmp /= i;
  if (tmp > 1) w[tmp] = 1;
  for (int i = 1; i <= n; i++) {
    int ord = phi, g = Ksm(a[i], gcd);
    for (const auto &[p, k] : w)
      for (int i = 1; i <= k; i++)
        if (Ksm(g, ord / p) == 1)
          ord /= p;
        else
          break;
    c[i] = phi / ord;
  }
  int ans = 0;
  for (int i = tot; i >= 1; i--) {
    bool ok = false;
    for (int j = 1; j <= n; j++)
      if (d[i] % c[j] == 0) {
        ok = true;
        break;
      }
    if (!ok) continue;
    f[i] = phi / d[i];
    for (int j = i + 1; j <= tot; j++)
      if (d[j] % d[i] == 0) f[i] -= f[j];
    ans += f[i];
  }
  std::cout << ans;
  return 0;
}