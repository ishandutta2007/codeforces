#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int i, j, a, b;
} p[45][45][45][45];
int T, n, A, B, a[45], dp[45][45][45][45];
char s[45];
void Solve() {
  std::cin >> n >> A >> B >> s;
  for (int i = 0; i < n; i++) a[i] = s[i] - '0';
  std::memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i + j >= n) continue;
      for (int pa = 0; pa < A; pa++)
        for (int pb = 0; pb < B; pb++)
          if (dp[i][j][pa][pb]) {
            int na = (pa * 10 + a[i + j]) % A, nb = (pb * 10 + a[i + j]) % B;
            if (!dp[i + 1][j][na][pb])
              dp[i + 1][j][na][pb] = true, p[i + 1][j][na][pb] = {i, j, pa, pb};
            if (!dp[i][j + 1][pa][nb])
              dp[i][j + 1][pa][nb] = true, p[i][j + 1][pa][nb] = {i, j, pa, pb};
          }
    }
  std::pair<int, int> ans(-1, 10000);
  for (int i = 1; i < n; i++)
    if (dp[i][n - i][0][0])
      if (std::abs(ans.first - ans.second) > std::abs(i - (n - i)))
        ans = {i, n - i};
  if (ans.first == -1) {
    std::cout << "-1\n";
    return;
  }
  std::string ss;
  Node x = {ans.first, ans.second, 0, 0};
  while (x.i || x.j) {
    auto pr = p[x.i][x.j][x.a][x.b];
    ss += "RB"[pr.i == x.i];
    std::swap(pr, x);
  }
  std::reverse(ss.begin(), ss.end());
  std::cout << ss << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}