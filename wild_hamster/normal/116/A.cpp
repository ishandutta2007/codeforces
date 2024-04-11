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
ll max1=-1;
ll t=0;
cin>>n;
while (n--)
{
cin>>k1>>k2;
t+=k2-k1;
if (t>max1) max1=t;
}
cout<<max1<<endl;
return 0;
}