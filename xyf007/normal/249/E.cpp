#include <iomanip>
#include <iostream>
constexpr __int128_t operator""_LLL(unsigned long long x) { return x; }
constexpr __int128_t kLim = 10000000000_LLL;
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
constexpr int kB = 1 << 20;
char rbuf[kB + 1], *ps = rbuf + kB, wbuf[kB + 1], *po = wbuf;
char Getchar() {
  if (ps - rbuf == kB) {
    if (std::cin.read(rbuf, kB).rdstate() == std::ios_base::eofbit) return EOF;
    ps = rbuf;
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
  if (po - wbuf == kB) std::cout.write(wbuf, kB), po = wbuf;
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
  ~AutoFlusher() { std::cout.write(wbuf, po - wbuf); }
} autoflusher;
int T;
__int128_t x1, y1, x2, y2;
inline __int128_t S1(__int128_t x) { return x * (x + 1) / 2; }
inline __int128_t S2(__int128_t x) { return x * (x + 1) * (2 * x + 1) / 6; }
__int128_t Calc(__int128_t x, __int128_t y) {
  if (x == 0 || y == 0) return 0_LLL;
  if (x <= y)
    return S1(x * x) + x * (S2(y - 1) - S2(x - 1)) + (y - x) * S1(x);
  else
    return S1(y * y) + y * (S2(x) - S2(y)) - (x - y) * S1(y - 1);
}
void Solve() {
  Read(x1, y1, x2, y2);
  __int128_t tmp =
      Calc(x2, y2) - Calc(x1 - 1, y2) - Calc(x2, y1 - 1) + Calc(x1 - 1, y1 - 1);
  long long ans = tmp % kLim;
  if (tmp >= kLim) {
    std::cout << "..." << std::setw(10) << std::setfill('0') << ans << '\n';
  } else {
    std::cout << ans << '\n';
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  Read(T);
  while (T--) Solve();
  return 0;
}