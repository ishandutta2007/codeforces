#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
char s[max_n],t[max_n];
const int inf=1e9;
int cnt[26],dp[max_n][max_n];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d%s%s",&n,s+1,t+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i)
			++cnt[s[i]-'a'],--cnt[t[i]-'a'];
		bool flag=true;
		for(int i=0;i<26;++i)
		{
			if(cnt[i])
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			puts("-1");
			continue;
		}
		int S=(n&1)^1;
		for(int i=1;i<=n;++i)
			dp[S][i]=inf;
		dp[S][n+1]=0;
		for(int i=n+1;i>=2;--i)
		{
			if(i<=n)
				++cnt[t[i]-'a'];
			int x=i&1,y=x^1,now=inf;
			char val=t[i-1];
			int cnt_s=0,cnt_t=cnt[val-'a'];
			for(int j=n;j>=1;--j)
			{
				now=min(now,dp[x][j+1]);
				if(s[j]==val)
				{
					dp[y][j]=now;
					++cnt_s;
				}
				else
					dp[y][j]=inf;
				if(cnt_s>cnt_t)
					dp[y][j]=min(dp[y][j],dp[x][j]+1);
			}
			dp[y][n+1]=inf;
		}
		assert(dp[1][1]<inf);
		printf("%d\n",dp[1][1]); 
	}
	return 0;
}