#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
ll y,j1,j2,rez,p[5],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[150][150];
vector <ll> f;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
int main()
{
cin>>n>>k;
for (i=0;i<120;i++)
for (j=0;j<120;j++)
a[i][j]=0;
for (i=0;i<n;i++)
{
cin>>j1;
ll max1=15000000;
for (x=1;x<=k;x++)
{
ll s=0;
for (y=1;y<=j1;y++)
s+=a[x][y];
y=j1;
while (y<=k)
{
if (s<=0)
{
ll tmp=0;
for (j=y-j1+1;j<=y;j++)
tmp+=Abs(k+1-2*j)+Abs(k+1-2*x);
//cout<<tmp<<endl;
if (tmp<max1) {max1=tmp;p[1]=x;p[2]=y-j1+1;p[3]=y;}
}
y++;
s+=a[x][y]-a[x][y-j1];
}
}
if (max1==15000000) cout<<-1<<endl; else cout<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
for (j=p[2];j<=p[3];j++)
a[p[1]][j]=1;
}
return 0;
}