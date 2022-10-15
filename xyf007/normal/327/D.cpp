#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kDx[] = {1, 0, -1, 0}, kDy[] = {0, 1, 0, -1};
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = std::getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = std::getchar()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
char s[501][501];
std::vector<std::pair<char, std::pair<int, int>>> ans;
bool vis[501][501];
void Dfs(int x, int y) {
  ans.emplace_back('B', std::make_pair(x, y));
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int tx = x + kDx[i], ty = y + kDy[i];
    if (tx < 1 || tx > n || ty < 1 || ty > m || s[tx][ty] == '#' || vis[tx][ty])
      continue;
    Dfs(tx, ty);
  }
  ans.emplace_back('D', std::make_pair(x, y));
  ans.emplace_back('R', std::make_pair(x, y));
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) std::scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] != '#' && !vis[i][j]) {
        Dfs(i, j);
        ans.pop_back();
        ans.pop_back();
      }
  std::printf("%d\n", static_cast<int>(ans.size()));
  for (auto &&i : ans)
    std::printf("%c %d %d\n", i.first, i.second.first, i.second.second);
  return 0;
}