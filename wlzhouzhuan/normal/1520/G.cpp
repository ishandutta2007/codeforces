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

const int N = 2005;
const ll inf = 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int a[N][N];
int n, m, w;

ll S[N][N], T[N][N], ans = inf;

void bfs(ll dis[N][N], int sx, int sy) {
  rep(i, 1, n) rep(j, 1, m) dis[i][j] = inf;
  queue<pii> q; q.push({sx, sy}), dis[sx][sy] = 0;
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    for (int d = 0; d < 4; d++) {
      pii v = {u.fir + dx[d], u.sec + dy[d]};
      if (v.fir < 1 || v.fir > n || v.sec < 1 || v.sec > m || a[v.fir][v.sec] < 0) continue;
      if (dis[v.fir][v.sec] > dis[u.fir][u.sec] + w) {
        dis[v.fir][v.sec] = dis[u.fir][u.sec] + w;
        q.push(v);
      }
    }
  }
}

int main() {
  n = read(), m = read(), w = read();
  rep(i, 1, n) rep(j, 1, m) a[i][j] = read();
  bfs(S, 1, 1), bfs(T, n, m);
  ckmin(ans, S[n][m]);
  ll pref = inf, preg = inf; 
  rep(i, 1, n) {
    rep(j, 1, m) {
      if (a[i][j] <= 0) continue;
      ckmin(pref, S[i][j] + a[i][j]);
      ckmin(preg, T[i][j] + a[i][j]);
    }
  }
  ckmin(ans, pref + preg);
  if (ans == inf) puts("-1");
  else print(ans, '\n');
  return 0;
}