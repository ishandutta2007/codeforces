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
ll j1,k1,k2,i,j,m,n,max1,b[10000],a[10000],c[10000],d[10000],rez1,rez2,y,p,x1,y1,x2,y2,x3,x,y3;
ll gcd(ll x, ll y)
{
if (y==0) return x;
else return gcd(y,x%y);
}
int main()
{
string s;
cin>>n>>m;
x1=0;x2=0;
for (i=0;i<n;i++)
{
cin>>s;
cin>>x;
if (s[0]=='A') a[x1++]=x; else c[x2++]=x+1;
}
for (i=0;i<m;i++) cin>>b[i];
sort(a,a+x1);
sort(b,b+m);
sort(c,c+x2);
for (i=0;i<m;i++) d[i]=b[i];
rez1=0;rez2=0;
j=0;
i=0;
if (x2!=0)
while (i<m)
{
while (b[i]<c[j]&&i<m-1) i++;
if (b[i]>=c[j]) {b[i]=0;i++;j++;} 
if (i==m-1) i++;
if (j==x2) break;
}
sort(b,b+m);
if (j==x2)
{
j1=0;
i=0;
if (x1!=0)
while (i<m)
{
while (b[i]<a[j1]&&i<m-1) i++;
if (b[i]>=a[j1]) {b[i]-=a[j1];i++;j1++;} 
if (i==m-1) i++;
if (j1==x1) break;
}
if (j1==x1)
for (i=0;i<m;i++) rez1+=b[i];
}
for (i=m-1;(i>=0&&x1-m+i>=0);i--) if (d[i]>=a[m-1-i]) rez2+=d[i]-a[m-1-i];
//cout<<rez1<<" "<<rez2<<endl;
cout<<max(rez1,rez2)<<endl;
return 0;
}