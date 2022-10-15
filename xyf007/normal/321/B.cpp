#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
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
struct Card {
  char op[10];
  int v;
} a[101];
int n, m, b[101];
std::multiset<int> s;
int main(int argc, char const *argv[]) {
  Read(n, m);
  for (int i = 1; i <= n; i++) {
    std::scanf("%s", a[i].op);
    Read(a[i].v);
  }
  for (int i = 1; i <= m; i++) {
    Read(b[i]);
    s.emplace(b[i]);
  }
  std::sort(a + 1, a + n + 1, [](const Card &lhs, const Card &rhs) -> bool {
    return lhs.op[0] == rhs.op[0] ? lhs.v < rhs.v : lhs.op[0] < rhs.op[0];
  });
  std::sort(b + 1, b + m + 1, std::greater<int>());
  int pos, cnt, ans = 0;
  for (pos = 1; pos <= n; pos++)
    if (a[pos].op[0] == 'D') break;
  pos--;
  for (int i = pos; i >= 1; i--)
    if (auto it = s.lower_bound(a[i].v); it != s.end()) s.erase(it);
  cnt = m - s.size();
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= cnt; i++) checkmax(ans, (s1 += b[i]) - (s2 += a[i].v));
  s.clear();
  for (int i = 1; i <= m; i++) s.emplace(b[i]);
  bool f = true;
  for (int i = n; i > pos; i--)
    if (auto it = s.upper_bound(a[i].v); it == s.end()) {
      f = false;
      break;
    } else {
      s.erase(it);
    }
  if (!f) {
    std::printf("%d", ans);
    return 0;
  }
  int sum = 0;
  for (int i = pos; i >= 1; i--)
    if (auto it = s.lower_bound(a[i].v); it == s.end()) {
      f = false;
      break;
    } else {
      sum += *it - a[i].v;
      s.erase(it);
    }
  if (!f) {
    std::printf("%d", ans);
    return 0;
  }
  for (auto &&i : s) sum += i;
  std::printf("%d", std::max(ans, sum));
  return 0;
}