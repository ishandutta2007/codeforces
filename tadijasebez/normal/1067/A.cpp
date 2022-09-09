#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int K=201;
const int mod=998244353;
int dp[N][K][2],a[N],pre[K][2];
int add(int x, int y){ x+=y;if(x>=mod) x-=mod;return x;}
int sub(int x, int y){ x-=y;if(x<0) x+=mod;return x;}
int Get(int t, int l, int r){ return sub(pre[r][t],pre[l-1][t]);}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	if(a[1]==-1) for(i=1;i<K;i++) dp[1][i][0]=1;
	else dp[1][a[1]][0]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<K;j++) pre[j][0]=add(pre[j-1][0],dp[i-1][j][0]);
		for(j=1;j<K;j++) pre[j][1]=add(pre[j-1][1],dp[i-1][j][1]);
		if(a[i]==-1)
		{
			for(j=1;j<K;j++)
			{
				dp[i][j][0]=add(Get(0,1,j-1),Get(1,1,j-1));
				dp[i][j][1]=add(Get(0,j,j),Get(1,j,K-1));
			}
		}
		else
		{
			dp[i][a[i]][0]=add(Get(0,1,a[i]-1),Get(1,1,a[i]-1));
			dp[i][a[i]][1]=add(Get(0,a[i],a[i]),Get(1,a[i],K-1));
		}
	}
	int ans=0;
	for(i=1;i<K;i++) ans=add(ans,dp[n][i][1]);
	printf("%i\n",ans);
	return 0;
}