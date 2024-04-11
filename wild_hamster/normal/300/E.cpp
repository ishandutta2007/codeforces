#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define tr 1000000007
using namespace std;
long long dfs(long long k1, long long k2)
{
long long k3=0;
long long k4=k2;
while (k2<=k1)
{
k3+=k1/k2;
k2*=k4;
}
return k3;
}
long long s,a[10000010],b[10000010],l,r,max1,mid,z,n,i,j,k,k1,k2,k3;
int main()
{
cin>>n;
s=0;
max1=0;
for (i=0;i<10000005;i++) a[i]=0; 
for (i=0;i<n;i++)
{
scanf("%d",&k);
a[k]++;
s+=k;
max1=max(max1,k);
}
for (i=2;i<10000005;i++)
if (b[i]==0)
for (j=i;j<10000005;j+=i)
b[j]=i;
for (j=10000003;j>=2;j--)
a[j]+=a[j+1];
for (j=10000004;j>=2;j--)
if (b[j]!=j)
{
a[b[j]]+=a[j];
a[j/b[j]]+=a[j];
}
l=1;r=s;
while (l<r)
{
z=1;
mid=(l+r)>>1;
for (i=2;i<=max1;i++)
if (b[i]==i)
{
if (dfs(mid,i)<a[i]) {z=0;break;}
}
if (z) r=mid;
else l=mid+1;
}
cout<<r<<endl;
//system("pause");
return 0;
}