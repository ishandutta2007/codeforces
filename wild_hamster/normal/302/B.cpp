#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>
#include <stdio.h>
typedef long long ll;
using namespace std;
ll k,d,n,s,a[101000][2],b[100100],k1,k2,k3,k4,m,j,i;
int main()
{

cin>>n>>m;
for (i=0;i<n;i++)
scanf("%I64d%I64d",&a[i][0],&a[i][1]);
b[0]=a[0][0]*a[0][1];
for (i=1;i<n;i++)
b[i]=b[i-1]+a[i][0]*a[i][1];
for (i=0;i<m;i++)
{
scanf("%I64d",&k1);
k2=upper_bound(b,b+n,k1-1)-b+1;
printf("%I64d\n",k2);
}
return 0;
}