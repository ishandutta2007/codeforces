#include <bits/stdc++.h>
using namespace std;

const int N = 6111111;
const int MX = 2e5 + 5;

bitset <N> isp;

int n, m, x, y, pr[N], cnt, g[N], l, r;

int mxw[N][8], ans[MX][15];

void prework(int n) {
  for(int i = 2; i <= n; ++ i) isp[i] = 1;
  for(int i = 1; i <= n; ++ i) {
    if(isp[i]) {
      pr[++ cnt] = i;
      g[i] = i;
    }
    for(int j = 1; j <= cnt && pr[j] * i <= n; ++ j) {
      isp[i * pr[j]] = 0;
      g[i * pr[j]] = pr[j];
      if(i % pr[j] == 0) break;
    }
  }
}

int a[N], d;

main(void) {
  prework(N - 1);
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &x);
    //cerr << x << endl;
    d = 0;
    while(x != 1) {
      int now = x;
      int t = 0;
      while(now % g[x] == 0) {
	now /= g[x];
	t ^= 1;
      }
      if(t) a[d ++] = g[x];
      x = now;
    }
    for(int j = 0; j <= 14; ++ j) ans[i][j] = ans[i - 1][j];
    for(int mask = 0; mask < (1 << d); ++ mask) {
      int x = 1, k = d;
      for(int j = 0; j < d; ++ j) {
	if((mask >> j) & 1) x = x * a[j], -- k;
      }
      for(int j = 0; j <= 7; ++ j) ans[i][j + k] = max(ans[i][j + k], mxw[x][j]);
      mxw[x][k] = i;
    }
  }
  for(; q --;) {
    scanf("%d%d", &l, &r);
    int res = 1e9;
    for(int i = 0; i <= 14; ++ i) if(ans[r][i] >= l) res = min(res, i);
    printf("%d\n", res);
  }
}