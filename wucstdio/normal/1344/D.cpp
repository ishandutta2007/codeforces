#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll k,a[100005],b1[100005],b2[100005];
bool check(ll v)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=a[i];
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(mid*(a[i]-mid*mid)-((mid-1)*(a[i]-(mid-1)*(mid-1)))>=v)l=mid+1;
			else r=mid-1;
		}
		sum+=r;
	}
	return sum>k;
}
void solve(ll v,ll*b)
{
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=a[i];
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(mid*(a[i]-mid*mid)-((mid-1)*(a[i]-(mid-1)*(mid-1)))>=v)l=mid+1;
			else r=mid-1;
		}
		b[i]=r;
	}
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll l=-3e18,r=1e9;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	solve(l,b1);
	solve(r,b2);
	ll sum1=0;
	for(int i=1;i<=n;i++)sum1+=b1[i];
	for(int i=1;i<=n;i++)
	{
		if(sum1==k)printf("%lld ",b1[i]);
		else
		{
			ll v=min(b2[i],b1[i]+k-sum1);
			printf("%lld ",v);
			sum1+=v-b1[i];
		}
	}
	printf("\n");
	return 0;
}