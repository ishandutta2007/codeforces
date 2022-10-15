#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, l, r) for (int i = l; i <= r; i++) 
#define per(i, l, r) for (int i = l; i >= r; i--)

inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char ch) {
  print(x), putchar(ch);
}

template<typename T1, typename T2> void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

const int N = 1005;
char s[N], t[N];
int n, m;

void solve() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      bool ok = 1;
      int tail = 1;
      for (int k = i; k <= j; k++) if (s[k] != t[k - i + 1]) ok = 0;
      int _ = j - i + 2;
      for (int k = j - 1; k >= 1 && _ <= m; k--, _++) {
        if (s[k] != t[_]) ok = 0;
      }
      if (ok && _ == m + 1) { puts("YES"); return ; }
    }
  }
  puts("NO");
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}