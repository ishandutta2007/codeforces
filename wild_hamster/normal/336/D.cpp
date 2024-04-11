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
ll x,n,k,m,t,r,y,i;
ll c[4],a[200500],rev[200500],rez[3];
ll binpow(ll x, ll k)
{
if (k==0) return 1; 
if (k%2==1) return (binpow(x,k-1)*x)%tr; 
ll t=binpow(x,k/2);
return (t*t)%tr;
}
ll C(ll n,ll k)
{
return (((a[n]*rev[k])%tr)*rev[n-k])%tr;
}
int main()
{
cin>>n>>m>>x;
if (m==0)
{
c[0]=n%2;
c[1]=(n+1)%2;
cout<<c[x]<<endl;
return 0;
}
a[0]=1;rev[0]=1;
a[1]=1;
for (i=2;i<200400;i++)
a[i]=(a[i-1]*i)%tr;
for (i=1;i<200400;i++)
rev[i]=binpow(a[i],tr-2)%tr;
rez[0]=0;rez[1]=0;
for (i=0;i<n+m+1;i++)
{
if (n-i<0) break;
if (m-1<0) break;
if (i==n+m-1) rez[(i+1)%2]+=C(n+m-i-1,m-1);
else rez[i%2]+=C(n+m-i-1,m-1);
}
cout<<rez[x]%tr<<endl;
return 0;
}