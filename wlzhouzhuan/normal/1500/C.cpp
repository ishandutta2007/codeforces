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

const int N = 1505;

int a[N][N], b[N][N], deg[N], n, m;
int vis[N], id[N];

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = read();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = read();
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[i][j] > b[i + 1][j]) deg[j]++;
    }
  }
  vector<int> ans;
  queue<int> q;
  for (int i = 1; i <= m; i++) {
    if (!deg[i]) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ans.pb(u);
    for (int i = 1; i < n; i++) {
      if (!vis[i] && b[i][u] != b[i + 1][u]) {
        vis[i] = 1;
        for (int j = 1; j <= m; j++) {
          if (b[i][j] > b[i + 1][j]) {
            deg[j]--;
            if (!deg[j]) q.push(j);
          }
        }
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 1; i <= n; i++) id[i] = i;
  for (auto v: ans) {
    stable_sort(id + 1, id + n + 1, [&](int i, int j) {
      return a[i][v] < a[j][v];
    });
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[id[i]][j] != b[i][j]) {
        puts("-1");
        return 0;
      }
    }
  }
  printf("%d\n", SZ(ans));
  for (auto v: ans) printf("%d ", v);
  puts("");
  return 0;
}