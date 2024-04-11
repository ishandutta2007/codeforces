// Author: wlzhouzhuan
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 200005;
int f[N][18], g[N][18];
int a[N], n, m, q;

int main() {
  n = read(), m = read();
  rep(i, 1, n) a[i] = read(), g[a[i]][0]++;
  rep(j, 1, 17) {
    rep(i, 1, m - (1 << j) + 1) {
      g[i][j] = g[i][j - 1] + g[i + (1 << j - 1)][j - 1];
      f[i][j] = f[i][j - 1] ^ f[i + (1 << j - 1)][j - 1] ^ (g[i + (1 << j - 1)][j - 1] & 1 ? (1 << j - 1) : 0);
    }
  }
  q = read();
  while (q--) {
    int l = read(), r = read() + 1; 
    int bit = 0, now = l, ans = 0;
    per(j, 17, 0) {
      if (now + (1 << j) <= r) {
        ans ^= f[now][j] ^ (g[now][j] & 1 ? bit : 0);
        now += 1 << j;
        bit += 1 << j;
      }
    }
    if (ans) putchar('A');
    else putchar('B');
  }
  return 0;
}