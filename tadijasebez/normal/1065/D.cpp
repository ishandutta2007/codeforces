#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=1e9;
int a[N][N];
pair<int,int> dist[3][N][3][N];
pair<int,int> dp[N][3];
pair<int,int> operator + (pair<int,int> a, pair<int,int> b){ return {a.first+b.first,a.second+b.second};}
pair<int,int> min(pair<int,int> a, pair<int,int> b){ return a>b?b:a;}
int main()
{
	int n,i,j,x,y;
	scanf("%i",&n);
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%i",&a[i][j]);
	for(int l=0;l<3;l++) for(int r=0;r<3;r++) for(i=1;i<=n*n;i++) for(j=1;j<=n*n;j++) dist[l][i][r][j]={inf,inf};
	for(i=1;i<=n;i++) for(j=1;j<=n;j++)
	{
		dist[0][a[i][j]][0][a[i][j]]={0,0};
		dist[0][a[i][j]][1][a[i][j]]={1,1};
		dist[0][a[i][j]][2][a[i][j]]={1,1};
		dist[1][a[i][j]][0][a[i][j]]={1,1};
		dist[1][a[i][j]][2][a[i][j]]={1,1};
		dist[2][a[i][j]][1][a[i][j]]={1,1};
		dist[2][a[i][j]][0][a[i][j]]={1,1};
		vector<int> A={2,-2},B={1,-1};
		for(x:A) for(y:B)
		{
			if(i+x<=n && i+x>0 && j+y<=n && j+y>0) dist[0][a[i][j]][0][a[i+x][j+y]]=dist[0][a[i+x][j+y]][0][a[i][j]]={1,0};
			if(i+y<=n && i+y>0 && j+x<=n && j+x>0) dist[0][a[i][j]][0][a[i+y][j+x]]=dist[0][a[i+y][j+x]][0][a[i][j]]={1,0};
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++)
	{
		dist[1][a[i][j]][1][a[i][j]]={0,0};
		dist[2][a[i][j]][2][a[i][j]]={0,0};
		for(int x=1;x<=n;x++)
		{
			if(i+x<=n && j+x<=n) dist[1][a[i][j]][1][a[i+x][j+x]]=dist[1][a[i+x][j+x]][1][a[i][j]]={1,0};
			if(i+x<=n && j-x>=1) dist[1][a[i][j]][1][a[i+x][j-x]]=dist[1][a[i+x][j-x]][1][a[i][j]]={1,0};
			if(i-x>=1 && j+x<=n) dist[1][a[i][j]][1][a[i-x][j+x]]=dist[1][a[i-x][j+x]][1][a[i][j]]={1,0};
			if(i-x>=1 && j-x>=1) dist[1][a[i][j]][1][a[i-x][j-x]]=dist[1][a[i-x][j-x]][1][a[i][j]]={1,0};
			if(i+x<=n) dist[2][a[i][j]][2][a[i+x][j]]=dist[2][a[i+x][j]][2][a[i][j]]={1,0};
			if(i-x>=1) dist[2][a[i][j]][2][a[i-x][j]]=dist[2][a[i-x][j]][2][a[i][j]]={1,0};
			if(j+x<=n) dist[2][a[i][j]][2][a[i][j+x]]=dist[2][a[i][j+x]][2][a[i][j]]={1,0};
			if(j-x>=1) dist[2][a[i][j]][2][a[i][j-x]]=dist[2][a[i][j-x]][2][a[i][j]]={1,0};
		}
	}
	for(int k=0;k<3;k++)
	{
		for(int u=1;u<=n*n;u++)
		{
			for(int l=0;l<3;l++)
			{
				for(i=1;i<=n*n;i++)
				{
					for(int r=0;r<3;r++)
					{
						for(j=1;j<=n*n;j++)
						{
							dist[l][i][r][j]=min(dist[l][i][r][j],dist[l][i][k][u]+dist[k][u][r][j]);
						}
					}
				}
			}
		}
	}
	for(i=1;i<=n*n;i++) for(j=0;j<3;j++) dp[i][j]={inf,inf};
	dp[1][0]=dp[1][1]=dp[1][2]={0,0};
	for(i=1;i<n*n;i++)
	{
		for(j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				dp[i+1][k]=min(dp[i+1][k],dp[i][j]+dist[j][i][k][i+1]);
			}
		}
	}
	pair<int,int> ans;ans=dp[n*n][0];
	for(i=1;i<3;i++) ans=min(ans,dp[n*n][i]);
	printf("%i %i\n",ans.first,ans.second);
	return 0;
}