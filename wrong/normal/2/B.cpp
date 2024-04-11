#include<cstdio>
#include<algorithm>

using namespace std;

int m[1024][1024], dp[1024][1024][2], left[1024][1024][2];

int main()
{
  int n, p[2] = {2, 5}, zx=0, zy;
  scanf("%d", &n);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
      scanf("%d", &m[i][j]);
  for(int i=2; i<=n; ++i)
    dp[i][0][0]=dp[i][0][1]=dp[0][i][0]=dp[0][i][1]=1<<29;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(!m[i][j]) zx=j, zy=i;
      for(int k=0; k<2; ++k) {
    dp[i][j][k] = min(dp[i-1][j][k], dp[i][j-1][k]) + !m[i][j];
    left[i][j][k] = dp[i-1][j][k] > dp[i][j-1][k];
    for(int x=m[i][j]; x&&x%p[k]==0; x/=p[k]) dp[i][j][k]++;
      }
    }
  }
  int k = dp[n][n][0]>dp[n][n][1] ? 1 : 0, way[2000];
  if(zx>0 && dp[n][n][k]>0) {
    puts("1");
    for(int i=1; i<zx; ++i) putchar('R');
    for(int i=1; i<zy; ++i) putchar('D');
    for(int i=zx; i<n; ++i) putchar('R');
    for(int i=zy; i<n; ++i) putchar('D');
    puts("");
    return 0;
  }
  printf("%d\n", dp[n][n][k]);
  for(int i=2*n-3, x=n, y=n; i>=0; --i, left[y][x][k]?--x:--y)
    way[i] = left[y][x][k];
  for(int i=0; i<2*n-2; ++i) putchar("DR"[way[i]]);
  puts("");
  return 0;
}