#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstring>
#define eps 1e-12
using namespace std;
int main()
{
long long a[100005];
long long d,i,j,n,k,m,z;
cin>>n;
if (n%4==2||n%4==3) {cout<<-1;return 0;}
if (n%4==0)
{
for (i=1;i<=n/2;i++)
if (i%2==1) a[i]=i+1; else a[i]=n+2-i;
for (i=n/2+1;i<=n;i++)
if (i%2==1) a[i]=n-i; else a[i]=i-1;
} else
{
for (i=1;i<=n/2;i++)
if (i%2==1) a[i]=i+1; else a[i]=n+2-i;
a[n/2+1]=n/2+1;
for (i=n/2+2;i<=n;i++)
if (i%2==0) a[i]=n-i; else a[i]=i-1;
}
for (i=1;i<=n;i++) cout<<a[i]<<" ";
return 0;
}