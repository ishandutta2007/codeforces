#include <stdio.h>
const int N=5050;
int a[N],dp[N][N],p[10],q[100050];
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c, int d){ return max(max(a,b),max(c,d));}
int main()
{
int n,i,j,sol=0;
scanf("%i",&n);
for(i=1;i<=n;i++) scanf("%i",&a[i]);
for(i=0;i<=n;i++)
{
for(j=0;j<10;j++) p[j]=0;
for(j=1;j<=n;j++) q[a[j]]=0;
for(j=1;j<i;j++)
{
p[a[j]%7]=max(p[a[j]%7],dp[i][j]);
q[a[j]]=max(q[a[j]],dp[i][j]);
}
for(j=i+1;j<=n;j++)
{
dp[i][j]=max(p[a[j]%7],q[a[j]+1],q[a[j]-1],dp[i][0])+1;
dp[j][i]=dp[i][j];
p[a[j]%7]=max(p[a[j]%7],dp[i][j]);
q[a[j]]=max(q[a[j]],dp[i][j]);
sol=max(sol,dp[i][j]);
}
}
printf("%i\n",sol);
return 0;
}