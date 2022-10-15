#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, a[101], r1, c1, r2, c2, dis[10000001];
bool vis[10000101];
auto id = [](const int &x, const int &y) -> int {
  return (x - 1) * 100001 + y;
};
auto de = [](const int &x) -> std::pair<int, int> {
  return {x / 100001 + 1, x % 100001};
};
int main(int argc, char const *argv[]) {
#if defined(ONLINE_JUDGE)
  std::freopen("input.txt", "r", stdin);
  std::freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cin >> r1 >> c1 >> r2 >> c2;
  int s = id(r1, c1), t = id(r2, c2);
  std::memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  std::queue<int> q;
  q.emplace(s);
  vis[s] = true;
  while (!q.empty()) {
    int tmp = q.front(), x, y;
    q.pop();
    x = de(tmp).first;
    y = de(tmp).second;
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 1 || tx > n || ty < 0) {
        continue;
      }
      if (ty > a[tx] + 1) {
        ty = a[tx] + 1;
      }
      if (int p = id(tx, ty); !vis[id(tx, ty)]) {
        dis[p] = dis[tmp] + 1;
        q.emplace(p);
        vis[p] = true;
      }
    }
  }
  std::cout << dis[t];
  return 0;
}