#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#define t 1000000007
using namespace std;
int g,r,i,j,n,m,k,b[9];
int main()
{
int a[8]={2,9,64,0,0,0,0,0};
long long s;
cin>>n>>m;
int i1,i2,i3,i4;
s=1;
for (i=m+1;i<=n;i++)
s=(s*(n-m))%t;
for (i=1;i<=m-1;i++)
s=(s*m)%t;
cout<<s<<endl;
return 0;
}