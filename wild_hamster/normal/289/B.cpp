#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
long long ost,s,sa,sa1,rez,max1,n,m,d,i,j,j1,x,k,k1,k2,z,a[40000];
cin>>n>>m>>d;
for (i=1;i<=m*n;i++)
cin>>a[i];
a[0]=a[1];
ost=a[1]%d;
z=0;s=0;
for (i=1;i<=m*n;i++)
{
if (a[i]%d!=ost) z=1;
s+=a[i];
}
if (z==1) {cout<<-1<<endl;return 0;}
sort(a+1,a+m*n+1);
max1=(long long)1e+17;
if ((m*n)%2==0)
for (j1=0;j1<=1;j1++)
{
sa1=a[(m*n)/2+j1];
rez=0;
for (i=1;i<=m*n;i++)
rez=rez+((long long)abs(a[i]-sa1))/d;
if (rez<max1) max1=rez;
} else
for (j1=1;j1<=1;j1++)
{
sa1=a[(m*n)/2+j1];
rez=0;
for (i=1;i<=m*n;i++)
rez=rez+((long long)abs(a[i]-sa1))/d;
if (rez<max1) max1=rez;
}
cout<<max1<<endl;
return 0;
}