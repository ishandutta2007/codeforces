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
ll s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[1000];
vector <ll> f;
int main()
{
cin>>s>>k;
a[1]=1;x=1;
for (i=2;i<=k+1;i++)
{
if (x>(ll)2e+9) {z=1;break;}
a[i]=x;
x+=a[i];
}
i=k+1;
if (!z)
while (a[i]<=(ll)2e+9)
{
for (j=i-k+1;j<=i;j++)
a[i+1]+=a[j];
i++;
}
//for (i=0;i<100;i++) cout<<a[i]<<" ";
f.push_back(0);
for (i=100;i>=0;i--) if (a[i]>0) {k=i; break;}
while (s>0)
{
//break;
j=upper_bound(a,a+k,s)-a-1;
s-=a[j];
f.push_back(a[j]);
}
cout<<f.size()<<endl;
for (i=0;i<f.size();i++) cout<<f[i]<<" ";
return 0;
}