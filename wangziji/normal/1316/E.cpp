#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
#pragma GCC optimize 2
using namespace std;
int dp[150][10];// 
struct node
{
	int w,id,rk;
}a[100005];
inline bool cmp(node x,node y)
{
	return x.w>y.w;
}
inline bool cmp2(node x,node y)
{
	return x.id<y.id;
}
int d[100005],w[100005][10];
signed main(int argc, char** argv) {
	int n,p,k;
	cin >> n >> p >> k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].w);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			scanf("%lld",&w[i][j]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) a[i].rk=i,d[i]=a[i].w;
	int ans=0;
	for(int i=1;i<=k;i++) ans+=d[i];
	for(int i=0;i<(1<<p);i++) for(int j=0;j<=p;j++) dp[i][j]=-1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=(1<<p)-1;j>=0;j--)
		{
			for(int K=1;K<=p;K++)
			{
				if((1<<K-1)&j) continue;
				for(int l=p;l>=0;l--)
				{
					if(i<=k+l) {if(l!=p)dp[j|(1<<K-1)][l+1]=max(dp[j|(1<<K-1)][l+1],dp[j][l]-d[i]+d[k+l+1]+w[a[i].id][K]);}
					else dp[j|(1<<K-1)][l]=max(dp[j|(1<<K-1)][l],dp[j][l]+w[a[i].id][K]);
				}
			}
		}
	}
	int mx=-1e18;
	for(int i=0;i<=p;i++) mx=max(mx,dp[(1<<p)-1][i]);
	cout << ans+mx;
	return 0;
}