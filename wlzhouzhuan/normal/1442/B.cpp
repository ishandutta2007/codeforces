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

const int N = 200005;
const int mod = 998244353;

int a[N], b[N], l[N], r[N], ban[N];
int n, k;

void solve() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read(), l[i] = r[i] = ban[i] = 0;
  }
  for (int i = 1; i < n; i++) l[a[i + 1]] = a[i], r[a[i]] = a[i + 1];
  for (int i = 1; i <= k; i++) {
    b[i] = read(), ban[b[i]] = 1;
  }
  int ans = 1;
  for (int i = 1; i <= k; i++) {
    int cnt = 0;
    if (l[b[i]] != 0 && ban[l[b[i]]] == 0) cnt++;
    if (r[b[i]] != 0 && ban[r[b[i]]] == 0) cnt++;
    ans = 1ll * ans * cnt % mod;
    r[l[b[i]]] = r[b[i]], l[r[b[i]]] = l[b[i]];
  }
  printf("%d\n", ans);
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}