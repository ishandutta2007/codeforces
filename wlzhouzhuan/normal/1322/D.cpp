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

const int N = 5005;

struct node {
  int l, s;
//  friend bool operator < (const node &x, const node &y) {
//    return x.l < y.l;
//  }
} a[N]; 
ll f[N][N];
int cost[N];
int n, m;

int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i].l = read();
  for (int i = 1; i <= n; i++) a[i].s = read();
  for (int i = 1; i <= n + m; i++) cost[i] = read();
//  sort(a + 1, a + n + 1);
  memset(f, 192, sizeof(f));
  for (int i = 0; i <= n + m + 1; i++) f[i][0] = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 0; j--) {
      ckmax(f[a[i].l][j + 1], f[a[i].l][j] - a[i].s + cost[a[i].l]);
    }
    for (int j = a[i].l, lim = n; j <= n + m; j++, lim /= 2) {
      for (int k = 0; k <= lim; k++) {
        ckmax(f[j + 1][k / 2], f[j][k] + 1ll * (k / 2) * cost[j + 1]);
      }
    }
  }
  printf("%lld\n", f[n + m + 1][0]);
  return 0;
}

/*
5 4
4 3 1 2 1
1 2 1 2 1
1 2 3 4 5 6 7 8 9
*/