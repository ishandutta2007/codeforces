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
  while ((c = Gc()) >= '0' && c <= '9') x = x * 10 + (c - '0');
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &... args) {
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
int n, m, col[100001], pre[100001], pree[100001];
std::vector<std::pair<int, int>> g[100001];
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    Read(u, v, c);
    g[u].emplace_back(v, c), g[v].emplace_back(u, c);
  }
  std::memset(col, -1, sizeof(col));
  col[n - 1] = 0;
  std::queue<int> q;
  q.emplace(n - 1);
  std::queue<std::vector<int>> qq;
  qq.emplace(std::vector<int>());
  qq.front().emplace_back(n - 1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &&[v, c] : g[u]) {
      if (c || !col[v]) continue;
      col[v] = 0;
      pre[v] = u;
      qq.front().emplace_back(v);
      q.emplace(v);
    }
  }
  int cnt = 0;
  while (!qq.empty()) {
    auto a = qq.front();
    qq.pop();
    cnt++;
    std::vector<int> tmp;
    for (auto &&u : a)
      for (auto &&[v, c] : g[u])
        if (col[v] == -1) {
          col[v] = cnt;
          pre[v] = u;
          pree[v] = c;
          tmp.emplace_back(v);
        } else if (col[v] == cnt && c < pree[v]) {
          pre[v] = u;
          pree[v] = c;
        }
    std::vector<int> buc[10];
    for (auto &&u : tmp) buc[pree[u]].emplace_back(u);
    for (int i = 0; i < 10; i++)
      if (!buc[i].empty()) qq.emplace(buc[i]);
  }
  std::string res;
  std::vector<int> ans;
  int u = 0;
  while (u != n - 1) {
    if (col[u]) res += pree[u] + '0';
    ans.emplace_back(u);
    u = pre[u];
  }
  std::reverse(res.begin(), res.end());
  std::printf("%s\n%d\n", res.empty() ? "0" : res.c_str(),
              static_cast<int>(ans.size()) + 1);
  for (auto &&i : ans) std::printf("%d ", i);
  std::printf("%d", n - 1);
  return 0;
}