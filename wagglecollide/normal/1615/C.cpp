#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 100010;
const int INF = 2147483600;
int N;
char str[MAXN + 1];
int a[MAXN + 1], b[MAXN + 1];
int ans;
inline void Test() {
  N = read();
  scanf("%s", str + 1);
  for (int i = 1; i <= N; i++) a[i] = str[i] - '0';
  scanf("%s", str + 1);
  for (int i = 1; i <= N; i++) b[i] = str[i] - '0';
  ans = INF;
  for (int rot = 0; rot < 2; rot++) {
    int cur = 0, c1 = 0, c0 = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] != b[i]) {
        cur++;
        if (a[i])
          c1++;
        else
          c0++;
      }
    }
    if (c1 + rot == c0) ans = min(ans, cur);
    for (int i = 1; i <= N; i++) a[i] ^= 1;
  }
  if (ans == INF)
    puts("-1");
  else
    printf("%d\n", ans);
}
int main() {
  int T = read();
  while (T--) Test();
  return 0;
}