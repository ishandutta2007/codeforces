#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll quan[200005];
int a[200005];
int b[200005];
ll sum[200005];
ll kasumi(ll a,ll b)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b/=2;
	}
	return ans%mod;
}
int main()
{
	int n,m;
	cin>>n>>m;
	quan[1]=1;
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",quan[i]);
//	}
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[n-i+1]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%1d",&b[m-i+1]);
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("**%lld \n",a[i]);
//	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]*kasumi(2,i-1);
	}
	for(int i=1;i<=m;i++)
	{
		sum[i]=(sum[i-1]+sum[i])%mod;
	}
//	for(int i=1;i<=m;i++)
//	{
//		printf("%lld ",sum[i]);
//	}
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		if(b[i]==1)
		{
			ans=(ans+sum[i])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}