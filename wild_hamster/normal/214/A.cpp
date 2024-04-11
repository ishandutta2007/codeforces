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
    cin>>n>>m;
k1=0;
for (i=0;i<=1000;i++)
for (j=0;j<=1000;j++)
if (i+j*j==n&&i*i+j==m) k1++;
cout<<k1<<endl;
return 0;
}