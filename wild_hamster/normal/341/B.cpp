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
#define tr 1000000009
ll rez,z,x,y1,y2,m,n,i,j,k1,k,a[100500],b[100500],c[100500];
vector <ll> f;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
ll Abs(ll n)
{
if (n<0) return -n; else return n;
}
ll azaza(ll n)
{

if (f.size()==n)
{
k=0;
for (int i=0;i<f.size();i++)
{
rez+=Abs(a[f[i]]-k);
k=a[f[i]];
}
}
for (int i=1;i<=n;i++)
if (b[i]==0) {f.push_back(i);b[i]=1;azaza(n);b[i]=0;f.pop_back();}
}
int main()
{
rez=0;
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
ll d[100500];
d[0] = -(ll)1e+17;
for (i=1; i<=n+1; i++) d[i] = (ll)1e+17;
for (i=0; i<n; i++) {
ll j = ll (upper_bound (d, d+n+2, a[i]) - d);
if (d[j-1] < a[i] && a[i] < d[j]) d[j] = a[i];
}
k1=0;
for (i=0;i<=n;i++)
if (d[i]<(ll)1e+17) k=i;
/*
for (i=0;i<n;i++) a[i]=n+1-a[i];
d[0] = -(ll)1e+17;
for (i=1; i<=n+1; i++) d[i] = (ll)1e+17;
for (i=0; i<n; i++) {
ll j = ll (upper_bound (d, d+n+2, a[i]) - d);
if (d[j-1] < a[i] && a[i] < d[j]) d[j] = a[i];
}
for (i=0;i<=n;i++)
if (d[i]<(ll)1e+17) k1=i;*/
cout<<max(k,k1)<<endl;
return 0;
}