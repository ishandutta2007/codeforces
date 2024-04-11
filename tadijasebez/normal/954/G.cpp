#include <stdio.h>
#define ll long long
const int N=500050;
ll k;
ll a[N],b[N],dp[N];
int n,r;
bool Check(ll t)
{
	ll sum=0,used=0;
	int i;
	for(i=1;i<=n;i++) b[i]=0;
	for(i=1;i<=n;i++)
	{
		sum-=b[i];
		sum+=a[i];
		if(sum<t)
		{
			used+=t-sum;
			if(i+r*2+1<=n) b[i+r*2+1]+=t-sum;
			sum+=t-sum;
		}
		sum-=a[i];
		if(used>k) return 0;
	}
	//printf("t:%lld used:%lld k:%lld\n",t,used,k);
	return used<=k;
}
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int i;
	scanf("%i %i %lld",&n,&r,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),dp[i]=dp[i-1]+a[i];
	for(i=1;i<=n;i++) a[i]=dp[min(n,i+r)]-dp[max(0,i-r-1)];
	ll top=4e18,bot=0,mid,ans;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) bot=mid+1,ans=mid;
		else top=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}