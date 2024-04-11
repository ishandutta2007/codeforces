// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 1000005;
int f[N][20];
ll a[N], c[N], q;

int main() {
  q = read(), a[1] = read(), c[1] = read();
  for (int i = 2; i <= q + 1; i++) {
    int opt = read();
    if (opt == 1) {
      f[i][0] = read() + 1;
      for (int j = 1; j < 20; j++) f[i][j] = f[f[i][j - 1]][j - 1];
      a[i] = read(), c[i] = read();
    } else {
      int v = read() + 1, w = read();
      int jiba = v, jumps = 0;
      for (int j = 19; j >= 0; j--) {
        if (f[jiba][j] != 0 && a[f[jiba][j]] != 0) jiba = f[jiba][j], jumps += 1 << j;
      }
      auto son = [&](int x, int dist) {
        for (int j = 19; j >= 0; j--) {
          if (dist >> j & 1) x = f[x][j];
        }
        return x;
      };
      ll ans1 = 0, ans2 = 0;
      while (true) {
//        printf("jiba = %d, a = %d, c = %d\n", jiba, a[jiba], c[jiba]);
        if (w < a[jiba]) {
          ans1 += w, a[jiba] -= w, ans2 += 1ll * w * c[jiba];
          break;
        }
        ans1 += a[jiba], ans2 += 1ll * a[jiba] * c[jiba];
        w -= a[jiba], a[jiba] = 0;
        if (jiba == v) break;
        jiba = son(v, --jumps);
      }
      printf("%lld %lld\n", ans1, ans2);
      fflush(stdout);
    }
  }
  return 0;
}