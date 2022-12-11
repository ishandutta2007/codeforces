#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define maxm 10005
using namespace std;
const ll mod = 1000000007;
int n,a[maxn];
ll dp[2][3][maxm*2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		int now=i&1,pre=now^1;
		memset(dp[now],0,sizeof(dp[now]));
		dp[now][1][10005+a[i]]=1;dp[now][2][10005-a[i]]=1;
		for(int k=1;k<=2;++k)
			for(int j=0;j<maxm*2;++j)if(dp[pre][k][j])
				{
					dp[now][1][j+a[i]]=(dp[now][1][j+a[i]]+dp[pre][k][j])%mod;
					dp[now][2][j-a[i]]=(dp[now][2][j-a[i]]+dp[pre][k][j])%mod;
				}
		for(int k=1;k<=2;++k)ans=(ans+dp[i&1][k][10005])%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}