#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, w, q, a[100001], k[100001], min[100001], max[100001], f[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> w >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= q; i++) std::cin >> k[i], k[i] = w - k[i];
  std::fill(min + 1, min + q + 1, a[1]);
  std::fill(max + 1, max + q + 1, a[1]);
  for (int i = 1; i <= n; i++) {
    int t = a[i];
    for (int j = 1; j <= q; j++) {
      checkmax(max[j], t), checkmin(min[j], t);
      if (max[j] - min[j] > k[j]) max[j] = min[j] = t, f[j]++;
    }
  }
  for (int i = 1; i <= q; i++) std::cout << f[i] << '\n';
  return 0;
}