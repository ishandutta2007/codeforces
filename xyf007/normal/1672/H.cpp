#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <iostream>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, q, s0[200001], s1[200001];
char s[200001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q >> (s + 1);
  for (int i = 1; i <= n; i++) {
    s[i] -= '0';
    s0[i] = s0[i - 1], s1[i] = s1[i - 1];
    if (s[i] == s[i - 1]) (s[i] ? s1[i] : s0[i])++;
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << std::max(s0[r] - s0[l], s1[r] - s1[l]) + 1 << '\n';
  }
  return 0;
}