#include<bits/stdc++.h>
using namespace std;
const int prime[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
const int max_S=1<<17|5;
vector<int> val[max_S],id;
inline void init()
{
	for(int i=1;i<=59;++i)
	{
		int S=0;
		for(int j=0;j<17;++j)
		{
			if(i%prime[j]==0)
				S|=1<<j;
		}
		val[S].push_back(i);
	}
	for(int S=0;S<(1<<17);++S)
	{
		if(!val[S].empty())
			id.push_back(S);
	}
//	fprintf(stderr,"id.size()=%d\n",int(id.size()));
}
const int max_n=100+5;
int a[max_n],b[max_n],dp[max_n][max_S],pre[max_n][max_S],cur[max_n][max_S],cost[max_S],best[max_S];
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int U=(1<<17)-1;
	for(int i=0;i<=n;++i)
		for(int S=0;S<=U;++S)
			dp[i][S]=1e9;
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int S:id)
		{
			cost[S]=1e9;
			vector<int>::iterator it=lower_bound(val[S].begin(),val[S].end(),a[i]);
			if(it!=val[S].end())
			{
				cost[S]=*it-a[i];
				best[S]=*it;
			}
			if(it!=val[S].begin())
			{
				if(a[i]-*(--it)<cost[S])
				{
					cost[S]=a[i]-*it;
					best[S]=*it;
				}
			}
		}
		for(int S=0;S<=U;++S)
		{
			int v=dp[i-1][S];
			if(v<1e9)
			{
				for(int T:id)
				{
					if(!(S&T)&&v+cost[T]<dp[i][S|T])
					{
						dp[i][S|T]=v+cost[T];
						pre[i][S|T]=S;
						cur[i][S|T]=best[T];
					}
				}
			}
		}
	}
	int ans=1e9,now=-1;
	for(int S=0;S<=U;++S)
	{
		if(dp[n][S]<ans)
		{
			ans=dp[n][S];
			now=S;
		}
	}
//	fprintf(stderr,"ans=%d\n",ans);
	assert(~now);
	for(int i=n;i>=1;--i)
	{
		b[i]=cur[i][now];
		now=pre[i][now];
	}
	for(int i=1;i<=n;++i)
		printf("%d%c",b[i]," \n"[i==n]);
	return 0;
}
/*
30
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/