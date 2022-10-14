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
ll x,y,a[200000],n1,i1,c[2000500],d,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
int main()
{
cin>>x>>y>>m;
k=0;
if (m<=x||m<=y) {cout<<0;return 0;}
if (x<=0&&y<=0&&m>x&&m>y) {cout<<-1;return 0;}
if (x>y) swap(x,y);
if (x<=0&&y>0) {k=(-x)/y;x+=k*y;}
while (x<m&&y<m)
{
if (x<y) x+=y; else y+=x;
k++;
}
cout<<k<<endl;
return 0;
}