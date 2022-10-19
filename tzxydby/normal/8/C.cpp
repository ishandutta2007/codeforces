#include<bits/stdc++.h>
using namespace std;
const int N=25;
int dp[1<<N],path[1<<N],x[N],y[N],dis[N][N],n;
vector<int>ans;
void up(int s,int t,int v)
{
	if(dp[s]>v)
	{
		dp[s]=v;
		path[s]=s^t;
	}
}
int dfs(int s)
{
	if(dp[s]!=1e9)
		return dp[s];
	if(s==(1<<n)-1)
		return dp[s]=0;
	int p;
	for(int i=0;i<n;i++)
	{
		if(!(s&(1<<i)))
		{
			p=i;
			break;
		}
	}
	int t=s|(1<<p);
	up(s,t,dfs(t)+2*dis[p][n]);
	for(int i=p+1;i<n;i++)
	{
		if(s&(1<<i))
			continue;
		int k=t|(1<<i);
		up(s,k,dfs(k)+dis[n][p]+dis[p][i]+dis[i][n]);
	}
	return dp[s];
}
void p(int s)
{
	if(s==(1<<n)-1)
		return;
	ans.push_back(0);
	for(int i=0;i<n;i++)
		if(path[s]&(1<<i))
			ans.push_back(i+1);
	p(s|path[s]);
}
int main()
{
	int a,b;
	scanf("%d%d%d",&a,&b,&n);
	x[n]=a,y[n]=b;
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	for(int i=0;i<(1<<n);i++)
		dp[i]=1e9;
	printf("%d\n",dfs(0));
	p(0);
	ans.push_back(0);
	for(auto i:ans)
		printf("%d ",i);
	puts("");
	return 0;
}