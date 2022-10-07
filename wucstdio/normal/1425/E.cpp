#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k;
ll a[100005],b[100005],s[100005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	if(k>=2)
	{
		ll minn=1e9;
		for(int i=1;i<n;i++)minn=min(minn,b[i]);
		ll ans=max(s[n]-minn,0ll);
		ans=max(ans,a[n]-b[n]);
		printf("%lld\n",ans);
		return 0;
	}
	if(k==1)
	{
		ll ans=0,minn=1e9;
		for(int i=1;i<n;i++)
		{
			minn=min(minn,b[i]);
			ans=max(ans,s[n]-minn-b[i+1]);
		}
		ans=max(ans,s[n-1]-minn);
		for(int i=2;i<=n;i++)ans=max(ans,s[n]-s[i-1]-b[i]);
		minn=1e9;
		for(int i=2;i<n;i++)minn=min(minn,a[i]);
		ans=max(ans,s[n]-minn-b[1]);
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,s[n]-s[i-1]-b[i]);
	printf("%lld\n",ans);
	return 0;
}