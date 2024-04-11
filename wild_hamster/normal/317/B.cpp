#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll x1,y1,x,y,a[2000][2000],b[2000][2000],n1,i1,c[2000500],d,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
vector <ll> f[2];
int main()
{
cin>>n>>t;
for (i=0;i<2000;i++)
for (j=0;j<2000;j++)
a[i][j]=0;
a[1000][1000]=n;
x1=1000;y1=1000;k=0;
for (i=2;i<7500;i++)
for (j=0;j<=130;j++)
for (k=0;k<=130;k++)
if ((j+k)%2==i%2)
{
x=j+x1-65;y=k+y1-65;
if (a[x][y]>=4)
{
ll d=a[x][y]/4;
a[x][y-1]+=d;
a[x][y+1]+=d;
a[x-1][y]+=d;
a[x+1][y]+=d;
a[x][y]%=4;
}
}
for (i=0;i<t;i++)
{
cin>>k1>>k2;
if (k1<-100||k1>100||k2<-100||k2>100) cout<<0<<endl; else
cout<<a[k1+1000][k2+1000]<<endl;
}
return 0;
}