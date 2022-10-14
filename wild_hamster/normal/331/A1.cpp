#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cmath>
#define tr 1000000007
#define eps 1e+12
#define maxn 20000000
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
map <ll,ll> f1,f2;
ll a[200000],s,k1,k2,b[200000][2],m,i,j,n;
vector <ll> f;
int main()
{

cin>>n;
for (i=1;i<=n;i++) 
{
cin>>a[i];
if (f1[a[i]]==0) f1[a[i]]=i; 
}
for (i=n;i>=1;i--)
if (f2[a[i]]==0) f2[a[i]]=i;
map <ll,ll>::iterator t;
ll max1=-(ll)1e+10;
for (t=f1.begin();t!=f1.end();t++)
if (f1[(*t).first]<f2[(*t).first])
{
s=0;
for (j=f1[(*t).first]+1;j<f2[(*t).first];j++)
{          
if (a[j]>=0) s+=a[j];
}
s+=2*a[f1[(*t).first]];
if (s>max1) {k1=f1[(*t).first];k2=f2[(*t).first];max1=s;}
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