#include<bits/stdc++.h>
using namespace std;
int n,m,g1,g2,s1,s2;
const int max_n=50+5;
int dis[max_n][max_n];
const int inf=1e9;
int Min[max_n],Max[max_n];
bool G[max_n],S[max_n],B[max_n];
long long dp[max_n][max_n][max_n];
typedef pair<int,int> P;
inline long long solve(P gold,P bronze,P silver_down,P silver_up)
{
	for(int i=1;i<=n;++i)
	{
		G[i]=S[i]=B[i]=false;
		for(int j=1;j<=n;++j)
		{
			if(i!=j)
			{
				if(P(dis[i][j],i)<=gold)
					G[i]=true;
				if(P(dis[i][j],i)>=bronze)
					B[i]=true;
				if(P(dis[i][j],i)<silver_up&&P(dis[i][j],i)>silver_down)
					S[i]=true;
			}
		}
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			for(int k=0;j+k<=i;++k)
			{
				dp[i][j][k]=0;
				if(G[i]&&j)
					dp[i][j][k]+=dp[i-1][j-1][k];
				if(S[i]&&k)
					dp[i][j][k]+=dp[i-1][j][k-1];
				if(B[i])
					dp[i][j][k]+=dp[i-1][j][k];
			}
	long long res=0;
	for(int i=g1;i<=g2;++i)
		for(int j=s1;j<=s2;++j)
			res+=dp[n][i][j];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=i!=j?inf:0;
	for(int i=1;i<=m;++i)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		dis[u][v]=dis[v][u]=c;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i)
	{
		Min[i]=inf,Max[i]=-inf;
		for(int j=1;j<=n;++j)
		{
//			fprintf(stderr,"%d%c",dis[i][j],j<n?' ':'\n');
			if(j!=i)
			{
				Min[i]=min(Min[i],dis[i][j]);
				Max[i]=max(Max[i],dis[i][j]);
			}
		}
	}
	scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
	long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans+=solve(P(Min[i],i),P(Max[j],j),P(Min[i],i),P(Max[j],j))-solve(P(Min[i],i-1),P(Max[j],j),P(Min[i],i),P(Max[j],j))-solve(P(Min[i],i),P(Max[j],j+1),P(Min[i],i),P(Max[j],j))+solve(P(Min[i],i-1),P(Max[j],j+1),P(Min[i],i),P(Max[j],j));
	printf("%lld\n",ans);
	return 0;
}