// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
 
namespace IO {
  const int SIZE = 1 << 23;
  char ibuf[SIZE], *iS, *iT;
  char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
  bool flush() {
    fwrite(obuf, 1, oS - obuf, stdout);
    oS = obuf;
    return true;
  }
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
  #define pc(x) (*oS++ = x) 
  int read() {
    int x = 0, f = 0;
    char c = gc();
    while (!isdigit(c)) f |= c == '-', c = gc();
    while (isdigit(c)) x = 10 * x + c - '0', c = gc();
    return f ? -x : x;
  }
  char qu[55]; int qlen;
  template <class T> void print(T x) {
    if (!x) pc('0');
    if (x < 0) pc('-'), x = -x;
    while (x) qu[++qlen] = x % 10 + '0', x /= 10;
    while (qlen) pc(qu[qlen--]);
  }
  template <class T> void print(T x, char charset) {
    print(x), pc(charset);
  }
  struct Flusher {
    ~Flusher() {
      flush();
    }
  } flusher;
}
using namespace IO;

const int N = 1005;
const int mod = 998244353;

int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

ull mul(ull a, ull b) {
  return (static_cast<unsigned long long>(a) * b) % mod;
}
int a[N], m, n;
ull fz = 1, sumfz = 0, fm = 1, ans = 0;
int j = 0;
void run(int t) {
  for (; j < t; j++) {
    fz = mul(fz, 2 * n - j);
    sumfz = mul(sumfz, (n - j)) + fz;
    fm = mul(fm, n - j);
  }
}
int main() {
  m = read();
  for (int i = 1; i <= m; i++) {
    a[i] = read(), n += a[i];
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    run(a[i]);
    ans = (ans + mul(sumfz, qpow(fm))) % mod;
  }
  run(n);
  ans = (ans + mod - mul(sumfz, qpow(fm))) % mod;
  print((mod - ans) % mod, '\n');
  return 0;
}