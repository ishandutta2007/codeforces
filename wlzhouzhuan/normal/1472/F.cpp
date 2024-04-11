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
int n, m;
void xay5421() {
  map<int, int> f;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    f[y] |= 1 << (x - 1);
  }
  f[n + 1] = 3;
  int haveLast = 0, lst = 0;
  for (auto it: f) {
    int x = it.fir, y = it.sec;
    if (y != 3) {
      if (haveLast) {
        int now = (x + y) % 2;
        if (now == lst) {
          puts("NO"); return ;
        }
        haveLast = 0;
      } else {
        lst = (x + y) % 2;
        haveLast = 1;
      }
    } else {
      if (haveLast) {
        puts("NO"); return ;
      }
    }
  }
  puts("YES"); return ;
}
int main() { 
  int T = read();
  while (T--) {
    n = read(), m = read();
    xay5421();
  }
}