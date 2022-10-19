#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,k,p,dp[N][N][N],b[N][N];
int dfs(int i,int j,int c)
{
	if(j>m&&c)
		return 0;
	if((i+1)/2<c)
		return 0;
	int &f=dp[i][j][c];
	if(f!=-1)
		return f;
	f=0;
	if(i==0)
		return f=(!c);
	int w=c;
	if(j==m)
		w--;
	for(int s=0;s<i;s++)
	{
		for(int l=0;l<=w;l++)
		{
			int v=1ll*dfs(s,j+1,l)*dfs(i-s-1,j+1,w-l)%p*b[i-1][s]%p;
			f=(f+v)%p;
		}
	}
	return f;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0;i<=n;i++)
	{
		b[i][0]=1;
		for(int j=1;j<=i;j++)
			b[i][j]=(b[i-1][j]+b[i-1][j-1])%p;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(n,1,k)%p);
	return 0;
}