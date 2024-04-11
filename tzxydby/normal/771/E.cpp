#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n;
long long a[3][N],p[3][N];
map<long long,int>dp[N],mp;
int dfs(int x,int y)
{
	if(x<0||y<0)
		return -1;
	if(x==0&&y==0)
		return 0;
	if(dp[x].count(y))
		return dp[x][y];
	return dp[x][y]=max(0,1+max((p[1][x]<p[2][y]?dfs(x,p[2][y]):dfs(p[1][x],y)),dfs(p[0][min(x,y)],p[0][min(x,y)])));
}
void sol()
{
	scanf("%d",&n);
	for(int j=1;j<=2;j++)
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[j][i]);
	for(int i=0;i<=n+1;i++)
		dp[i].clear();
	for(int i=1;i<=n;i++)
		a[0][i]=a[1][i]+a[2][i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			a[j][i]+=a[j][i-1];
	p[0][0]=p[1][0]=p[2][0]=-1;
	for(int j=0;j<=2;j++)
	{
		mp.clear();
		mp[0]=1;
		for(int i=1;i<=n;i++)
		{
			p[j][i]=mp[a[j][i]]-1;
			p[j][i]=max(p[j][i],p[j][i-1]);
			mp[a[j][i]]=i+1;
		}
	}
	printf("%d\n",dfs(n,n));
}
int main()
{
	int t=1;
	while(t--)
		sol();		
	return 0;
}