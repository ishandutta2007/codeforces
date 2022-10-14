#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll k1,k2,k3,i,n,a[100005],b[100005],j,azaza,min1,z1,x,z2,yw,xb,yb,z;
ll binpow(ll a, ll m)
{
if (m==0) return 1;
if (m%2==1) return (a*binpow(a,m-1))%tr; else
return (binpow((a*a)%tr,m/2))%tr;
} 
ll ob(ll k)
{
return binpow(k,tr-2);
}
ll sorted()
{
int k1,k2;
k1=1;k2=1;
for (int i=0;i<n-1;i++)
if (a[i]>a[i+1]) k1=0;
for (int i=0;i<n-1;i++)
if (a[i]<a[i+1]) k2=0;
if (!k1&&!k2) return 0;
return 1;
}
int main()
{
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
if (n==1||n==2) {cout<<-1;return 0;}
k1=1;k2=1;k3=1;
for (i=0;i<n-1;i++)
{
if (a[i]!=a[i+1]) k1=0;
if (a[i]>a[i+1]) k2=0;
if (a[i]<a[i+1]) k3=0;
}
if (k1==1) {cout<<-1;return 0;} else
if (k2==1)
{
for (i=0;i<n-1;i++)
if (a[i]<a[i+1]) {cout<<i+1<<" "<<i+2;return 0;}
} else
if (k3==1)
{
for (i=0;i<n-1;i++)
if (a[i]>a[i+1]) {cout<<i+1<<" "<<i+2;return 0;}
} else
{
for (i=0;i<n;i++)
if (a[1]!=a[i])
{
swap(a[1],a[i]);
if (!sorted()) {cout<<2<<" "<<i+1;return 0;} else
swap(a[1],a[i]);
}
for (i=0;i<n-1;i++)
if (a[i]!=a[n-2])
{
swap(a[n-2],a[i]);
if (!sorted()) {cout<<n-1<<" "<<i+1;return 0;} else
swap(a[n-2],a[i]);
}
}
cout<<-1;
return 0;
}