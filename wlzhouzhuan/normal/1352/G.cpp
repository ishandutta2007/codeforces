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

int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
void print(int x) {
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

int b[1002], n, m;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n <= 3) {
      puts("-1");
      continue;
    }
    if (n == 4) {
      puts("3 1 4 2");
      continue;
    }
    if (n & 1) {
      m = 0;
      for (int i = 1; i <= n; i += 2) {
        b[++m] = i;
      }
      b[++m] = n - 3;
      b[++m] = n - 1;
      for (int i = n - 5; i >= 2; i -= 2) {
        b[++m] = i;
      }
    } else {
      m = 0;
      for (int i = 1; i <= n; i += 2) {
        b[++m] = i;
      }
      b[++m] = n - 4;
      b[++m] = n;
      b[++m] = n - 2;
      for (int i = n - 6; i >= 2; i -= 2) {
        b[++m] = i;
      }
    }
    for (int i = 1; i <= m; i++) {
      printf("%d ", b[i]);
    }
    puts("");
  }
  return 0;
}