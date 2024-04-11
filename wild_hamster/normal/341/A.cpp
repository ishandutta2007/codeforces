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
ll rez,z,x,y1,y2,m,n,i,j,k,a[100500],b[100500],c[100500];
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
cin>>n;a[0]=0;m=0;
for (i=1;i<=n;i++) cin>>c[i];
sort(c+1,c+n+1);
for (i=1;i<=n;i++) {k=c[i];a[i]=k-m;m+=a[i];}
i=1;k=n;m=n;z=1;
while (b[i]==0)
{
b[i]=1;
rez+=a[i]*k;
m--;
k+=m;
i+=m*z;
z*=-1;
}
m=gcd(rez,n);
cout<<rez/m<<" "<<n/m<<endl;
return 0;
}