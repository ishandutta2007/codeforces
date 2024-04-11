// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
const int N = 100005;
string s;
int x[N], n;
int dp[N][2][2];
int main() {
  int T = read();
  while (T--) {
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 0; i <= n; i++) {
      dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 1e9;
    }
    dp[1][0][0] = 0, dp[1][0][1] = dp[1][1][0] = 1, dp[1][1][1] = 2;
    for (int i = 2; i <= n; i++) {
      if (s[i] == s[i - 2]) {
        dp[i][0][1] = min(dp[i - 1][1][0] + 1, dp[i - 1][0][0] + 1);
        dp[i][1][1] = min(dp[i - 1][1][1] + 1, dp[i - 1][0][1] + 1);
        if (s[i] != s[i - 1]) {
          dp[i][0][0] = dp[i - 1][1][0];
        }
        dp[i][1][0] = dp[i - 1][1][1];
      } else {
        if (s[i] == s[i - 1]) {
          dp[i][0][1] = min(dp[i - 1][0][0] + 1, dp[i - 1][1][0] + 1);
          dp[i][1][0] = min(dp[i - 1][1][1], dp[i - 1][0][1]);
          dp[i][1][1] = min(dp[i - 1][1][1] + 1, dp[i - 1][0][1] + 1);
        } else {
          dp[i][0][1] = min(dp[i - 1][0][0] +1, dp[i - 1][1][0] + 1);
          dp[i][1][0] = min(dp[i - 1][1][1], dp[i - 1][0][1]);
          dp[i][1][1] = min(dp[i - 1][1][1] + 1, dp[i - 1][0][1] + 1);
          dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][0][0]);
        }
      }      
    }
    int ans = 1e9;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        ckmin(ans, dp[n][j][k]);
      }
    }
    printf("%d\n", ans);
  }
}
/*
const int N = 100005;
const int inf = 1e9;
char a[N];
int dp[2][26][26], pre[26][26], suf[26][26], n;
int main() {
  int T;
  for (T = read(); T; T--) {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    if (n == 1) {
      puts("0"); continue;
    }
    if (n == 2) {
      if (a[1] == a[2]) puts("1");
      else puts("0");
      continue;
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) a[i] -= 'a';
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        dp[1][i][j] = (a[1] != i) + (a[2] != j);
      }
    }
    for (int i = 3; i <= n; i++) {
      memcpy(dp[0], dp[1], sizeof(dp[1]));
      for (int k = 0; k < 26; k++) {
        for (int j = 0; j < 26; j++) {
          if (j == 0) pre[j][k] = dp[0][j][k];
          else pre[j][k] = min(pre[j - 1][k], dp[0][j][k]);
        }
        for (int j = 25; j >= 0; j--) {
          if (j == 25) suf[j][k] = dp[0][j][k];
          else suf[j][k] = min(suf[j + 1][k], dp[0][j][k]);
        }
      }
      memset(dp[1], 0x3f, sizeof(dp[1]));
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
          if (j == k) continue;
          ckmin(dp[1][j][k], (k > 0 ? pre[k - 1][j] : inf) + (k + 25 ? suf[k + 1][j] : inf));
        }
      }
    }
    int ans = 1e9;
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        ckmin(ans, dp[1][j][k]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
*/