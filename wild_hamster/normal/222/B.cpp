#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,i,k2,j,a[1005][1005],s[1005],r[1005],n,m,azaza,z1,z2,yw,xb,yb,z;
int main()
{
    char t;
cin>>m>>n>>k;
for (i=1;i<=m;i++)
for (j=1;j<=n;j++)
scanf("%I64d",&a[i][j]);
for (i=1;i<=1000;i++) {s[i]=i;r[i]=i;}
while (k--)
{
cin>>t;
scanf("%I64d%I64d",&k1,&k2);
if (t=='c') swap(s[k1],s[k2]); else
if (t=='r') swap(r[k1],r[k2]); else
printf("%I64d\n",a[r[k1]][s[k2]]);
}
return 0;
}