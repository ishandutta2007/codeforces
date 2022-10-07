#include <iostream>
using namespace std;
long long n,k,a[100001],b[100001],x,y,r1,r2,r=1000000007,ans=1,p,q,i,j,m[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
main()
{
cin>>n>>k;
for (i=0;i<n/k;i++)
cin>>a[i];
for (i=0;i<n/k;i++)
cin>>b[i];
for (i=0;i<n/k;i++)
{
x=(m[k]-1)/a[i]+1;
p=b[i]*m[k-1];
r1=p%a[i];
if (r1>0)
p+=a[i]-r1;
q=(b[i]+1)*m[k-1]-1;
r2=q%a[i];
q-=r2;
y=(q-p)/a[i]+1;
ans*=(x-y);
ans%=r;
}
cout<<ans<<endl;
}