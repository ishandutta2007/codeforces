#include<bits/stdc++.h>
using namespace std;
long long n,k,d0,d1,d2,s,x,y,r,c,a[500003],i,j,minn,maxx;
main()
{
cin>>n>>k;
d1=k;
d2=k;
for (i=1;i<=n;i++){
//cin>>a[i];
scanf("%lld",&a[i]);
s+=a[i];
}
sort(a+1,a+n+1);
x=s/n;
y=(s+n-1)/n;
r=s%n;
c=n-r;
for (i=1;i<=n;i++)
if (i<=c)
d0+=abs(a[i]-x);
else
d0+=abs(a[i]-y);
d0=(d0+1)/2;
if (k>=d0){if (r==0)cout<<0<<endl;else cout<<1<<endl;return 0;}
for (i=2;i<=n;i++){
if ((a[i]-a[i-1])*(i-1)<=d1)d1-=(a[i]-a[i-1])*(i-1);
else {minn=a[i-1]+d1/(i-1);break;}
}
for (i=n-1;i>=1;i--){
if ((a[i+1]-a[i])*(n-i)<=d2)d2-=(a[i+1]-a[i])*(n-i);
else {maxx=a[i+1]-d2/(n-i);break;}
}
cout<<maxx-minn<<endl;
}