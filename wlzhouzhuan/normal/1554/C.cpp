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

int n, m;

int main() {
  int T = read();
  while (T--) {
    n = read(), m = read();
    int las = 0, ans = 0;
    for (int i = 30; i >= 0; i--) {
      // go 0 ?
      if (n >> i & 1) las += 1 << i;
      if (las > m) { break; }
      if (las + (1 << i) - 1 <= m) {
        if (n >> i & 1) las -= 1 << i;
        if (!(n >> i & 1)) las += 1 << i;
        ans += 1 << i;
//        printf("i = %d, go 1\n", i);
      } else {
//        printf("i = %d, go 0\n", i);
      }
//      printf("ans = %d, las = %d\n", ans, las);
    }
    printf("%d\n", ans);
  }
  return 0;
}