//113D
#include<stdio.h>

const double zero = 1e-19;

double ma[490][490], p[25], ans[25], cnt[25], td;
bool g[25][25];
int n, m, t1, t2, a, b;

inline long double abss(const long double &a) {return a<-a?-a:a;}

double f(const int &a, const int &b, const int &x, const int &y) {
  if (a == b) return 0;
  
  double ret = 1;
  
  if (a == x) {
    ret = ret * p[a];
  } else if (g[a][x]) {
    ret = ret * (1 - p[a]) / cnt[a];
  } else {
    ret = 0;
  }
  
  if (b == y) {
    ret = ret * p[b];
  } else if (g[b][y]) {
    ret = ret * (1 - p[b]) / cnt[b];
  } else {
    ret = 0;
  }
  
  return ret;
}

int main() {
  scanf("%d %d %d %d", &n, &m, &a, &b);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t1, &t2);
    g[t1][t2] = true;
    g[t2][t1] = true;
    cnt[t1]++;
    cnt[t2]++;
  }
  
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      t1 = (i - 1) * n + j;
      for (int k = 1; k <= n; k++) {
        for (int t = 1; t <= n; t++) {
          t2 = (k - 1) * n + t;
          ma[t1][t2] = f(k, t, i, j);
          if (t1 == t2) ma[t1][t2] -= 1;
        }
      }
    }
  }
  
  t1 = n * (a - 1) + b;
  for (int i = 1; i <= n * n; i++) {
    ma[t1][i] = 0;
  }
  ma[t1][t1] = 1;
  ma[t1][n * n + 1] = 1;
  /*
  for (int i = 1; i <= n * n; i++) {
    for (int j = 1; j <= n * n + 1; j++) {
      printf("%lf ", ma[i][j]);
    }
    printf("\n");
  }  
  */
  for (int i = 1; i <= n * n; i++) {
    if (abss(ma[i][i]) < zero) {
      for (int j = i + 1; j <= n * n; j++) {
        if (abss(ma[j][i]) > zero) {
          for (int k = i; k <= n * n + 1; k++) {
            td = ma[i][k];
            ma[i][k] = ma[j][k];
            ma[j][k] = td;
          }
          break;
        }
      }
    }
    for (int j = i + 1; j <= n * n; j++) {
      if (abss(ma[j][i]) > zero) {
        td = ma[j][i] / ma[i][i];
        for (int k = i; k <= n * n + 1; k++) {
          ma[j][k] = ma[j][k] - td * ma[i][k];
        }
      }
    }
  }
  
  for (int i = n * n; i >= 1; i--) {
    for (int j = i + 1; j <= n * n; j++) {
      if (abss(ma[i][j]) > zero) {
        ma[i][n * n + 1] = ma[i][n * n + 1] - ma[j][n * n + 1] * ma[i][j];
        ma[i][j] = 0;
      }
    }
    ma[i][n * n + 1] = ma[i][n * n + 1] / ma[i][i];
    ma[i][i] = 1;
  }  
  
  td = 0;
  for (int i = 1; i <= n; i++) {
    td += ma[n * (i - 1) + i][n * n + 1];
  }
  
  for (int i = 1; i <= n; i++) {
    ans[i] = ma[n * (i - 1) + i][n * n + 1] / td;
  }
  
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%.12lf", ans[i]);
  }
  
  return 0;
}