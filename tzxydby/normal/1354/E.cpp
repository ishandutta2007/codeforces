#include<bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int>e[N];
int b[N],c[N],n,m,k,s[N][2],n1,n2,n3,s1,s2,dp[N][N],co[N],ans[N],p[N][N];
void dfs(int u)
{
	for(auto v:e[u])
	{
		if(!b[v])
		{
			b[v]=k;
			c[v]=c[u]^1;
			dfs(v);
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&n3);
	s1=n1+n3,s2=n2;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			k++;
			b[i]=k;
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		s[b[i]][c[i]]++;
		for(auto j:e[i])
		{
			if(c[i]==c[j])
			{
				puts("NO");
				exit(0);
			}
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(dp[i-1][j-s[i][0]])
			{
				dp[i][j]=1;
				p[i][j]=0;
			}
			if(dp[i-1][j-s[i][1]])
			{
				dp[i][j]=1;
				p[i][j]=1;
			}
		}
	}
	if(!dp[k][s1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int q=s1;
	for(int i=k;i>=1;i--)
	{
		co[i]=p[i][q];
		q-=s[i][p[i][q]];
	}
	for(int i=1;i<=n;i++)
		ans[i]=1+(co[b[i]]^c[i]);
	for(int i=1;i<=n&&n3;i++)
	{
		if(ans[i]==1)
		{
			ans[i]=3;
			n3--;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d",ans[i]);
	return 0;
}