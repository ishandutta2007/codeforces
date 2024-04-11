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

const int N = 15;
char s[N]; int n;
int ans;
void solve() {
  scanf("%s", s + 1);
  n = 10;
  ans = 10;
  // all 1
  int kk = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) kk += (s[i] != '0');
    else kk -= (s[i] == '1');
    if ((kk < 0 && (n + 1) / 2 - (i + 1) / 2 + kk < 0) ||
        (kk > 0 && n / 2 - i / 2 < kk)) {
      ans = min(ans, i);
      break;
    }
  }
  // all 0 
  kk = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) kk += (s[i] == '1');
    else kk -= (s[i] != '0');
    if ((kk < 0 && (n + 1) / 2 - (i + 1) / 2 + kk < 0) ||
        (kk > 0 && n / 2 - i / 2 < kk)) {
      ans = min(ans, i);
      break;
    }
  }
  print(ans, '\n');
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}