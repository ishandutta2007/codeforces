#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
int k1,k2,k3,t,s,y,j1,j2,rez,z,a[100500],t1,t2,x,y1,y2,m,n,i,j,k;
int main()
{
cin>>n;
for (i=0;i<n;i++)
{
cin>>k;
a[k]++;
}
z=0;
a[6]-=a[3];a[1]-=a[3];k1=a[3];a[3]=0;
for (i=1;i<=7;i++) if (a[i]<0) z=1;
a[2]-=a[4];a[1]-=a[4];k2=a[4];a[4]=0;
for (i=1;i<=7;i++) if (a[i]<0) z=1;
a[2]-=a[6];a[1]-=a[6];k3=a[6];a[6]=0;
for (i=1;i<=7;i++) if (a[i]!=0) z=1;
if (z==1) cout<<-1;
else
{
for (i=0;i<k2;i++) cout<<"1 2 4 ";
for (i=0;i<k3;i++) cout<<"1 2 6 ";
for (i=0;i<k1;i++) cout<<"1 3 6 ";
}
return 0;
}