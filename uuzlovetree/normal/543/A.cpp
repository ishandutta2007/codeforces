#include<bits/stdc++.h>
#define ll long long
#define maxn 505
using namespace std;
int n,m,b;
ll mod;
int a[maxn];
ll dp[maxn][maxn];
int main()
{
	scanf("%d%d%d%I64d",&n,&m,&b,&mod);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=m;++i)
		{
			for(int j=0;j<=b;++j)if(j-a[k]>=0)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[k]])%mod;
			}
		}
	}
	ll ans=0;
	for(int j=0;j<=b;++j)ans+=dp[m][j],ans%=mod;
	cout<<ans<<endl;
	return 0;
}