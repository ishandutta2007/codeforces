#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cmath>
#define eps 1e+12
#define maxn 20000000
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
map <ll,ll> f1,f2;
ll a[400000],s,k1,k2,x1,x2,x3,x4,b[400000],m,i,j,n;
ll t[1600000];
vector <ll> f,g[2];
void build (ll v, ll tl, ll tr) {
if (tl == tr)
t[v] = b[tl];
else {
ll tm = (tl + tr) / 2;
build (v*2, tl, tm);
build (v*2+1, tm+1, tr);
t[v] = t[v*2] + t[v*2+1];
}
}

ll sum (ll v, ll tl, ll tr, ll l, ll r) {
if (l > r)
return 0;
if (l == tl && r == tr)
return t[v];
ll tm = (tl + tr) / 2;
return sum (v*2, tl, tm, l, min(r,tm))
+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
int main()
{

cin>>n;
for (i=1;i<=n;i++) 
{
cin>>a[i];
b[i]=max(a[i],(ll)0);
if (f1[a[i]]==0) f1[a[i]]=i; 
}
build(1,1,n);
for (i=n;i>=1;i--)
if (f2[a[i]]==0) f2[a[i]]=i;
map <ll,ll>::iterator t;
ll max1=-(ll)1e+10;
for (t=f1.begin();t!=f1.end();t++)
if (f1[(*t).first]<f2[(*t).first])
{
g[0].push_back(f1[(*t).first]);
g[1].push_back(f2[(*t).first]);
}
max1=-(ll)1e+10;
for (i=0;i<g[0].size();i++)
{
if (sum(1,1,n,g[0][i]+1,g[1][i]-1)+2*a[g[0][i]]>max1)
{max1=sum(1,1,n,g[0][i]+1,g[1][i]-1)+2*a[g[0][i]];k1=g[0][i];k2=g[1][i];}
}
s=2*a[k1];
for (i=1;i<=n;i++)
{
if (i>k1&&i<k2&&a[i]>0)
s+=a[i];
if ((a[i]<0&&i!=k1&&i!=k2)||(i<k1)||(i>k2))
f.push_back(i);
}
cout<<s<<" "<<f.size()<<endl;
for (i=0;i<f.size();i++)
cout<<f[i]<<" ";
return 0;
}