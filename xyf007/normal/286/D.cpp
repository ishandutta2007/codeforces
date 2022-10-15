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
struct Node {
  int x, t, id;
} a[200001];
struct Node2 {
  int x, v, op;
} b[400001];
int n, m, tot;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<std::pair<int, int>>>
    q;
bool vis[100001];
void Insert(int l, int r) {
  while (!q.empty())
    if (vis[q.top().second])
      q.pop();
    else
      break;
  if (q.empty()) return;
  int t = q.top().first;
  b[++tot] = {t - r, r - t, 1};
  b[++tot] = {t - l, t - l, -1};
}
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= m; i++) {
    int l, r, t;
    Read(l, r, t);
    a[2 * i - 1] = {l, t, i};
    a[2 * i] = {r, t, -i};
  }
  std::sort(a + 1, a + 2 * m + 1, [](const Node &lhs, const Node &rhs) -> bool {
    return lhs.x < rhs.x;
  });
  for (int i = 1; i <= 2 * m; i++) {
    if (i > 1 && a[i].x > a[i - 1].x) Insert(a[i - 1].x, a[i].x);
    if (a[i].id > 0)
      q.emplace(a[i].t, a[i].id);
    else
      vis[-a[i].id] = true;
  }
  std::sort(b + 1, b + tot + 1, [](const Node2 &lhs, const Node2 &rhs) -> bool {
    return lhs.x < rhs.x;
  });
  int p = 1, cnt = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    Read(x);
    while (p <= tot && b[p].x <= x) {
      sum += b[p].v;
      cnt += b[p].op;
      p++;
    }
    std::printf("%d\n", x * cnt + sum);
  }
  return 0;
}