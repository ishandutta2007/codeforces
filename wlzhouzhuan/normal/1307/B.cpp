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
#define debug(x) cerr << #x << " = " << x << '\n';
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

const int N = 100002;
int a[N], n, x;
bool find(int x) {
  for (rint i = 1; i <= n; i++) if (a[i] == x) return 1;
  return 0;
}
int main() {
  int T = read(); while (T--) {
    n = read(), x = read();
    for (rint i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    if (find(x)) { puts("1"); continue; }
    if (a[n] >= x) printf("2\n");
    else printf("%d\n", (int)ceil(x / 1.0 / a[n])); 
  }
  return 0;
}