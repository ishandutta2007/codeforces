#include <cstdio>
int i,j,n,a[1000][1000];
int main(){
scanf("%d",&n);n--;
for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=1+(i+j)%n;
for(i=0;i<n;a[i][i]=0,i++)a[i][n]=a[n][i]=a[i][i];
for(i=0;i<=n;i++,puts(""))for(j=0;j<=n;j++)printf("%d ",a[i][j]);}