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
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
ll a[2001][2001],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
int main()
{
for (i=1;i<=5;i++)
for (j=1;j<=5;j++)
{
cin>>k1;
if (k1) cout<<Abs(3-i)+Abs(3-j)<<endl;
}
return 0;
}