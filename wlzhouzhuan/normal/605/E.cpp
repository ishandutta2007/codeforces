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

const int N = 1005;
double p[N][N], coef[N], E[N];
int vis[N], n;

int main() {
  n = read();
  rep(i, 1, n) rep(j, 1, n) p[i][j] = read() / 100.0;
  rep(i, 1, n) coef[i] = 1, E[i] = 1;
  coef[n] = 0, E[n] = 0;
  rep(i, 1, n) {
    double minv = 1e9; int x = 0;
    rep(j, 1, n) {
      if (!vis[j] && E[j] / (1 - coef[j]) < minv) {
        minv = E[j] / (1 - coef[j]);
        x = j;
      }
    }
    vis[x] = 1;
    rep(j, 1, n) {
      if (!vis[j]) {
        E[j] += p[j][x] * E[x] / (1 - coef[x]) * coef[j];
        coef[j] *= 1 - p[j][x];
      }
    }
  }
//  rep(i, 1, n) printf("E[%d] = %.10f\n", i, E[i] / (1 - coef[i]));
   
  printf("%.10f\n", E[1] / (1 - coef[1]));
  return 0;
}