#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second

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

void ckmin(int &a, int b) {
  if (a > b) a = b;
}

const int N = 500005;
const int mod = 998244353;
const int inf = 1e9;

vector<pii> adj[N];
int n, m;

struct node {
  int x, y, id;
  friend bool operator < (const node &x, const node &y) {
    if (x.x ^ y.x) return x.x > y.x;
    else if (x.y ^ y.y) return x.y > y.y;
    else return x.id > y.id;
  }
};
pii dis[N];
void dijkstra1() {
  for (int i = 1; i <= n; i++) dis[i] = make_pair(inf, inf);
  dis[1] = make_pair(0, 0);
  priority_queue<node> pq;
  pq.push((node){0, 0, 1});
  while (!pq.empty()) {
    node fir = pq.top(); pq.pop();
    int u = fir.id;
    if (dis[u] < make_pair(fir.x, fir.y)) continue;
    for (auto it: adj[u]) {
      int v = it.fir;
      if (dis[v] > make_pair(dis[u].fir + it.sec, dis[u].sec + 1)) {
        dis[v] = make_pair(dis[u].fir + it.sec, dis[u].sec + 1);
        pq.push((node){dis[v].fir, dis[v].sec, v});
      }
    }
  }
}

int DIS[N][20];
void dijkstra2() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 20; j++) {
      DIS[i][j] = inf; 
    }
  }
  DIS[1][0] = 0;
  queue<pii> q;
  q.push(make_pair(1, 0));
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    for (auto it: adj[u.fir]) {
      int v = it.fir, j = u.sec + it.sec;
      if (j >= 20) continue;
      if (DIS[v][j] >= inf) {
        DIS[v][j] = DIS[u.fir][u.sec] + 1;
        q.push(make_pair(v, j));
      }
    }
  }
}
int main() {
  n = 2 * read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    adj[2 * u - 1].push_back(make_pair(2 * v - 1, 0));
    adj[2 * v].push_back(make_pair(2 * u, 0));
    adj[2 * v - 1].push_back(make_pair(2 * u, 1));
    adj[2 * u].push_back(make_pair(2 * v - 1, 1));
  }
  dijkstra1();
  pii d = min(dis[n - 1], dis[n]);
  if (d.fir >= 20) {
    ll ans = 1;
    for (int i = 0; i < d.fir; i++) ans = 2ll * ans % mod;
    ans = (ans + d.sec + mod - 1) % mod;
    printf("%lld\n", ans);
    return 0;
  } 
  dijkstra2();
  int ans = 1e9;
  for (int i = 0; i < 20; i++) {
    ckmin(ans, DIS[n][i] + (1 << i) - 1);
    ckmin(ans, DIS[n - 1][i] + (1 << i) - 1);
  }
  printf("%d\n", ans);
  return 0;
}