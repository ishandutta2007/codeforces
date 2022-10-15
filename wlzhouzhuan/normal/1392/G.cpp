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

char a[2][20];
int id[20];
int whoa[1000001], whob[1000001], n, m, k;
int f[1048576], g[1048576];

int main() {
  n = read(), m = read(), k = read();
  scanf("%s%s", a[0], a[1]);
  int one = 0;
  for (int i = 0; i < k; i++) id[i] = i, a[0][i] -= '-0', a[1][i] -= '0', one += a[0][i] + a[1][i];
  for (int i = 1; i <= n; i++) {
    whoa[i] = read() - 1, whob[i] = read() - 1;
  }
  memset(f, 0x3f, sizeof(f)), memset(g, 192, sizeof(g));
  for (int i = n + 1; i >= 1; i--) {
    if (i <= n) swap(id[whoa[i]], id[whob[i]]);
//    printf("[%d]\n", i);
//    for (int j = 0; j < k; j++) printf("id[%d] = %d, ", j, id[j]); puts("");
//    for (int j = 0; j < k; j++) printf("%d", a[0][id[j]]); puts("");
//    for (int j = 0; j < k; j++) printf("%d", a[1][id[j]]); puts("");
    int zip1 = 0, zip2 = 0;
    for (int j = 0; j < k; j++) {
      zip1 |= a[0][j] << id[j];
      zip2 |= a[1][j] << id[j];
    } 
    ckmin(f[zip1], i), ckmax(g[zip2], i);
//    printf("[%d]\n", i);
//    for (int j = 0; j < k; j++) printf("%d", a[0][j]); puts("");
//    for (int j = 0; j < k; j++) printf("%d", a[1][j]); puts("");
//    int zip1 = 0, zip2 = 0;
//    for (int j = 0; j < k; j++) {
//      zip1 |= a[0][j] << j;
//      zip2 |= a[1][j] << j;
//    }
//    ckmin(f[zip1], i), ckmax(g[zip2], i);
//    swap(a[0][whoa[i]], a[0][whob[i]]);
//    swap(a[1][whoa[i]], a[1][whob[i]]);
  }
  int all = 1 << k;
//  for (int i = 0; i < all; i++) tmpf[i] = f[i], f[i] = g[i] - f[i];
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 1 << k; j++) {
      if (!(j >> i & 1)) {
        ckmin(f[j], f[j ^ 1 << i]);
        ckmax(g[j], g[j ^ 1 << i]);
      }
    }
  }
//  cerr << "f[0] = " << f[0] << '\n';
  int ans = -1, who;
  for (int i = 0; i < all; i++) {
    if (g[i] - f[i] >= m && __builtin_popcount(i) > ans) {
      ans = __builtin_popcount(i), who = i;
    }
  }
  printf("%d\n", 2 * ans + k - one);
  printf("%d %d\n", f[who], g[who] - 1);
  return 0;
}