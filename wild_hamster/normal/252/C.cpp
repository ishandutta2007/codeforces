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
ll k,d,k1,k2,k3,i,n,a[100005],b[100005],j,azaza,min1,z1,x,z2,yw,xb,yb,z;
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
for (int i=0;i<n-1;i++)
if (a[i]!=a[i+1]) return 0;
return 1;
}
int main()
{
cin>>n>>d;
k=0;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<n;i++)
{
k1=upper_bound(a,a+n,a[i]+d)-a-i-1;
k+=(k1*(k1-1))/2;
//cout<<k1<<endl;
}
cout<<k<<endl;
return 0;
}