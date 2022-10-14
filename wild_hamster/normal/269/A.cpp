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
ll max1,x1,y1,x,y,a[2000][2000],b[2000][2000],n1,i1,c[2000500],d,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
vector <ll> f[2];
int main()
{
cin>>n;
max1=-1;
while (n--)
{
cin>>k1>>k2;
if (k2==1) k1++;
while (k2!=1) {k2=(k2+3)/4;k1++;}
if (k1>max1) max1=k1;
}
cout<<max1<<endl;
return 0;
}