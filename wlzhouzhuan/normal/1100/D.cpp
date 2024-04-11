// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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

bool vis[1005][1005];
int x[667], y[667], area[2][2];
int sx, sy;

bool two;
void move(int dx, int dy) {
  if (vis[sx + dx][sy + dy]) dy = 0;
  sx += dx, sy += dy;
  if (two) assert(sx <= 999 && sy <= 999);
  printf("%d %d\n", sx, sy), fflush(stdout);
  int k, X, Y;
  scanf("%d%d%d", &k, &X, &Y);
  if (k == -1) exit(0);
  if (!k) exit(0);
  vis[x[k]][y[k]] = 0;
  x[k] = X, y[k] = Y;
  vis[x[k]][y[k]] = 1;
}

int main() {
  scanf("%d%d", &sx, &sy);
  rep(i, 1, 666) x[i] = read(), y[i] = read(), vis[x[i]][y[i]] = 1;
  while (sx != 500 && sy != 500) {
    move(sx < 500 ? 1 : -1, sy < 500 ? 1 : -1);
  } 
  while (sx != 500) move(sx < 500 ? 1 : -1, 0);
  while (sy != 500) move(0, sy < 500 ? 1 : -1);
  rep(i, 1, 666) area[x[i] > 500][y[i] > 500]++;
  int d1 = 0, d2 = 0;
  rep(i, 0, 1) rep(j, 0, 1) if (area[i][j] < area[d1][d2]) d1 = i, d2 = j;
  d1 ^= 1, d2 ^= 1;
  if (!d1) d1 = -1;
  if (!d2) d2 = -1;
//  two = 1;
  while (1) move(d1, d2);
  return 0;
}