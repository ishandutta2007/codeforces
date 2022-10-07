#include <bits/stdc++.h>
using namespace std;
long long n,k,a[200000],i,j,ans,s,x=1;
main()
{
cin>>n>>k;
for (i=1;i<=n;i++)
cin>>a[i];
for (i=1;i<=k;i++)
ans+=a[i];
s=ans;
for (i=2;i<=n-k+1;i++)
{
s=s-a[i-1]+a[k+i-1];
if (s<ans)
{
ans=s;
x=i;
}
}
cout<<x<<endl;
}