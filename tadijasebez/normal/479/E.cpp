#include <stdio.h>
const int N=5050;
const int mod=1e9+7;
int dp[N],sum[N],n;
/*int Get(int l, int r, int x)
{
	l--;
	if(l<0) l=0;
	if(r>n) r=n;
	int ret=sum[r]-sum[l];
	if(ret<0) ret+=mod;
	ret-=dp[x];
	if(ret<0) ret+=mod;
	return ret;
}*/
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void Set(int l, int r, int add)
{
	l=max(l,1);
	r=min(r,n);
	sum[l]+=add;
	if(sum[l]>=mod) sum[l]-=mod;
	sum[r+1]-=add;
	if(sum[r+1]<0) sum[r+1]+=mod;
}
int dist(int x, int y){ return x>y?x-y:y-x;}
int main()
{
	int a,b,k,i;
	scanf("%i %i %i %i",&n,&a,&b,&k);
	dp[a]=1;
	while(k--)
	{
		for(i=1;i<=n;i++) sum[i]=0;
		for(i=1;i<=n;i++)
		{
			int d=dist(i,b);
			//dp[i]=Get(i-d+1,i+d-1,i);
			Set(i-d+1,i+d-1,dp[i]);
			//printf("i:%i %i %i\n",i,dp[i],d);
		}
		for(i=1;i<=n;i++)
		{
			sum[i]+=sum[i-1];
			if(sum[i]>=mod) sum[i]-=mod;
			dp[i]=sum[i]-dp[i];
			if(dp[i]<0) dp[i]+=mod;
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=dp[i];
		if(ans>=mod) ans-=mod;
	}
	printf("%i\n",ans);
	return 0;
}