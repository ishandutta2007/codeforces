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

const int N = 500005;
char s[N];
int a[N], n;
int T;

int main() {
  scanf("%d", &T); while (T--) {
    scanf("%d%s", &n, s + 2);
    for (rint i = 1; i <= n; i++) a[i] = n + 1 - i;
    for (rint i = 2; i <= n; i++) {
      if (s[i] == '>') continue;
      int j = i;
      while (s[j + 1] == '<') j++;
      for (rint p = i - 1, q = j; p < q; p++, q--) swap(a[p], a[q]);
      i = j;
    }
    for (rint i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
    for (rint i = 1; i <= n; i++) a[i] = i;
    for (rint i = 2; i <= n; i++) {
      if (s[i] == '<') continue;
      int j = i;
      while (s[j + 1] == '>') j++;
      for (rint p = i - 1, q = j; p < q; p++, q--) swap(a[p], a[q]);
      i = j;
    }
    for (rint i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
  }
}