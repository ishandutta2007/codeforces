// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 100005;
int a[N], n, x, y;
void work() {
  n = read(), x = read(), y = read();
  int ok = 1;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) ok &= abs(a[i] - a[i + 1]) <= 1;
  if (!ok) {
    puts("0");
    return ;
  }
  for (int i = 1; i <= n; i++) ok &= a[i] == a[1];
  if (ok) printf("%d\n", y + min(x, y));
  else printf("%d\n", min(x, y));
}
int main() {
  int T = read();
  while (T--) work();
  return 0;
}