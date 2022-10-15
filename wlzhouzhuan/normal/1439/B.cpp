// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }

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
    if (O == obuf + SIZE) fwrite(obuf, O - obuf, 1, stdout), O = obuf; 
  }
  template<typename T> void print(T x, char opt) {
    print(x), *O++ = opt;
  } 
  void Flush() {
    fwrite(obuf, O - obuf, 1, stdout);
  }
}
using namespace IO;

const int N = 100005;
const int M = 200005;
const int K = 11;

struct EdgeExist {
  int b1[N][N / (1 << K) + 3], bid;
  ull b2[M][1 << (K - 6)];
  void ins(int u, int v) {
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    if (!b1[u][id]) b1[u][id] = ++bid;
    b2[b1[u][id]][v2 >> 6] |= 1ull << (v2 & 63);
  }
  void del(int u, int v) {
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    b2[b1[u][id]][v2 >> 6] ^= 1ull << (v2 & 63);
  }
  void delb(int u, int v) {
    bid = 0;
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    b1[u][id] = 0;
  }
  bool qry(int u, int v) {
    int id = v / (1 << K), v2 = v & ((1 << K) - 1);
    if (!b1[u][id]) return 0;
    return b2[b1[u][id]][v2 >> 6] >> (v2 & 63) & 1;
  }
} o;

vector<int> adj[N];

struct node {
  int u, v;
} e[N];
int deg[N], ban[N];
int tmp[N], len;
int n, m, k;

void rollback() {
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    o.del(u, v), o.del(v, u);
  }
  for (int i = 1; i <= m; i++) {
    int u = e[i].u, v = e[i].v;
    o.delb(u, v), o.delb(v, u);
  }
}
void solve() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    adj[i].clear(), deg[i] = ban[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    o.ins(u, v), o.ins(v, u);
    e[i] = {u, v};
    adj[u].push_back(v), adj[v].push_back(u); 
    deg[u]++, deg[v]++;
  }
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 1; i <= n; i++) pq.push(make_pair(deg[i], i));
  int tag = 0;
  while (!pq.empty()) {
    pii qwq = pq.top(); pq.pop();
    if (deg[qwq.sec] != qwq.fir) continue;
    //printf("node[%d], deg (%d)\n", qwq.sec, qwq.fir);
    int u = qwq.sec;
    if (deg[u] >= k) {
      tag = 1; break;
    }
    if (deg[u] == k - 1 && 1ll * k * (k - 1) / 2 <= m) {
      tmp[len = 1] = u;
      for (auto v: adj[u]) if (!ban[v]) tmp[++len] = v;
      int ok = 1;
      for (int i = 1; i <= len; i++) {
        for (int j = i + 1; j <= len; j++) {
          if (!o.qry(tmp[i], tmp[j])) {
            ok = 0; break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        print(2, '\n');
        for (int i = 1; i <= len; i++) print(tmp[i], " \n"[i == len]);
        tag = 2;
        break;
      }
    }
    for (auto v: adj[u]) {
      if (!ban[v]) {
        deg[v]--;
        pq.push(make_pair(deg[v], v));
      }
    }
    ban[u] = 1; 
  }
  if (tag == 1) {
    print(1, ' ');
    len = 0;
    for (int i = 1; i <= n; i++) if (!ban[i]) tmp[++len] = i;
    print(len, '\n');
    for (int i = 1; i <= len; i++) print(tmp[i], " \n"[i == len]);
  }
  if (tag == 0) print(-1, '\n');
  rollback(); 
}
int main() {
  int T = read();
  while (T--) solve();
  Flush();
  return 0;
}