// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;

namespace IO {
  const int SIZE = 1 << 25;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  char getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
  }
  int read() {
    int x = 0, f = 0;
    char ch = getc();
    while (!isdigit(ch)) f |= ch == '-', ch = getc();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getc();
    return f ? -x : x;
  }
  template<typename T> void print(T x) {
    if (x < 0) *O++ = '-', x = -x;
    if (x > 9) print(x / 10);
    *O++ = char(x % 10 + '0');
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 200005;
const int B = 1000;
int f[135][N], g[135][N];
int be[N], cnt;
int a[N], n, q;

map<int, int> ff;
int val[N], map_cnt;
int Hash(int x) {
  if (!ff[x]) {
    ff[x] = ++map_cnt;
    val[map_cnt] = x;
  }
  return ff[x];
}
int main() {
  n = read();
  cnt = (n - 1) / B + 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read(), a[i] = Hash(a[i]);
    be[i] = (i - 1) / B + 1;
  }
  for (int i = 1; i <= cnt; i++) {
    int L = (i - 1) * B + 1, R = min(i * B, n);
    memcpy(f[i], f[i - 1], sizeof(f[i - 1]));
    memcpy(g[i], g[i - 1], sizeof(g[i - 1]));
    for (int j = L; j <= R; j++) {
      f[i][a[j]]++;
      g[i][f[i][a[j]]]++;
    }
  }
  q = read();
  while (q--) {
    int opt = read(), x = read(), y = read();
    if (opt == 1) {
      for (int j = be[y]; j <= cnt; j++) {
        g[j][f[j][a[y]]]--;
        f[j][a[y]]--;
      }
      a[y] = Hash(x);
      for (int j = be[y]; j <= cnt; j++) {
        f[j][a[y]]++;
        g[j][f[j][a[y]]]++;
      }
    } else {
      if (x == 1) {
        print(val[a[y]], '\n');
        continue;
      }
      int id = be[y] - 1;
      for (int j = id * B + 1; j <= y; j++) {
        f[id][a[j]]++;
        g[id][f[id][a[j]]]++;
      }
      if (x & 1) print(g[id][f[id][a[y]]], '\n');
      else print(f[id][a[y]], '\n');
      for (int j = id * B + 1; j <= y; j++) {
        g[id][f[id][a[j]]]--;
        f[id][a[j]]--;
      }
    }
  }
  Flush();
  return 0;
}