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

const int N = 105;
int dist[N], one[N], a[N][N];
int n, m;

void work() {
  n = read(), m = read();
  for (rint i = 0; i <= n + m; i++) dist[i] = one[i] = 0;
  for (rint i = 0; i < n; i++) {
    for (rint j = 0; j < m; j++) {
      a[i][j] = read();
      dist[i + j]++;
      one[i + j] += a[i][j];
    }
  }
  int ans = 0;
  for (rint i = 0, j = n + m - 2; i < j; i++, j--) {
    int all = dist[i] + dist[j];
    int tot = one[i] + one[j];
    ans += min(tot, all - tot);
  }
  printf("%d\n", ans);
}

int main() {
  int T = read();
  while (T--) work();
  return 0;
}