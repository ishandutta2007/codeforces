#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
ll min1,i,m,n,k,k1,o,a[100011];
cin>>n;
for (i=0;i<n;i++) scanf("%I64d",&a[i]);
k=0;k1=0;i=0;
while (i<n)
{
if (a[i]>k1) {k1=a[i];i++;} else
while (a[i]<=k1&&i<n) {k+=max((ll)0,a[i-1]-a[i]);i++;}
}
cout<<k<<endl;
return 0;
}