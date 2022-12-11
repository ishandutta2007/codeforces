#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
int a[maxn],c[9];
int dp[maxn][260];
int f[9][maxn][130];
void init()
{
	for(int x=1;x<=8;++x)
	{
		for(int l=0;l<=n;++l)
		{
			int cnt=0;
			f[x][l][0]=l;
			for(int r=l+1;r<=n;++r)
			{
				if(a[r]==x)
				{
					++cnt;
					f[x][l][cnt]=r;
				}
			}
			for(int i=cnt+1;i<=m;++i)f[x][l][i]=n+1;
		}
	}
}
int ans=0;
bool check(int L)
{
	memset(dp,128,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int S=0;S<(1<<8);++S)if(dp[i][S]>=0)
		{
			dp[i+1][S]=max(dp[i+1][S],dp[i][S]);
			for(int k=1;k<=8;++k)if(!(S&(1<<(k-1))))
			{
				int sta=S|(1<<(k-1));
				dp[f[k][i][L]][sta]=max(dp[f[k][i][L]][sta],dp[i][S]+L);
				dp[f[k][i][L+1]][sta]=max(dp[f[k][i][L+1]][sta],dp[i][S]+L+1);
			}
		}
	}
	ans=max(ans,dp[n][(1<<8)-1]);
	if(dp[n][(1<<8)-1]>=0)return 1;
	else return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[a[i]]++;
	m=n;
	for(int i=1;i<=8;++i)m=min(m,c[i]);
	m++;
	init();
	int l=0,r=m-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}