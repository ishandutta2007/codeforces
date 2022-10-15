#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + c - '0';
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
long long h, dis[10001];
std::size_t pos[10001];
int n, m, k, c[100001];
std::vector<long long> e;
std::vector<std::pair<long long, int>> v[10001];
bool vis[10001], vis2[100001];
void Dijkstra() {
  std::memset(dis, 0x3f, sizeof(dis));
  std::memset(vis, false, sizeof(vis));
  int s = 1 % k;
  dis[s] = 1LL;
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>
      q;
  q.emplace(1LL, s);
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto &&i : e) {
      int v = (u + i) % k;
      if (dis[u] + i < dis[v]) {
        dis[v] = dis[u] + i;
        q.emplace(dis[v], v);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  Read(h, n, m, k);
  for (int i = 1; i <= n; i++) {
    long long p;
    Read(p, c[i]);
    v[p % k].emplace_back(p, i);
  }
  for (int i = 0; i < k; i++) {
    std::sort(v[i].begin(), v[i].end());
    pos[i] = v[i].size();
  }
  std::priority_queue<std::pair<int, int>> q;
  Dijkstra();
  for (int i = 0; i < k; i++)
    while (pos[i] && v[i][pos[i] - 1].first >= dis[i]) {
      int u = v[i][--pos[i]].second;
      q.emplace(c[u], -u);
      vis2[u] = true;
    }
  for (int i = 1; i <= m; i++) {
    int op;
    Read(op);
    if (op == 1) {
      long long x;
      Read(x);
      e.emplace_back(x);
      Dijkstra();
      for (int i = 0; i < k; i++)
        while (pos[i] && v[i][pos[i] - 1].first >= dis[i]) {
          int u = v[i][--pos[i]].second;
          q.emplace(c[u], -u);
          vis2[u] = true;
        }
    } else if (op == 2) {
      int x, y;
      Read(x, y);
      c[x] -= y;
      if (vis2[x]) q.emplace(c[x], -x);
    } else {
      bool f = false;
      while (!q.empty()) {
        std::pair<int, int> tmp = q.top();
        q.pop();
        int u = -tmp.second;
        if (c[u] != tmp.first || !vis2[u]) continue;
        f = true;
        vis2[u] = false;
        std::printf("%d\n", c[u]);
        break;
      }
      if (!f) std::printf("0\n");
    }
  }
  return 0;
}