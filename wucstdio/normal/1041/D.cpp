#include<cstdio>
#include<algorithm>
#include<cstring>
//
#define ll long long
using namespace std;
ll n,h,from[200005],to[200005],sum[200005],down[200005],ans;
bool judge(ll x)
{
	int now=1;
	for(int i=1;i<=n;i++)
	{
		while(now<=n&&from[now]-from[i]<=x)now++;
		now--;
		if(h+sum[now]-sum[i-1]>=x)return 1;
	}
	return 0;
}
int main()
{
	scanf("%I64d%I64d",&n,&h);
	for(int i=1;i<=n;i++)
	  scanf("%I64d%I64d",&from[i],&to[i]);
	if(n==0)
	{
		printf("%I64d\n",h);
		return 0;
	}
	for(int i=1;i<=n;i++)
	  sum[i]=sum[i-1]+to[i]-from[i];
	for(int i=1;i<n;i++)
	  down[i]=down[i-1]+from[i+1]-to[i];
	down[n]=2147483647;
	int now=1;
	for(int i=0;i<n;i++)
	{
		while(down[now]-down[i]<h)now++;
		ans=max(ans,sum[now]-sum[i]+h);
	}
	printf("%I64d\n",ans);
	return 0;
}