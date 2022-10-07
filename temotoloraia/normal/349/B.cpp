#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long v,a[10],dp[3000000],i,j,x,y,z;
main()
{
cin>>v;
for (i=1;i<=9;i++)
cin>>a[i];
y=a[9];
z=9;
for (i=8;i>=1;i--)
if (a[i]<y)
{
y=a[i];
z=i;
}
//cout<<accumulate(a+1,a+10,0)<<endl;
x=v/y;
//cout<<x<<endl;
for (i=1;i<=x;i++)
dp[i]=z;
v%=y;
//cout<<v<<endl;
for (i=1;v>0 && i<=x;i++)
{
for (j=9;j>z;j--)
if (a[j]-y<=v)
break;
dp[i]=j;
v=v-a[j]+y;
}
if (x==0)
{
cout<<-1<<endl;
return 0;
}
for (i=1;i<=x;i++)
cout<<dp[i];
}