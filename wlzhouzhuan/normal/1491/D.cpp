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
int a, b;
void work() {
  a = read(), b = read();
  while (a < b) {
    for (int i = 29; i >= 0; i--) {
      int bitA = a >> i & 1, bitB = b >> i & 1;
      if (!bitA && bitB) {
        int qwq = -1;
        for (int j = i; j >= 0; j--) {
          if ((a >> j & 1) && (a + (1 << j)) <= b) {
            qwq = j;
            break;
          }
        }
//        printf("qwq = %d\n", qwq);
        if (qwq == -1) {
          puts("NO");
          return ;
        }
        a += 1 << qwq;
        break;
      }
    }
  }
  if (a == b) puts("YES");
  else puts("NO");
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}