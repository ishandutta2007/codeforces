#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, rk[262145], ord[262145], trk[262145];
std::string s;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> s;
  int N = 1 << n;
  for (int i = 0; i < N; i++) rk[i] = s[i] - 'a';
  for (int i = 0; i < n; i++) {
    std::iota(ord, ord + N, 0);
    std::sort(ord, ord + N, [i](int x, int y) {
      return rk[x] == rk[y] ? rk[x ^ (1 << i)] < rk[y ^ (1 << i)]
                            : rk[x] < rk[y];
    });
    int c = 0;
    trk[ord[0]] = 0;
    for (int j = 1; j < N; j++)
      trk[ord[j]] = c += rk[ord[j]] != rk[ord[j - 1]] ||
                         rk[ord[j] ^ (1 << i)] != rk[ord[j - 1] ^ (1 << i)];
    std::copy(trk, trk + N, rk);
  }
  int x = std::min_element(rk, rk + N) - rk;
  std::string ans;
  ans.resize(N);
  std::generate(ans.begin(), ans.end(),
                [n = 0, x]() mutable { return s[n++ ^ x]; });
  std::cout << ans;
  return 0;
}