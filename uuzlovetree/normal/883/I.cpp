#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,k;
int a[maxn];
int dp[maxn];
bool check(int x)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	priority_queue< pair<int,int> > q;
	for(int i=1;i<=n;++i)
	{
		if(i>=k)q.push(make_pair(dp[i-k],i-k));
		while(!q.empty())
		{
			int L=q.top().second;
			if(a[i]-a[L+1]>x)q.pop();
			else break;
		}
		if(q.empty())dp[i]=0;
		else dp[i]=dp[q.top().second];
	}
	return dp[n];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=0,r=1000000000,ans=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}