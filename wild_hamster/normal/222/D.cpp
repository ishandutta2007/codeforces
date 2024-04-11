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
ll k,k1,i,x,k2,j,a[100005],b[100005],r[1005],n,m,azaza,z1,z2,yw,xb,yb,z;
int main()
{
    char t;
cin>>n>>x;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<n;i++) cin>>b[i];
sort(a,a+n);
sort(b,b+n);
k1=0;k2=n-1;k=0;
while (k1<n)
{
while (a[k1]+b[k2]<x&&k1<n) k1++;
if (k1>=n) break;
k++;k1++;k2--;
}
cout<<1<<" "<<k;
return 0;
}