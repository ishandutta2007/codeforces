#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int kMod = 1e9 + 7;
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
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
char a[300001], b[300001], c[300001];
int cnt[600001][3], ans[300001];
class GeneralSuffixAutomaton {
 public:
  GeneralSuffixAutomaton() { t_[0].link = -1; }
  void Expand(char c, int id) {
    int p = last_;
    if (t_[p].nxt[c - 'a']) {
      int q = t_[p].nxt[c - 'a'];
      if (t_[q].len == t_[p].len + 1) {
        last_ = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1;
        t_[nq].link = t_[q].link;
        std::memcpy(t_[nq].nxt, t_[q].nxt, sizeof(t_[nq].nxt));
        while (p != -1 && t_[p].nxt[c - 'a'] == q) {
          t_[p].nxt[c - 'a'] = nq;
          p = t_[p].link;
        }
        t_[q].link = nq;
        last_ = nq;
      }
      cnt[last_][id]++;
      return;
    }
    int cur = ++sz_;
    t_[cur].len = t_[p].len + 1;
    while (p != -1 && !t_[p].nxt[c - 'a']) {
      t_[p].nxt[c - 'a'] = cur;
      p = t_[p].link;
    }
    if (p == -1) {
      t_[cur].link = 0;
    } else {
      int q = t_[p].nxt[c - 'a'];
      if (t_[q].len == t_[p].len + 1) {
        t_[cur].link = q;
      } else {
        int nq = ++sz_;
        t_[nq].len = t_[p].len + 1;
        t_[nq].link = t_[q].link;
        std::memcpy(t_[nq].nxt, t_[q].nxt, sizeof(t_[q].nxt));
        while (p != -1 && t_[p].nxt[c - 'a'] == q) {
          t_[p].nxt[c - 'a'] = nq;
          p = t_[p].link;
        }
        t_[cur].link = t_[q].link = nq;
      }
    }
    cnt[last_ = cur][id]++;
  }
  void Build(const char *s, int id) {
    last_ = 0;
    for (std::size_t i = 0, n = std::strlen(s); i < n; i++) Expand(s[i], id);
  }
  ~GeneralSuffixAutomaton() {}
  friend void Solve();

 private:
  struct Node {
    int len, link, nxt[26];
  } t_[600001];
  int sz_, last_;
} T;
std::vector<int> g[600001];
void Dfs(int u) {
  for (auto &&v : g[u]) {
    Dfs(v);
    cnt[u][0] += cnt[v][0];
    cnt[u][1] += cnt[v][1];
    cnt[u][2] += cnt[v][2];
  }
}
void Solve() {
  for (int i = 1; i <= T.sz_; i++) g[T.t_[i].link].emplace_back(i);
  Dfs(0);
  for (int i = 1; i <= T.sz_; i++) {
    int s = mul(cnt[i][0], cnt[i][1], cnt[i][2]);
    Add(ans[T.t_[T.t_[i].link].len + 1], s);
    Sub(ans[T.t_[i].len + 1], s);
  }
}
int main(int argc, char const *argv[]) {
  std::scanf("%s%s%s", a, b, c);
  T.Build(a, 0);
  T.Build(b, 1);
  T.Build(c, 2);
  std::size_t l = std::min({std::strlen(a), std::strlen(b), std::strlen(c)});
  Solve();
  std::partial_sum(
      ans + 1, ans + l + 1, ans + 1,
      [](const int &lhs, const int &rhs) -> int { return add(lhs, rhs); });
  for (std::size_t i = 1; i <= l; i++) std::printf("%d ", ans[i]);
  return 0;
}