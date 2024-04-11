#include <cstdio>
#include <cstring>
#include <set>
#include <tuple>
#include <vector>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
char rbuf[1 << 20], *ps, *pt, wbuf[1 << 20], *po = wbuf;
char Getchar() {
  if (ps == pt) {
    pt = (ps = rbuf) + std::fread(rbuf, 1, 1 << 20, stdin);
    if (ps == pt) return EOF;
  }
  return *ps++;
}
template <typename T = int>
T Read() {
  T x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  return x * f;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  x = c - '0';
  while ((c = Getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
void Read(char &c) { c = Getchar(); }
void Read(char *s) {
  char c = Getchar();
  while (c <= 32) c = Getchar();
  while (c > 32) *s++ = c, c = Getchar();
  *s = '\0';
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
void Putchar(const char &c) {
  if (po - wbuf == 1 << 20) std::fwrite(wbuf, po - wbuf, 1, stdout), po = wbuf;
  *po++ = c;
}
template <typename T>
void Write(const T &x) {
  if (x < 0) {
    Putchar('-'), Write(-x);
    return;
  }
  if (x > 9) Write(x / 10);
  Putchar(x % 10 + '0');
}
void Write(const char c) { Putchar(c); }
void Write(const char *s) {
  while (*s != '\0') Putchar(*s++);
}
template <typename T, typename... Args>
void Write(const T &x, const Args &...args) {
  Write(x), Write(args...);
}
class AutoFlusher {
 public:
  AutoFlusher() {}
  ~AutoFlusher() { std::fwrite(wbuf, po - wbuf, 1, stdout); }
} autoflusher;
struct Edge {
  int to, nxt;
} e[1000001];
int T, n, q, a[1000001], E, head[1000001], cnt[1000001], ans[1000001];
std::vector<std::tuple<int, int, int>> b[1000001];
std::set<int> s[1000001];
template <typename T = int>
class FenwickTree {
 public:
  FenwickTree(int n = 200000) : n_(n) { Clear(); }
  void Init(int n) { n_ = n + 1, Clear(); }
  void Add(int x, const T &v) {
    x++;
    while (x <= n_) t_[x] += v, x += x & -x;
  }
  T Query(int x) {
    x++;
    T s(0);
    while (x) s += t_[x], x -= x & -x;
    return s;
  }
  void Clear() { std::memset(t_ + 1, 0, sizeof(T) * n_); }
  ~FenwickTree() {}

 private:
  int n_;
  T t_[1000005];
};
FenwickTree bit;
void Add(int f, int t) { e[E] = {t, head[f]}, head[f] = E++; }
void Dfs(int u) {
  bit.Add(cnt[a[u]], -1);
  s[cnt[a[u]]].erase(a[u]);
  cnt[a[u]]++;
  bit.Add(cnt[a[u]], 1);
  s[cnt[a[u]]].emplace(a[u]);
  for (auto &&[l, k, id] : b[u]) {
    k += bit.Query(l - 1);
    if (k > bit.Query(n)) {
      ans[id] = -1;
    } else {
      int L = 0, R = n, best = -1;
      while (L <= R) {
        int mid = (L + R) >> 1;
        if (bit.Query(mid) >= k)
          best = mid, R = mid - 1;
        else
          L = mid + 1;
      }
      ans[id] = *s[best].begin();
    }
  }
  std::vector<std::tuple<int, int, int>>().swap(b[u]);
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].to;
    Dfs(v);
  }
  bit.Add(cnt[a[u]], -1);
  s[cnt[a[u]]].erase(a[u]);
  cnt[a[u]]--;
  bit.Add(cnt[a[u]], 1);
  s[cnt[a[u]]].emplace(a[u]);
}
void Solve() {
  Read(n, q);
  bit.Init(n);
  for (int i = 1; i <= n; i++) Read(a[i]);
  E = 0, std::memset(head + 1, -1, 4 * n);
  std::set<int>().swap(s[0]);
  for (int i = 1; i <= n; i++) s[0].emplace_hint(s[0].end(), i);
  bit.Add(0, n);
  for (int i = 2; i <= n; i++) Add(Read(), i);
  for (int i = 1; i <= q; i++) {
    int v = Read(), l = Read(), k = Read();
    b[v].emplace_back(l, k, i);
  }
  Dfs(1);
  for (int i = 1; i <= q; i++) Write(ans[i], " \n"[i == n]);
}
int main(int argc, char const *argv[]) {
  Read(T);
  while (T--) Solve();
  return 0;
}