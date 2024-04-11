#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll x,a[200000],n1,i1,c[2000500],d,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
bool z;
string s4,s1,s2[15],s[300];
char s3;
map <char,ll> f;
map <string, ll> g;
int main()
{
cin>>n>>m;
for (i=1;i<=n;i++) cin>>a[i];
k=0;
while (m--)
{
cin>>k1;
if (k1==1)
{
cin>>k2>>k3;
a[k2]=k3-k;
} else
if (k1==3)
{
cin>>k2;
cout<<a[k2]+k<<endl;
} else
{
cin>>k2;
k+=k2;
}
}
return 0;
}