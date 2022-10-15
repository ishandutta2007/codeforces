#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
struct Edge {
  int to, nxt, cost;
} e[6001];
int n, E, head[3001], cnt, dp[3001];
void checkmax(int &x, int y) {
  if (x < y) {
    x = y;
  }
}
void checkmin(int &x, int y) {
  if (x > y) {
    x = y;
  }
}
void Add(int f, int t, int c) {
  e[E].to = t;
  e[E].cost = c;
  e[E].nxt = head[f];
  head[f] = E++;
}
void Dfs(int u, int fa) {
  dp[u] = 0;
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) {
      continue;
    }
    Dfs(v, u);
    cnt += e[i].cost == -1;
    checkmax(dp[u], dp[v] - e[i].cost);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v, 1);
    Add(v, u, -1);
  }
  int ans = 0x7fffffff;
  for (int i = 1; i <= n; i++) {
    cnt = 0;
    Dfs(i, 0);
    checkmin(ans, cnt - *std::max_element(dp + 1, dp + n + 1));
  }
  std::cout << ans;
  return 0;
}