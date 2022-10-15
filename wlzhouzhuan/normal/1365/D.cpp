// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>
#define fir first
#define sec second

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 55;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char c[N][N];
int a[N][N], n, m;

bool vis[N][N];
void bfs(int n, int m) {
  queue <pii> q;
  q.push(make_pair(n, m));
  for (rint i = 1; i <= n; i++) {
    for (rint j = 1; j <= m; j++) {
      vis[i][j] = 0;
    }
  }
  vis[n][m] = 1;
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    for (rint d = 0; d < 4; d++) {
      pii v = make_pair(u.fir + dx[d], u.sec + dy[d]);
      if (v.fir < 1 || v.fir > n || v.sec < 1 || v.sec > m) continue;
      if (!vis[v.fir][v.sec] && a[v.fir][v.sec] != 1) {
        vis[v.fir][v.sec] = 1;
        q.push(v);
      } 
    }
  }
}

void solve() {
  scanf("%d%d", &n, &m);
  vector <pii> G, B;
  for (rint i = 1; i <= n; i++) {
    scanf("%s", c[i] + 1);
    for (rint j = 1; j <= m; j++) {
      if (c[i][j] == '.') a[i][j] = 0;
      else if (c[i][j] == '#') a[i][j] = 1;
      else if (c[i][j] == 'G') G.pb(make_pair(i, j)), a[i][j] = 2;
      else B.pb(make_pair(i, j)), a[i][j] = 3;
    }
  }
  if (!G.size()) {
    puts("Yes");
    return ;
  }
  for (auto v: B) {
    for (rint d = 0; d < 4; d++) {
      pii newv = make_pair(v.fir + dx[d], v.sec + dy[d]);
      if (newv.fir < 1 || newv.fir > n || newv.sec < 1 || newv.sec > m) continue;
      if (a[newv.fir][newv.sec] == 2) {
        puts("No");
        return ;
      }
      if (!a[newv.fir][newv.sec]) {
        a[newv.fir][newv.sec] = 1; 
      }
    }
  }
  if (a[n][m]) {
    puts("No");
    return ;
  }
  bfs(n, m);
  /*
  for (auto v: B) {
    if (vis[v.fir][v.sec]) {
      puts("No");
      return ;   
    }
  }
  */
  for (auto v: G) {
    if (!vis[v.fir][v.sec]) {
      puts("No");
      return ;
    } 
  }
  puts("Yes");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}