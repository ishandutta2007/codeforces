#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
struct Node {
  int x, y, d;
  Node(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) {}
};
int n, m, d, cnt;
char mp[1001][1001];
std::pair<int, int> pos[84101];
std::map<std::pair<int, int>, int> id;
bool vis[1001][1001], f[84101][291];
int main(int argc, char const *argv[]) {
#ifdef ONLINE_JUDGE
  std::freopen("input.txt", "r", stdin);
  std::freopen("output.txt", "w", stdout);
#endif
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> d;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> (mp[i] + 1);
    tot += std::count(mp[i] + 1, mp[i] + m + 1, 'R');
  }
  if (tot > 290) {
    std::cout << -1;
    return 0;
  }
  std::queue<Node> q;
  int c0 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 'R') {
        std::memset(vis, false, sizeof(vis));
        c0++;
        q.emplace(i, j, 0);
        while (!q.empty()) {
          Node tmp = q.front();
          q.pop();
          int x = tmp.x, y = tmp.y;
          if (!id[{x, y}]) {
            pos[id[{x, y}] = ++cnt] = {x, y};
          }
          f[id[{x, y}]][c0] = true;
          if (tmp.d == d) {
            continue;
          }
          for (int k = 0; k < 4; k++) {
            int tx = x + dx[k], ty = y + dy[k];
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] ||
                mp[tx][ty] == 'X') {
              continue;
            }
            vis[tx][ty] = true;
            q.emplace(tx, ty, tmp.d + 1);
          }
        }
      }
    }
  }
  if (cnt == 1) {
    if (std::all_of(f[1] + 1, f[1] + c0 + 1,
                    [](const bool &x) -> bool { return x; })) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (mp[i][j] != 'X' && pos[1] != std::make_pair(i, j)) {
            std::cout << pos[1].first << ' ' << pos[1].second << ' ' << i << ' '
                      << j;
            return 0;
          }
        }
      }
    }
    std::cout << -1;
    return 0;
  }
  for (int i = 1; i < cnt; i++) {
    for (int j = i + 1; j <= cnt; j++) {
      bool ok = true;
      for (int k = 1; k <= c0 && f; k++) {
        ok &= f[i][k] || f[j][k];
      }
      if (ok) {
        std::cout << pos[i].first << ' ' << pos[i].second << ' ' << pos[j].first
                  << ' ' << pos[j].second;
        return 0;
      }
    }
  }
  std::cout << -1;
  return 0;
}