// Author: wlzhouzhuan
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
int read() {
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

const int N = 505;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, 1, -1, 1, -1, 0};

int qwq[N][N];
int n, m;

void solve() {
  n = read(), m = read();
  rep(i, 1, n) rep(j, 1, m) qwq[i][j] = 0;
  vector<pii> ans;
  for (int i = 1; i < m; i++) ans.pb({1, i});
  for (int i = 1; i < n; i++) ans.pb({i, m});
  for (int i = m; i > 1; i--) ans.pb({n, i});
  for (int i = n; i > 1; i--) ans.pb({i, 1});
//  for (auto v: ans) printf("%d %d\n", v.fir, v.sec);
  for (auto it: ans) {
    bool ok = 1;
    for (int d = 0; d < 8; d++) {
      int fx = it.fir + dx[d], fy = it.sec + dy[d];
      if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && qwq[fx][fy]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      qwq[it.fir][it.sec] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", qwq[i][j]);
    }
    puts("");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}