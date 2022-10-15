// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

int a[N], b[N], p[N], n;
int mxa, mxb;

int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i] = read();
  p[0] = 1e9, p[n + 1] = 1e9;
  for (int i = 1; i <= n; i++) {
    if (p[i - 1] > p[i]) a[i] = 1;
    else a[i] = a[i - 1] + 1;
    mxa = max(mxa, a[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (p[i] < p[i + 1]) b[i] = 1;
    else b[i] = b[i + 1] + 1;
    mxb = max(mxb, b[i]);
  }
  int zz = 0, xay = 0;
  for (int i = 1; i <= n; i++) {
    zz += mxa == a[i];
  }
  for (int i = 1; i <= n; i++) {
    xay += mxb == b[i];
  }
  for (int i = 2; i < n; i++) {
    if (p[i - 1] < p[i] && p[i] > p[i + 1]) {
      //cerr << i << '\n';
      if (a[i] == b[i] && (a[i] % 2 == 1)) {
        if (zz == 1 && xay == 1) {
          if (mxa == a[i] && mxb == b[i]) {
            printf("%d\n", 1);
            return 0;
          }
        }
      }
    }
  }
  puts("0");
  return 0;
}