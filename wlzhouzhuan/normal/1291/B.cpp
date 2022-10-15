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

const int N = 300005;
int a[N], n;
int b[N], c[N];

int main() {
  int T = read();
  while (T--) {
    n = read();
    for (rint i = 1; i <= n; i++) {
      a[i] = read();
      b[i] = a[i] - (i - 1);
      c[i] = a[i] - (n - i);
    }
    int Left = 0, Right = n + 1;
    while (Left < n && b[Left + 1] >= 0) Left++;
    while (Right > 0 && c[Right - 1] >= 0) Right--;
    if (Left >= Right) puts("Yes");
    else puts("No");
  } 
  return 0;
}