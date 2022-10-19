#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,d[N][N],g1,g2,s1,s2,f[N],w[N],g[N],s[N],b[N];
long long dp[N][N][N],ans;
long long sol(int gl,int bl,int su,int sd)
{
	for(int i=1;i<=n;i++)
		g[i]=s[i]=b[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			if(d[i][j]<=gl)
				g[i]=1;
			if(d[i][j]>=bl)
				b[i]=1;
			if(d[i][j]>su&&d[i][j]<sd)
				s[i]=1;
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;j+k<=i;k++)
				dp[i][j][k]=dp[i-1][j-1][k]*g[i]+dp[i-1][j][k-1]*s[i]+dp[i-1][j][k]*b[i];
	long long r=0;
	for(int i=g1;i<=g2;i++)
		for(int j=s1;j<=s2;j++)
			r+=dp[n][i][j];
	return r;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=1e9;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u][v]=d[v][u]=w;
	}
	scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(d[i][j]<1e9)
				d[i][j]=d[i][j]*n+i;
	for(int i=1;i<=n;i++)
	{
		f[i]=1e9,w[i]=-1e9;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			f[i]=min(f[i],d[i][j]);
			w[i]=max(w[i],d[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=sol(f[i],w[j],f[i],w[j])-sol(f[i]-1,w[j],f[i],w[j])-sol(f[i],w[j]+1,f[i],w[j])+sol(f[i]-1,w[j]+1,f[i],w[j]);
	printf("%I64d\n",ans);
	return 0;
}