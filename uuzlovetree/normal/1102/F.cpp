#include<bits/stdc++.h>
#define maxs 70005
#define maxn 18
#define maxm 10005
using namespace std;
const int inf = (int)(1e9)+7;
int n,m;
int a[maxn][maxm];
int w[maxn][maxn],nxtw[maxn][maxn];
int dp[maxn][maxs];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			w[i][j]=nxtw[i][j]=inf;
			for(int k=1;k<=m;++k)w[i][j]=min(w[i][j],abs(a[i][k]-a[j][k]));
			for(int k=1;k<m;++k)nxtw[i][j]=min(nxtw[i][j],abs(a[i][k]-a[j][k+1]));
		}
	int ans=0;
	for(int st=0;st<n;++st)
	{
		memset(dp,0,sizeof(dp));
		dp[st][1<<st]=inf;
		for(int S=0;S<(1<<n);++S)
		{
			for(int i=0;i<n;++i)if(S&(1<<i))
			{
				for(int j=0;j<n;++j)if(!(S&(1<<j)))dp[j][S|(1<<j)]=max(dp[j][S|(1<<j)],min(dp[i][S],w[i+1][j+1]));
			}
		}
		for(int i=0;i<n;++i)ans=max(ans,min(dp[i][(1<<n)-1],nxtw[i+1][st+1]));
	}
	printf("%d\n",ans);
}