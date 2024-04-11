#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, x[1001], y[1001], xx[3005], yy[3005],
    totx = 3, toty = 3, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0},
    vis[3005][3005];
void Dfs(int x, int y) {
  if (x < 1 || x > totx + 1 || y < 1 || y > toty + 1 || vis[x][y]) {
    return;
  }
  vis[x][y] = 2;
  for (int i = 0; i < 4; i++) {
    Dfs(x + dx[i], y + dy[i]);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  xx[1] = yy[1] = -1;
  xx[2] = yy[2] = 0;
  xx[3] = yy[3] = 1;
  int nowx = 0, nowy = 0;
  for (int i = 1; i <= n; i++) {
    char op[10];
    int d;
    std::cin >> op >> d;
    switch (op[0]) {
      case 'L':
        nowx -= d;
        break;
      case 'R':
        nowx += d;
        break;
      case 'U':
        nowy += d;
        break;
      case 'D':
        nowy -= d;
        break;
      default:
        assert(false);
        break;
    }
    xx[++totx] = nowx - 1;
    yy[++toty] = nowy - 1;
    xx[++totx] = x[i] = nowx;
    yy[++toty] = y[i] = nowy;
    xx[++totx] = nowx + 1;
    yy[++toty] = nowy + 1;
  }
  std::sort(xx + 1, xx + totx + 1);
  totx = std::unique(xx + 1, xx + totx + 1) - xx - 1;
  std::sort(yy + 1, yy + toty + 1);
  toty = std::unique(yy + 1, yy + toty + 1) - yy - 1;
  auto findx = [](const int &v) -> int {
    return std::lower_bound(xx + 1, xx + totx + 1, v) - xx;
  };
  auto findy = [](const int &v) -> int {
    return std::lower_bound(yy + 1, yy + toty + 1, v) - yy;
  };
  for (int i = 1; i <= n; i++) {
    int x1 = findx(x[i - 1]), y1 = findy(y[i - 1]), x2 = findx(x[i]),
        y2 = findy(y[i]);
    if (x1 == x2) {
      for (int j = std::min(y1, y2); j <= y1 || j <= y2; j++) {
        vis[x1][j] = 1;
      }
    }
    if (y1 == y2) {
      for (int j = std::min(x1, x2); j <= x1 || j <= x2; j++) {
        vis[j][y1] = 1;
      }
    }
  }
  Dfs(1, 1);
  long long ans = 0LL;
  for (int i = 1; i <= totx; i++) {
    for (int j = 1; j <= toty; j++) {
      if (vis[i][j] != 2) {
        ans += static_cast<long long>(xx[i] - xx[i - 1]) * (yy[j] - yy[j - 1]);
      }
    }
  }
  std::cout << ans;
  return 0;
}