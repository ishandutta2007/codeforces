#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
const ll mod = 1000000007;
int n;
ll l,r;
ll val[4];
ll dp[maxn][4];
int main()
{
	scanf("%d%I64d%I64d",&n,&l,&r);
	ll t=(r-l+1)/3,d=(r-l+1)%3;
	if(d==0)val[0]=val[1]=val[2]=t;
	if(d==1)
	{
		val[0]=val[1]=val[2]=t;
		int x=(int)(l%3);
		val[x]++;
	}
	if(d==2)
	{
		val[0]=val[1]=val[2]=t;
		int x=(int)(l%3);
		int y=(int)((l+1)%3);
		val[x]++;val[y]++;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=(dp[i-1][0]*val[0]%mod+dp[i-1][1]*val[2]%mod+dp[i-1][2]*val[1]%mod)%mod;
		dp[i][1]=(dp[i-1][0]*val[1]%mod+dp[i-1][1]*val[0]%mod+dp[i-1][2]*val[2]%mod)%mod;
		dp[i][2]=(dp[i-1][0]*val[2]%mod+dp[i-1][1]*val[1]%mod+dp[i-1][2]*val[0]%mod)%mod;
	}
	int ans=dp[n][0];
	printf("%d\n",ans);
	return 0;
}