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

int n;
void solve() {
  n = read();
  if (n % 10 == 9) cout << n / 10 + 1 << '\n';
  else cout << n / 10 << '\n'; 
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}