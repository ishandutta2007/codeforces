#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int INF=0x3f3f3f3f;
int n,m,x,y,sum;
int vis[N],dp[N];
vector<int>e[N],v;
map<int,int>mp;
void dfs(int x)
{
	vis[x]=1;
	for(int i=0;i<e[x].size();i++)
		if(!vis[e[x][i]])
			dfs(e[x][i]);
	sum++;
}
bool lucky(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)
			return false;
		x/=10;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			sum=0;
			dfs(i);
			mp[sum]++;
		}
	}
	for(int i=1;i<=n;i++)
		dp[i]=INF;
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		int c=itr->first,k=itr->second;
		while(k>0)
		{
			for(int i=n;i>=c*((k+1)/2);i--)
				dp[i]=min(dp[i],dp[i-c*((k+1)/2)]+(k+1)/2);
			k/=2;
		}
	}
	int ans=INF;
	for(int i=1;i<=n;i++)
		if(lucky(i))
			ans=min(ans,dp[i]);
	if(ans==INF)
		printf("-1\n");
	else
		printf("%d\n",ans-1);
	return 0;
}