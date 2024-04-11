#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
map <ll,ll> f5;
ll a[2001][2001],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
int main()
{
cin>>n>>m;
for (i=0;i<n;i++)
for (j=0;j<m;j++)
scanf("%d", &a[i][j]);
ll rez=-(ll)1e+9;
for (k1=0;k1<n;k1++)
for (k2=k1+1;k2<n;k2++)
{
ll k3=-1,k4=-1;
for (i=0;i<m;i++)
if (a[k1][i] > rez && a[k2][i] > rez)
{
ll b=min(a[k1][i],a[k2][i]);
if (b>k3)
{k4=k3;k3=b;} else
if (b>k4)
k4=b;
}
rez=max(rez,k4);
}
cout<<rez<<endl;
return 0;
}