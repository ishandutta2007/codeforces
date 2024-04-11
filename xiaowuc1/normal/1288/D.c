#include <stdio.h>
#include <string.h>

int g[300000][8];
int reta = -1;
int retb = -1;

int n, m;
int dp[256];

int valid(int maxamt) {
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++) {
    int mask = 0;
    for(int j = 0; j < m; j++) if(g[i][j] >= maxamt) mask |= (1 << j);
    dp[mask] = i;
  }
  for(int i = 0; i < (1<<m); i++) {
    for(int j = i; j < (1<<m); j++) {
      if((i|j) == ((1<<m)-1) && dp[i] >= 0 && dp[j] >= 0) {
        reta = dp[i];
        retb = dp[j];
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &g[i][j]);
  int lhs = -1;
  int rhs = 1000000001;
  while(lhs < rhs) {
    int mid = (lhs+rhs+1)/2;
    if(valid(mid)) lhs = mid;
    else rhs = mid-1;
  }
  printf("%d %d\n", reta+1, retb+1);
}