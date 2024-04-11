// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 200005;
char s[N];
int dp[N][2][2], n;

void solve() {
  int ans = 1e9;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) s[i] = (s[i] == 'R');
  for (int x1 = 0; x1 < 2; x1++) {
    for (int x2 = 0; x2 < 2; x2++) {
      for (int i = 0; i <= n; i++) dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 1e9;
      dp[1][x2][x1] = (x2 != s[1]) + (x1 != s[0]);
      for (int i = 2; i < n; i++) {
        for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 2; k++) {
            for (int t = 0; t < 2; t++) {
              if (j == k && k == t) continue;
              ckmin(dp[i][j][k], dp[i - 1][k][t] + (j != s[i]));
            }
          }
        }
      }
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i == x1 && x1 == x2) continue;
          if (j == i && i == x1) continue;
          ckmin(ans, dp[n - 1][i][j]);
        }
      }
    }
  }
  print(ans, '\n');
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}