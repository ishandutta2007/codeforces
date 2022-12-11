#include<bits/stdc++.h>
using namespace std;
const int max_n=18+5;
int v[max_n],deg[max_n],S_out[max_n];
bool Map[max_n][max_n];
int que[max_n],sz,a[max_n];
const int max_U=1<<18|5;
int dp[2][max_n][max_U],pre[max_n][max_n][max_U]; // about 575 MiB
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		--x,--y;
		v[x]+=w,v[y]-=w;
		Map[x][y]=true;
		++deg[y];
		S_out[x]|=1<<y;
	}
	for(int i=0;i<n;++i)
	{
		if(!deg[i])
			que[++sz]=i;
	}
	for(int t=1;t<=sz;++t)
	{
		int x=que[t];
		for(int y=0;y<n;++y)
		{
			if(Map[x][y]&&!--deg[y])
				que[++sz]=y;
		}
	}
	assert(sz==n);
//	for(int i=1;i<=sz;++i)
//		fprintf(stderr,"%d%c",que[i]," \n"[i==sz]);
	int U=(1<<n)-1; 
	for(int i=0;i<2;++i)
		for(int j=1;j<=n;++j)
			for(int S=0;S<=U;++S)
				dp[i][j][S]=1e9;
	int sta=0;
	for(int i=0;i<n;++i)
	{
		if(!S_out[i])
			sta|=1<<i;
	}
	for(int S=sta;S;S=(S-1)&sta)
		dp[0][n][S]=0;
	for(int i=1;i<n;++i)
	{
		int b=i&1,a=b^1;
		for(int S=0;S<=U;++S)
		{
			dp[b][0][S]=dp[a][n][S];
			pre[i][0][S]=-1;
		}
		for(int j=1;j<=n;++j)
		{
			for(int S=0;S<=U;++S)
			{
				dp[b][j][S]=dp[b][j-1][S];
				pre[i][j][S]=-1;
			}
			int x=que[j];
			for(int S=0;S<=U;++S)
			{
				if(~S>>x&1&&(S_out[x]&S)==S_out[x])
				{
					int T=S|(1<<x);
					if(dp[b][j][T]>dp[b][j-1][S]+v[x]*i)
					{
						dp[b][j][T]=dp[b][j-1][S]+v[x]*i;
						pre[i][j][T]=x;
					}
				}
			}
		}
	}
	int now_i=n-1,now_j=n,now_S=U;
	while(now_i>0)
	{
		int x=pre[now_i][now_j][now_S];
		if(~x)
		{
			a[x]=now_i;
			--now_j;
			now_S^=1<<x;
		}
		else
		{
			if(now_j>0)
				--now_j;
			else
				--now_i,now_j=n;
		}
	}
//	for(int i=0;i<n;++i)
//		for(int S=0;S<=U;++S)
//			fprintf(stderr,"i=%d S=%d dp[i][S]=%d pre[i][S]=%d\n",i,S,dp[i][S],pre[i][S]);
	for(int i=0;i<n;++i)
		printf("%d%c",a[i]," \n"[i+1==n]);
	return 0;
}