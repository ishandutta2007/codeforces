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
ll t,s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[10000];
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
vector <ll> f;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
ll C(ll n, ll m)
{
ll a[65],b[65],i;
if (n<m) return 0;
for (i=1;i<=n;i++) a[i]=i;
for (i=1;i<=m;i++) b[i]=i;
for (j=1;j<=n-m;j++) b[m+j]=j;
for (i=1;i<=n;i++)
{
for (j=1;j<=n;j++)
{
ll k=gcd(a[j],b[i]); 
a[j]/=k;b[i]/=k;
}
}
ll s=1;
for (i=1;i<=n;i++) s*=a[i];
return s;
}
int main()
{
cin>>n>>m>>t;
rez=0;
for (i=4;i<=min(t-1,n);i++)
rez+=(C(n,i))*(C(m,t-i));
cout<<rez<<endl;
return 0;
}