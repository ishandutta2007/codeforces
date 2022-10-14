#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#define tr 1000000007
#define eps 1e+12
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll a[50000],b[50000],m,k,k1,k2,k3,n,rez,i,j,i1,i2,i3,i4,i5,i6;
ll gcd(ll x, ll y)
{
if (y==0) return x;
else return gcd(y,x%y);
}
int main()
{
cin>>n;
ll sum=0,max1=-1;
for (i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
for (i=0;i<n;i++)
for (j=i;j<n;j++)
{
ll s=0;
for (k=i;k<=j;k++)
s+=a[k];
if (j-i+1-2*s>max1) max1=j-i+1-2*s;
}
cout<<sum+max1<<endl;
return 0;
}