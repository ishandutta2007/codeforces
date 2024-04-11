#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000000
//map <ll,ll> a,b,c;
ll f[2000],x,a[2000],n1,i1,c[2000500],b[2000500],d,s,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
string s1;
int main()
{
cin>>n>>m;
f[0]=1;f[1]=1;
for (i=2;i<1000;i++)
f[i]=(f[i-1]+f[i-2])%tr;
for (i=1;i<=n;i++) cin>>a[i];
for (i=0;i<m;i++)
{
cin>>k1>>k2>>k3;
if (k1==1) a[k2]=k3; else
{
ll sum=0;
for (j=k2;j<=k3;j++)
sum=(sum+f[j-k2]*a[j])%tr;
cout<<sum<<endl;
}
}
return 0;
}