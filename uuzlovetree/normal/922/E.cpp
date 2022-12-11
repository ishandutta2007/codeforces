#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define maxc 10005
using namespace std;
int n,W,B,X;
int c[maxn],w[maxn];
bool vis[maxn][maxc];
ll dp[maxn][maxc];
int main()
{
	scanf("%d%d%d%d",&n,&W,&B,&X);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	dp[0][0]=W;vis[0][0]=1;
	int ans=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=10000;++j)if(vis[i][j])
		{
			for(int k=0;k<=c[i+1];++k)
			{
				ll res=min(dp[i][j]+X,1ll*W+1ll*j*B)-1ll*k*w[i+1];
				if(res>=0)
				{
					dp[i+1][j+k]=max(dp[i+1][j+k],res);
					vis[i+1][j+k]=1;
					ans=max(ans,j+k);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}