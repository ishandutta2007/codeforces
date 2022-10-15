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
int n, m, q;
char s[100001][11];
std::pair<int, int> nxt[400001][11];
void Calc(int id, int x) {
  for (int i = 1; i <= m; i++) nxt[x][i] = {0, 0};
  for (int i = 1; i < m; i++)
    if (s[id][i] == '>' && s[id][i + 1] == '<')
      nxt[x][i] = nxt[x][i + 1] = {-1, -1};
  for (int i = 1; i <= m; i++) {
    if (nxt[x][i].first == -1) continue;
    int nx = id, ny = i;
    while (nx == id && ny >= 1 && ny <= m)
      if (nxt[x][ny].first == -1)
        nx = -1, ny = -1;
      else if (s[id][ny] == '^')
        nx--;
      else if (s[id][ny] == '<')
        ny--;
      else if (s[id][ny] == '>')
        ny++;
    nxt[x][i] = {nx, ny};
  }
}
void Pushup(int x) {
  for (int i = 1; i <= m; i++) {
    nxt[x][i] = nxt[x + x + 1][i];
    auto [nx, ny] = nxt[x + x + 1][i];
    if (ny >= 1 && ny <= m) nxt[x][i] = nxt[x + x][ny];
  }
}
void Build(int l, int r, int x) {
  if (l == r) {
    Calc(l, x);
    return;
  }
  int mid = (l + r) >> 1;
  Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
  Pushup(x);
}
void Modify(int l, int r, int p, int y, char v, int x) {
  if (l == r) {
    s[l][y] = v;
    Calc(l, x);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    Modify(l, mid, p, y, v, x + x);
  else
    Modify(mid + 1, r, p, y, v, x + x + 1);
  Pushup(x);
}
std::pair<int, int> Query(int l, int r, int p, int y, int x) {
  if (r == p) return nxt[x][y];
  int mid = (l + r) >> 1;
  if (p <= mid) return Query(l, mid, p, y, x + x);
  auto [nx, ny] = Query(mid + 1, r, p, y, x + x + 1);
  if (ny >= 1 && ny <= m) return nxt[x + x][ny];
  return {nx, ny};
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) std::cin >> (s[i] + 1);
  Build(1, n, 1);
  while (q--) {
    char op[10];
    int x, y;
    std::cin >> op >> x >> y;
    if (op[0] == 'A') {
      std::pair<int, int> ans = Query(1, n, x, y, 1);
      std::cout << ans.first << ' ' << ans.second << '\n';
    } else {
      char v[10];
      std::cin >> v;
      Modify(1, n, x, y, v[0], 1);
    }
  }
  return 0;
}