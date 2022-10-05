#include <bits/stdc++.h>
const int Maxn=17,Maxm=10005;
using namespace std;
int dp[1<<Maxn][Maxn][Maxn],n,m,val[Maxn][Maxm],diff[Maxn][Maxn],mini[Maxn][Maxn],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&val[i][j]);
	memset(mini,0x3f,sizeof(mini));
	memset(diff,0x3f,sizeof(diff));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
			{
				if(i!=j)
					mini[i][j]=min(mini[i][j],abs(val[i][k]-val[j][k]));
				diff[i][j]=min(diff[i][j],k==m?0x3f3f3f3f:abs(val[i][k+1]-val[j][k]));
			}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<(1<<n);i++)
		for(int k=1;k<=n;k++)
			if((i>>k-1)&1)
				for(int j=1;j<=n;j++)
					if(((1<<(j-1))&i)&&j!=k)
						for(int q=1;q<=n;q++)
							if((1<<(q-1)&i)&&(q!=k||i==(1<<(j-1))+(1<<(k-1))||i==(1<<(j-1)))&&(q!=j||i==(1<<(q-1))))
								dp[i][j][q]=max(dp[i][j][q]==0x3f3f3f3f?0:dp[i][j][q],min(dp[i-(1<<(j-1))][k][q],mini[j][k]));
	if(n==1) 
	{
		printf("%d",diff[1][1]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				ans=max(ans,min(diff[i][j],dp[(1<<n)-1][i][j]));
	printf("%d",ans);
	return 0;
}