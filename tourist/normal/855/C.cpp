/**
 *    author:  tourist
 *    created: 24.09.2017 17:55:58       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (long long) a * b % md;
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

const int N = 1234567;

vector<int> g[N];
int f[N][12][3];
int aux[12][3];
int m, k, x;

void solve(int v, int pr) {
  for (int cnt = 0; cnt <= x; cnt++) {
    for (int type = 0; type <= 2; type++) {
      f[v][cnt][type] = 0;
    }
  }
  f[v][0][0] = k - 1;
  f[v][1][1] = 1;
  f[v][0][2] = m - k;
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    solve(u, v);
    for (int cnt = 0; cnt <= x; cnt++) {
      for (int type = 0; type <= 2; type++) {
        aux[cnt][type] = 0;
      }
    }
    for (int cnt = 0; cnt <= x; cnt++) {
      for (int type = 0; type <= 2; type++) {
        int ft = f[v][cnt][type];
        if (ft == 0) {
          continue;
        }
        for (int new_cnt = 0; cnt + new_cnt <= x; new_cnt++) {
          for (int new_type = 0; new_type <= 2; new_type++) {
            if ((type == 1 || new_type == 1) && type + new_type != 1) {
              continue;
            }
            int gt = f[u][new_cnt][new_type];
            if (gt == 0) {
              continue;
            }
            add(aux[cnt + new_cnt][type], mul(ft, gt));
          }
        }
      }
    }
    for (int cnt = 0; cnt <= x; cnt++) {
      for (int type = 0; type <= 2; type++) {
        f[v][cnt][type] = aux[cnt][type];
      }
    }
  }
}

int main() {
  int n;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  scanf("%d %d", &k, &x);
  solve(0, -1);
  int ans = 0;
  for (int cnt = 0; cnt <= x; cnt++) {
    for (int type = 0; type <= 2; type++) {
      add(ans, f[0][cnt][type]);
    }
  }
  printf("%d\n", ans);
  return 0;
}