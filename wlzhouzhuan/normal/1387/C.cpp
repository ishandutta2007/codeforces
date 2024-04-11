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
inline int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 205;
const ull inf = 9223372036854775808ull;

vector<int> adj[N];
pii to[N];
int a[N][N], id[N][N], tag[N];
int G, n, m, tot;

int ch[N][2], fail[N], End[N], AC_tot;
void ins() {
  int l = read(), rt = 0;
  rep(i, 1, l) {
    int &son = ch[rt][read()];
    if (!son) son = ++AC_tot;
    rt = son;
  }
  End[rt] = 1;
}
void build_fail() {
  queue<int> q;
  rep(i, 0, 1) if (ch[0][i]) q.push(ch[0][i]);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    End[u] |= End[fail[u]];
    rep(i, 0, 1) {
      if (ch[u][i]) {
        fail[ch[u][i]] = ch[fail[u]][i];
        q.push(ch[u][i]);
      } else {
        ch[u][i] = ch[fail[u]][i];
      }
    }
  }
//  rep(i, 0, AC_tot) {
//    printf("[Info] %d: ls = %d, rs = %d\n", i, ch[i][0], ch[i][1]);
//  }
}

struct node {
  int a, b, c;
  ull dis;
  friend bool operator < (const node &x, const node &y) {
    return x.dis > y.dis;
  }
};
priority_queue<node> pq;
ull dis[N][N][N];
bool vis[N][N][N];
void dijkstra() {
  rep(i, 0, tot) rep(j, 0, AC_tot) rep(k, 0, AC_tot) dis[i][j][k] = inf;
  rep(i, 0, AC_tot) {
    if (End[i]) continue;
    int son = ch[i][0];
    if (!End[son]) dis[0][i][son] = 1, pq.push({0, i, son, 1});
    son = ch[i][1];
    if (!End[son]) dis[1][i][son] = 1, pq.push({1, i, son, 1});
  }
  while (!pq.empty()) {
    node it = pq.top(); pq.pop();
    int a = it.a, b = it.b, c = it.c;
//    printf("%d %d %d %llu\n", a, b, c, it.dis);
    if (vis[a][b][c]) continue; vis[a][b][c] = 1;
    if (a < G) {
      for (auto u: adj[a]) {
        if (tag[u] & 1) { //  
          if (dis[u][b][c] > dis[a][b][c]) {
            dis[u][b][c] = dis[a][b][c];
//            printf("[coef 1] %d %d %d\n", u, b, c);
            pq.push({u, b, c, dis[u][b][c]});
          }
        } else { //  
          for (int d = 0; d <= AC_tot; d++) {
            if (dis[u][d][c] > dis[u - 1][d][b] + dis[a][b][c]) {
              dis[u][d][c] = dis[u - 1][d][b] + dis[a][b][c];
//              printf("[coef 2] %d %d %d\n", u, d, c);
              pq.push({u, d, c, dis[u][d][c]});
            }
          }
        }
      }
    } else if (tag[a] & 2) { // , 
      int from = ::a[to[a].fir][0];
      if (dis[from][b][c] > dis[a][b][c]) {
        dis[from][b][c] = dis[a][b][c];
//        printf("[coef 3] %d %d %d\n", from, b, c);
        pq.push({from, b, c, dis[from][b][c]});
      }
    } else { //  
      int nxt = ::a[to[a].fir][to[a].sec + 1];
      for (int d = 0; d <= AC_tot; d++) {
        if (dis[a + 1][b][d] > dis[a][b][c] + dis[nxt][c][d]) {
          dis[a + 1][b][d] = dis[a][b][c] + dis[nxt][c][d];
//          printf("[coef 4] %d %d %d\n", a + 1, b, d);
          pq.push({a + 1, b, d, dis[a + 1][b][d]});
        }
      }
    }
  }
}

int main() {
  G = read(), n = read(), m = read(), tot = G - 1;
  rep(i, 1, n) {
    a[i][0] = read(); int k = read();
    rep(j, 1, k) {
      a[i][j] = read(), id[i][j] = ++tot, to[tot] = make_pair(i, j);
      adj[a[i][j]].pb(tot);
      if (j == 1) tag[tot] |= 1;
      if (j == k) tag[tot] |= 2;
    }
  }
  rep(i, 1, m) ins();
  build_fail();
//  return 0;
  dijkstra();
  rep(i, 2, G - 1) {
    ull ans = inf;
    rep(b, 0, AC_tot) {
      rep(c, 0, AC_tot) {
        ckmin(ans, dis[i][b][c]);
      }
    }
    if (ans == inf) puts("YES");
    else printf("NO %llu\n", ans);
  }
  return 0;
}