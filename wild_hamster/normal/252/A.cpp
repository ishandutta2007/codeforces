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
ll k,max1,k1,k2,i,n,m,c[105][105],dp[105][10105],a[105],b[105],j,azaza,min1,z1,x,z2,yw,xb,yb,z;
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
int main()
{
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<n;i++)
{
k=0;
for (j=i;j<n;j++)
{
k=k^a[j];
if (k>max1) max1=k;
}
}
cout<<max1<<endl;
return 0;
}