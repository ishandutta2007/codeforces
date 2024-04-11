#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define h second
long long n,i,j,ans=2,maxx,x[200000],h[200000];
main()
{
cin>>n;
for (i=1;i<=n;i++)
cin>>x[i]>>h[i];
maxx=x[1];
for (i=2;i<n;i++)
{
if (x[i]-h[i]>maxx)
{
ans++;
//cout<<i<<" 1"<<endl;
maxx=x[i];
continue;
}
if (x[i]+h[i]<x[i+1])
{
maxx=x[i]+h[i];
//cout<<i<<" 2"<<endl;
ans++;
continue;
}
maxx=x[i];
}
if (ans>n)
ans=n;
cout<<ans<<endl;
}