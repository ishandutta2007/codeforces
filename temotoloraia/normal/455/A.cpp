#include <iostream>
using namespace std;
long long n,a[110001],dp[110001],i,j,p,k;
int main()
{
cin>>n;
for (i=1;i<=n;i++)
{
cin>>k;
a[k]+=k;
}
dp[1]=a[1];
dp[2]=max(a[1],a[2]);
for (i=3;i<=110000;i++)
dp[i]=max(dp[i-1],dp[i-2]+a[i]);
cout<<dp[110000]<<endl;
return 0;
}