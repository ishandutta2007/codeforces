#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
double f[2][222][444];
#define F(a,x,y) (f[(a)&1][x][210+((y)>200?200:(y))])
double p[222];
int a[222];
int n,l,ok;
int main()
{
scanf("%d %d %d",&n,&l,&ok);
for(int i=0;i<n;i++)
{
int t=0;
scanf("%d",&t);
p[i]=t/100.0;
}
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
F(0,0,ok)=1.0;
for(int i=0;i<n;i++)
{
memset(f[(i+1)&1],0,sizeof(f[0]));
for(int j=0;j<=n;j++)
{
for(int k=-200;k<=200;k++)
{
F(i+1,j,k)+=(1.0-p[i])*F(i,j,k);
if(a[i]!=-1)
{
if(j<n)
F(i+1,j+1,k+a[i])+=p[i]*F(i,j,k);
else
F(i+1,j,k)+=p[i]*F(i,j,k);
}
else
{
if(j<n)
F(i+1,j+1,k-1)+=p[i]*F(i,j,k);
else
F(i+1,j,k)+=p[i]*F(i,j,k);
}
}
}
}
double ans=0.0;
for(int j=l;j<=n;j++)
for(int i=0;i<=200;i++)
ans+=F(n,j,i);
printf("%.10lf\n",ans);
return 0;
}