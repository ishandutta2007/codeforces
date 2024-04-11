#include<bits/stdc++.h>
using namespace std;
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
const int N=4005;
int n,m,a[N][N],s[N][N],dp[N][N],p[N][N];
int val(int u,int v){return (s[v][v]-s[u-1][v]-s[v][u-1]+s[u-1][u-1]);}
int main()
{
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=rd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];
	for(int i=1;i<=n;i++)
		dp[0][i]=1e9;
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=1;j--)
		{
			dp[i][j]=1e9;
			for(int k=p[i-1][j];k<=(j==n?n:p[i][j+1]);k++)
				if(dp[i-1][k]+val(k+1,j)<dp[i][j])
					dp[i][j]=dp[i-1][k]+val(k+1,j),p[i][j]=k;
		}
	}
	printf("%d\n",dp[m][n]/2);
	return 0;
}