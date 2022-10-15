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

const int N = 1005;

int n;

void solve() {
  n = read();
  rep(i, 1, n) read();
  printf("%d\n", n / 2 * 6);
  for (int i = 1; i <= n; i += 2) {
    printf("1 %d %d\n", i, i + 1);
    printf("1 %d %d\n", i, i + 1);
    printf("2 %d %d\n", i, i + 1);
    printf("1 %d %d\n", i, i + 1);
    printf("1 %d %d\n", i, i + 1);
    printf("2 %d %d\n", i, i + 1);
  }
}

int main() {
  int T;
  for (scanf("%d", &T); T; T--) {
    solve();
  }
  return 0;
}