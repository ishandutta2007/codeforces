#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define maxn 2005
using namespace std;
int a,n,m;
int c[maxn];
int dp[maxn][maxn];
vector<pii> has[maxn];
int w[maxn];
int main()
{
	scanf("%d%d%d",&a,&n,&m);
	for(int i=1;i<=n;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		c[r]++;c[l]--;
	}
	for(int i=a;i>=0;--i)c[i]+=c[i+1];
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		has[x].push_back(mp(i,y));
		w[i]=y;
	}
	w[0]=0;
	memset(dp,127/2,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<a;++i)
	{
		for(int j=0;j<=m;++j)if(dp[i][j]<(int)1e9)
		{
			if(c[i+1])
			{
				if(j)dp[i+1][j]=min(dp[i+1][j],dp[i][j]+w[j]);
			}
			else dp[i+1][j]=min(dp[i+1][j],dp[i][j]+w[j]);
			if(!c[i+1])dp[i+1][0]=min(dp[i+1][0],dp[i][j]+w[0]);
			for(int k=0;k<has[i].size();++k)
			{
				int x=has[i][k].first;
				dp[i+1][x]=min(dp[i+1][x],dp[i][j]+w[x]);
			}
		}
	}
	int ans=(int)1e9;
	for(int j=0;j<=m;++j)ans=min(ans,dp[a][j]);
	if(ans==(int)1e9)puts("-1");
	else printf("%d\n",ans);
	return 0;
}