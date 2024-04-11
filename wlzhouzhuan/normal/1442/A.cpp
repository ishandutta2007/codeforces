#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long


namespace IO {
  const int SIZE = 1 << 20;
  char buf[SIZE], *p1 = buf, *p2 = buf;
  char obuf[SIZE], *O = obuf;
  int getc() {
    return getchar();
    //return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
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

const int N = 30005;
int n, a[N], b[N], c[N];

int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    a[1] = c[1], b[1] = 0;
    int ok = 1;
    for (int i = 2; i <= n; i++) {
      int ups = min(a[i - 1], c[i] - b[i - 1]);
      if (ups < 0) {
        ok = 0; break;
      }
      a[i] = ups, b[i] = c[i] - ups;
    }
    if (!ok) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
}