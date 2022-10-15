#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
auto Read() {
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
int T;
__int128_t k, las[101], ans[101], pre[101], pw[101];
void Init() {
  __int128_t c = 9;
  for (int i = 1; i <= 10; i++) {
    las[i] = las[i - 1] + c * i;
    ans[i] = (las[i - 1] + i + las[i]) * c / 2;
    c *= 10;
  }
  std::partial_sum(ans + 1, ans + 11, pre + 1);
  pw[0] = 1;
  for (int i = 1; i <= 30; i++) pw[i] = pw[i - 1] * 10;
}
__int128_t Calc(__int128_t x) {
  if (!x) return 0;
  int bt = 0;
  __int128_t tmp = x;
  while (tmp) bt++, tmp /= 10;
  __int128_t cnt = x - pw[bt - 1] + 1, l = las[bt - 1] + bt,
             r = las[bt - 1] + bt * cnt;
  return pre[bt - 1] + (l + r) * cnt / 2;
}
bool Check(__int128_t x) { return Calc(x) >= k; }
void Solve() {
  Read(k);
  __int128_t l = 1, r = 10000000000, best = r;
  while (l <= r) {
    __int128_t mid = (l + r) >> 1;
    if (Check(mid))
      best = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  k -= Calc(best - 1);
  __int128_t c = 9;
  for (int i = 1; i <= 10; i++) {
    if (k > c * i) {
      k -= c * i;
      c *= 10;
      continue;
    }
    __int128_t pos = (k + i - 1) / i, ans = pos + pw[i - 1] - 1;
    k -= (pos - 1) * i;
    int bit[101], tot = 0;
    while (ans) bit[++tot] = ans % 10, ans /= 10;
    std::reverse(bit + 1, bit + tot + 1);
    Write(bit[k], '\n');
    return;
  }
}
int main(int argc, char const *argv[]) {
  Init();
  Read(T);
  while (T--) Solve();
  return 0;
}