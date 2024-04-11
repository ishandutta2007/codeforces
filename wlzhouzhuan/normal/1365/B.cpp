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
#define fir first
#define sec second

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

const int N = 505;
int a[N], n;

void work() {
  n = read();
  for (rint i = 1; i <= n; i++) a[i] = read();
  int tot = 0;
  for (rint i = 1; i <= n; i++) {
    int x = read();
    tot += x;
  }
  if (tot == 0 || tot == n) {
    for (rint i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        puts("No");
        return ;
      }
    }
    puts("Yes");
  } else
    puts("Yes");
}

int main() {
  int T = read();
  while (T--) work();
  return 0;
}