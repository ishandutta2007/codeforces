#include<bits/stdc++.h>
using namespace std;
int tot;
const int max_tot=9e6+5;
int son[max_tot][2],res[max_tot][2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		vector<int> dp(n);
		for(int i=0;i<n;++i)
		{
			int v=a[i]^i,cur=0,mx=0;
			for(int j=29;j>=0;--j)
			{
				int x=v>>j&1;
				if(son[cur][x^1])
				{
					int goal=(a[i]>>j&1)^1;
					mx=max(mx,res[son[cur][x^1]][goal]);
				}
				if(!son[cur][x])
					break;
				cur=son[cur][x];
			}
			dp[i]=mx+1;
			cur=0;
			for(int j=29;j>=0;--j)
			{
				int x=v>>j&1;
				if(!son[cur][x])
					son[cur][x]=++tot;
				cur=son[cur][x];
				res[cur][i>>j&1]=max(res[cur][i>>j&1],dp[i]);
			}
		}
		int ans=0;
		for(int i=0;i<n;++i)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
		for(int i=0;i<=tot;++i)
			son[i][0]=son[i][1]=res[i][0]=res[i][1]=0;
		tot=0;
	}
	return 0;
}