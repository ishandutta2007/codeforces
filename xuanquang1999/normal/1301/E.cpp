#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, m, k, q;
int dpTL[MAXN][MAXN], dpTR[MAXN][MAXN], dpBL[MAXN][MAXN], dpBR[MAXN][MAXN];
int f[MAXN/2][MAXN][MAXN];
char s[MAXN][MAXN];

int calc(int k, int x1, int y1, int x2, int y2) {
  // printf("%d %d %d %d %d\n", k, x1, y1, x2, y2);
  return f[k][x2][y2] - f[k][x1-1][y2] - f[k][x2][y1-1] + f[k][x1-1][y1-1];
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if (s[i-1][j-1] == 'R')
        dpTL[i][j] = min(min(dpTL[i-1][j], dpTL[i][j-1]), dpTL[i-1][j-1]) + 1;
      else
        dpTL[i][j] = 0;
    }
  }
      
  for(int i = 1; i <= n; ++i) {
    for(int j = m; j >= 1; --j) {
      if (s[i-1][j-1] == 'G')
        dpTR[i][j] = min(min(dpTR[i-1][j], dpTR[i][j+1]), dpTR[i-1][j+1]) + 1;
      else
        dpTR[i][j] = 0;
    }
  }

  for(int i = n; i >= 1; --i) {
    for(int j = 1; j <= m; ++j) {
      if (s[i-1][j-1] == 'Y')
        dpBL[i][j] = min(min(dpBL[i+1][j], dpBL[i][j-1]), dpBL[i+1][j-1]) + 1;
      else
        dpBL[i][j] = 0;
    }
  }

  for(int i = n; i >= 1; --i) {
    for(int j = m; j >= 1; --j) {
      if (s[i-1][j-1] == 'B')
        dpBR[i][j] = min(min(dpBR[i+1][j], dpBR[i][j+1]), dpBR[i+1][j+1]) + 1;
      else
        dpBR[i][j] = 0;
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int x = min(min(dpTL[i][j], dpTR[i][j+1]), min(dpBL[i+1][j], dpBR[i+1][j+1]));
      for(int t = 1; t <= x; ++t)
        ++f[t][i][j];

      // printf("%d ", x);
    }
    // puts("");
  }

  k = min(n, m) / 2;
  for(int x = 1; x <= k; ++x)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= m; ++j) 
        f[x][i][j] += f[x][i-1][j] + f[x][i][j-1] - f[x][i-1][j-1];
          
  for(int iq = 1; iq <= q; ++iq) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // printf("%d %d %d %d\n", x1, y1, x2, y2);

    int lo = 1, hi = (min(x2 - x1, y2 - y1) + 1) / 2, res = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      int x = calc(mid, x1 + mid - 1, y1 + mid - 1, x2 - mid, y2 - mid);
      if (x >= 1) {
        res = max(res, mid);
        lo = mid + 1;
      } else 
        hi = mid - 1;
    }

    int ans = 4 * res * res;
    printf("%d\n", ans);
  }
      
  return 0;
}