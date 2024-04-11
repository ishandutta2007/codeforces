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

const int N = 105;
char s[N];
int n;

int main() {
  int T = read();
  while (T--) {
    n = read();
    int cnt1 = 0, cnt2 = 0;
    for (rint i = 0; i < n; i++) {
      int x = read();
      if (i % 2 == 1) {
        if (x % 2 == 0) cnt1++;
      } else {
        if (x % 2 == 1) cnt2++;
      }
    }
    if (cnt1 == cnt2) {
      printf("%d\n", cnt1);
    } else {
      printf("-1\n");
    }
  } 
  return 0;
}