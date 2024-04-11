#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <algorithm>
#include <cstring>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n;
long long a[100001], f[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::memset(f + 1, 0xc0, 8 * n);
  for (int i = 1; i <= n; i++)
    for (int j = i; j >= 1; j--) checkmax(f[j], f[j - 1] + j * a[i]);
  std::cout << *std::max_element(f, f + n + 1);
  return 0;
}