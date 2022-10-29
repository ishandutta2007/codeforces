#include <cstdio>
#include <cstdlib>
int a[501][501],sum[501][501],f[2][501][501],n,m,now,ans;
inline int call(int x,int y,int k) {
    return sum[x+k-1][y+k-1]-sum[x+k-1][y-1]-sum[x-1][y+k-1]+sum[x-1][y-1];
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
      for (int j=1;j<=m;++j) { 
        scanf("%d",&a[i][j]);f[0][i][j]=a[i][j];
        sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
      }
    now=1;
    ans=-10000000;
    for (int k=3;k<=n&&k<=m;k+=2,now^=1) 
      for (int i=1;i<=n-k+1;++i)
        for (int j=1;j<=m-k+1;++j) 
          if ((f[now][i][j]=call(i,j,k)-f[now^1][i+1][j+1]-a[i+1][j])>ans)
            ans=f[now][i][j];
    printf("%d",ans);
}