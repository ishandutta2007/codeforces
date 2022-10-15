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
#define pll pair <ll, ll>

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

const int N = 1000005;

char a[N], b[N];
int c[N], n;

int calc(int opt) {
  int cur = 0, ans = 0;
  for (rint i = 1; i <= n; i++) {
    cur += opt * c[i];
    if (cur > ans) ans = cur;
    if (cur < 0) cur = 0;
  }
  return ans;
}

int main() {
  scanf("%d%s%s", &n, a + 1, b + 1);
  int sum = 0;
  for (rint i = 1; i <= n; i++) {
    a[i] -= '0', b[i] -= '0';
    if (a[i] != b[i]) {
      if (a[i]) c[i] = 1;
      else c[i] = -1;
    }
    sum += c[i];
  }
  if (sum != 0) {
    puts("-1"); exit(0);
  }
  printf("%d\n", max(calc(1), calc(-1)));
  return 0;
}