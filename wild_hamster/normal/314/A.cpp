#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 95542721
//map <ll,ll> a,b,c;
vector <ll> f;
ll a[2000500],n1,i1,c[2000500],b[2000500],d,s,t,m,i,j,k,rez,n,k1,k2,k3,k4;
int main()
{
cin>>n>>k;
for (i=1;i<=n;i++) cin>>a[i];
s=0;k1=0;n1=n;
for (i=1;i<=n;i++)
{
d=s-((i-k1)-1)*(n1-i+k1)*a[i];
if (d<k) {cout<<i<<endl;k1++;n1--;} else
s+=a[i]*(i-k1-1);
}
return 0;
}