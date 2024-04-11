#include <bits/stdc++.h>
using namespace std;
long long n,w[200001],h[200001],i,j,x,y,d1,d2;
main()
{
cin>>n;
for (i=1;i<=n;i++)
{
cin>>w[i]>>h[i];
x+=w[i];
if (h[i]>d1)
d1=h[i];
if (d1>d2)
swap(d1,d2);
}
for (i=1;i<=n;i++)
{
y=d2;
if (y==h[i])
y=d1;
cout<<y*(x-w[i])<<" ";
}
}