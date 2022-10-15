#include <algorithm>
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
int T, n, cnt[3][2];
char s[301][301];
void Solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  std::memset(cnt, 0, sizeof(cnt));
  int k = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j] == 'O')
        cnt[(i + j) % 3][0]++, k++;
      else if (s[i][j] == 'X')
        cnt[(i + j) % 3][1]++, k++;
  if (cnt[0][0] + cnt[1][1] <= k / 3) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (!((i + j) % 3) && s[i][j] == 'O') s[i][j] = 'X';
        if ((i + j) % 3 == 1 && s[i][j] == 'X') s[i][j] = 'O';
      }
  } else if (cnt[1][0] + cnt[2][1] <= k / 3) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if ((i + j) % 3 == 1 && s[i][j] == 'O') s[i][j] = 'X';
        if ((i + j) % 3 == 2 && s[i][j] == 'X') s[i][j] = 'O';
      }
  } else {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if ((i + j) % 3 == 2 && s[i][j] == 'O') s[i][j] = 'X';
        if (!((i + j) % 3) && s[i][j] == 'X') s[i][j] = 'O';
      }
  }
  for (int i = 1; i <= n; i++) std::cout << (s[i] + 1) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}