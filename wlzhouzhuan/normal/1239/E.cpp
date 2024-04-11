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

const int N = 26;
const int M = 1300001;

bool one[N << 1];
int dp[N][M], sum;
int a[N << 1], n, len;

int main() {
  n = read();
  rep(i, 1, n) a[++len] = read();
  rep(i, 1, n) a[++len] = read();
  sort(a + 1, a + len + 1);
  rep(i, 3, len) sum += a[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  rep(i, 3, len) {
    per(j, n - 1, 1) {
      rep(k, a[i], sum / 2) {
        if (dp[j - 1][k - a[i]] != -1 && dp[j][k] == -1)
          dp[j][k] = i;
      }
    }
  }
  int t = 0;
  per(j, sum / 2, 0) {
    if (dp[n - 1][j] != -1) {
      t = j;
      break;
    }
  }
  for (int i = n - 1; i >= 1; i--) {
//    printf("dp[%d][%d] = %d\n", i, t, dp[i][t]);
    one[dp[i][t]] = 1;
    t -= a[dp[i][t]];
  }
  one[1] = 1;
  rep(i, 1, n << 1) if (one[i]) printf("%d ", a[i]); puts("");
  per(i, n << 1, 1) if (!one[i]) printf("%d ", a[i]); puts("");
  return 0; 
}