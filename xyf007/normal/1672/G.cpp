#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>
constexpr int kMod = 998244353;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, r[2001], c[2001], q[2001];
char s[2001][2005], tmp[2001][2005];
long long Ksm(long long a, int b) {
  long long s = 1LL;
  while (b) {
    if (b & 1) s = s * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return s;
}
class DisjointSet {
 public:
  int a_[4001];
  DisjointSet() {}
  void Init(int n) {
    std::iota(fa_ + 1, fa_ + n + 1, 1);
    std::fill(sz_ + 1, sz_ + n + 1, 1);
    std::fill(sze_ + 1, sze_ + n + 1, 0);
  }
  int Find(int x) { return fa_[x] == x ? x : fa_[x] = Find(fa_[x]); }
  bool Merge(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if (fx == fy) {
      sze_[fx]++;
      return false;
    }
    fa_[fx] = fy;
    sz_[fy] += sz_[fx], sze_[fy] += sze_[fx] + 1, a_[fy] ^= a_[fx];
    return true;
  }
  std::tuple<int, int, int> Info(int x) const {
    return {sz_[x], sze_[x], a_[x]};
  }
  ~DisjointSet() {}

 private:
  int fa_[4001], sz_[4001], sze_[4001];
} dsu;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (int i = 1; i <= n; i++) std::cin.getline(s[i] + 1, m + 1);
  if (n & 1 && ~m & 1) {
    for (int i = 1; i <= n; i++) std::copy(s[i] + 1, s[i] + m + 1, tmp[i] + 1);
    std::swap(n, m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) s[i][j] = tmp[j][i];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1') r[i] ^= 1;
      if (s[i][j] == '?') q[i]++;
    }
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++)
      if (s[i][j] == '1') c[j] ^= 1;
  if (~n & 1 && ~m & 1) {
    std::cout << Ksm(2LL, std::accumulate(q + 1, q + n + 1, 0));
  } else if (~n & 1 && m & 1) {
    int ans = 0;
    for (int aim = 0; aim < 2; aim++) {
      int w = 1;
      for (int i = 1; i <= n; i++) {
        if (q[i]) {
          w = w * Ksm(2LL, q[i] - 1) % kMod;
        } else if (r[i] != aim) {
          w = 0;
          break;
        }
      }
      ans += w;
    }
    std::cout << ans % kMod << '\n';
  } else {
    dsu.Init(n + m);
    std::copy(r + 1, r + n + 1, dsu.a_ + 1);
    std::copy(c + 1, c + m + 1, dsu.a_ + n + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (s[i][j] == '?') dsu.Merge(i, j + n);
    int ans = 0;
    for (int aim = 0; aim < 2; aim++) {
      int w = 1;
      for (int i = 1; i <= n + m; i++)
        if (dsu.Find(i) == i) {
          const auto [N, M, V] = dsu.Info(i);
          if (~N & 1) {
            if (V == 0) {
              w = w * Ksm(2LL, M - N + 1) % kMod;
            } else {
              w = 0;
              break;
            }
          } else {
            if (V == aim) {
              w = w * Ksm(2LL, M - N + 1) % kMod;
            } else {
              w = 0;
              break;
            }
          }
        }
      ans += w;
    }
    std::cout << ans % kMod << '\n';
  }
  return 0;
}