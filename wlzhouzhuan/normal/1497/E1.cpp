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

const int inf = 1e9;

int to[10000005];
int dp[200005][25];
int a[200005], nxt[200005][25], buc[10000005], n, k;

void ckmin(int &a, int b) {
  if (a > b) a = b;
}

void solve() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    a[i] = to[a[i]];
//    printf("%d ", a[i]);
  }
  for (int i = 0; i <= k; i++) nxt[n + 1][i] = n;
  for (int i = n; i >= 1; i--) {
    memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i + 1]));
    if (buc[a[i]]) {
      int t = buc[a[i]];
      int j = 0;
      while (j <= k && nxt[i][j] <= t - 1) j++;
      for (int t = k; t > j; t--) nxt[i][t] = nxt[i][t - 1];
      nxt[i][j] = t - 1;
    }
    buc[a[i]] = i;
//    printf("nxt[%d]: ", i);
//    for (int j = 1; j <= k; j++) {
//      printf(" [%d] = %d, ", j, nxt[i][j]);
//    }
//    puts("");
  }
  for (int i = 1; i <= n; i++) buc[a[i]] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int jj = 0; jj + j <= k; jj++) {
        ckmin(dp[nxt[i][jj]][j + jj], dp[i - 1][j] + 1);
      } 
    }
  }
  int ans = inf;
  for (int j = 0; j <= k; j++) ckmin(ans, dp[n][j]);
  printf("%d\n", ans); 
}

int main() {
  for (int i = 1; i <= 10000; i++) {
    for (int j = i * i; j <= 10000000; j += i * i) {
      to[j] = j / i / i;
    } 
  }
//  cerr << clock() << '\n';
  int T = read();
  while (T--) solve();
  return 0;
}