#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
long long a[320000],x1,x2,s1,s,i,j,n,m;
cin>>n;
for (i=1;i<=n;i++)
scanf("%I64d",&a[i]);
sort(a+1,a+n+1);
for (i=1;i<=n;i++)
s1+=abs(a[i]-i);
cout<<s1;
return 0;
}