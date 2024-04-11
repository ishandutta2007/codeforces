//CF 11D
/*
n<=19
DP
f[state][end] state statestateend

/2

  1
 j f[state - (1 << j)][k]f[state][j] 
 f[state][j] istate i,j
  
*/ 
#include<cstdio> 
#include<algorithm>
using namespace std;

int n, m, g[20][20], t1, t2, t3;
long long f[1050000][20], ans;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &t1, &t2);
    t1--; t2--;
    g[t1][t2] = g[t2][t1] = 1;
    f[(1 << t1) | (1 << t2)][max(t1, t2)] = 1;
  }
  
  t3 = (1 << (n + 1)) - 1;
  for (int i = 1; i < t3; i++) {
    t1 = i & (-i);
    t2 = 0;
    while (t1 = (t1 >> 1)) {
      t2++;
    }
    for (int j = t2 + 1; j < n; j++) {
      if (i & (1 << j)) {
        for (int k = t2 + 1; k < n; k++) {
          if ((i & (1 << k)) && g[k][j]) {
            f[i][j] += f[i - (1 << j)][k];
          }
        }
        if (g[t2][j] && (i - (1 << t2) - (1 << j))) {
          ans += f[i][j];
        }
      }
    }
  }
  
  ans = ans >> 1;
  printf("%I64d\n", ans);
  return 0;
}