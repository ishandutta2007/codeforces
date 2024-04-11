// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

namespace IO {
  const int SIZE = 1 << 20;
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
    ~Flusher() { flush(); }
  } flusher;
}
using namespace IO;

const int N = 1502;
const int inf = 1e9;

struct Vec {
  pii a[12];
  int p;
  Vec() { p = 0; fill(a, a + 12, make_pair(0, 0)); }
  Vec(pii x) { a[0] = x, p = 1; fill(a + 1, a + 12, make_pair(0, 0)); }
  void pb(pii x) { a[p++] = x; }
  int size() { return p; }
  pii operator [] (int x) {
    return a[x];
  }
} a[N][N], col[N][N];
int c[N][N], ans[N], n, q;

pii goal;
int dis(pii x, pii y) {
  return max(abs(x.fir - y.fir), abs(x.sec - y.sec));
}
int vis[N * N];
Vec merge(Vec a, Vec b) {
  Vec cc;
  int x = 0, y = 0;
  while (cc.size() <= q && (x < a.size() || y < b.size())) {
    if (x == a.size() || (y != b.size() && dis(goal, a[x]) >= dis(goal, b[y]))) {
//      assert(y != b.size());
      if (!vis[c[b[y].fir][b[y].sec]]) cc.pb(b[y]);
      vis[c[b[y].fir][b[y].sec]] = 1, y++;
    } else {
      if (!vis[c[a[x].fir][a[x].sec]]) cc.pb(a[x]);
      vis[c[a[x].fir][a[x].sec]] = 1, x++;
    }
  }
  for (int i = 0; i < a.size(); i++) vis[c[a[i].fir][a[i].sec]] = 0;
  for (int i = 0; i < b.size(); i++) vis[c[b[i].fir][b[i].sec]] = 0;
  return cc;
}

int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c[i][j] = read();
    }
  }
  for (int i = n; i >= 1; i--) {
    Vec cur;
    for (int j = n; j >= 1; j--) {
      goal = {i, j};
      cur = merge(cur, Vec({i, j}));
      col[i][j] = merge(col[i + 1][j], Vec({i, j}));
      a[i][j] = merge(merge(cur, col[i][j]), a[i + 1][j + 1]);
      
      //printf("[%d, %d]: ", i, j);
      //for (int k = 0; k <= q; k++) printf("[pos = (%d, %d), col = %d] ", a[i][j][k].fir, a[i][j][k].sec, c[a[i][j][k].fir][a[i][j][k].sec]);
      //puts("");
      
      ans[min({n - i + 1, n - j + 1, 
               a[i][j].size() > q ? dis(goal, a[i][j][q]) : inf
              })]++;
    }
  }
  for (int i = n; i >= 1; i--) ans[i] += ans[i + 1];
  for (int i = 1; i <= n; i++) print(ans[i], '\n');
  return 0;
}