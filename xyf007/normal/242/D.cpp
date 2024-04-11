#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
struct Edge {
  int to, nxt;
} e[200001];
int n, m, E, head[100001], a[100001], b[100001];
std::vector<int> ans;
void Add(int f, int t) {
  e[E].to = t;
  e[E].nxt = head[f];
  head[f] = E++;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::memset(head, -1, sizeof(head));
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    Add(u, v);
    Add(v, u);
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!a[i]) {
      q.emplace(i);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.emplace_back(u);
    b[u]++;
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].to;
      if (++b[v] == a[v]) {
        q.emplace(v);
      }
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &&i : ans) {
    std::cout << i << ' ';
  }
  return 0;
}