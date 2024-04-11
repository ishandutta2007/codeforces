#include <bits/stdc++.h>
using namespace std;
long long n,r1,r2,x11,y11,x21,y21,x[2001],y[2001],i,j,maxr;
pair<long long,long long>P[2003];
main()
{
cin>>n>>x11>>y11>>x21>>y21;
for (i=1;i<=n;i++)
{
cin>>x[i]>>y[i];
P[i].first=(x11-x[i])*(x11-x[i])+(y11-y[i])*(y11-y[i]);
P[i].second=(x21-x[i])*(x21-x[i])+(y21-y[i])*(y21-y[i]);
}
sort(P+1,P+1+n);
maxr=P[n].first;
for (i=0;i<n;i++)
{
r1=P[i].first;
r2=P[i+1].second;
for (j=i+2;j<=n;j++)
if (P[j].second>r2)
r2=P[j].second;
if (r1+r2<maxr)
maxr=r1+r2;
}
cout<<maxr<<endl;
}