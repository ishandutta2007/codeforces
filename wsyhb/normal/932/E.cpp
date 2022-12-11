#include<bits/stdc++.h>
using namespace std;
const int max_k=5e3+5;
int dp[max_k][max_k];
const int mod=1e9+7;
inline int qpow(int a,int n)
{
	int res=1;
	while(n>0)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	int N,k;
	scanf("%d%d",&N,&k);
	dp[0][0]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=i&&j<=N;++j)
			dp[i][j]=(dp[i-1][j-1]*(N-j+1ll)+dp[i-1][j]*(j+0ll))%mod;
	int lim=min(k,N),Pow=qpow(2,N-lim),ans=0;
	for(int j=lim;j>=0;--j)
	{
		ans=(ans+1ll*Pow*dp[k][j])%mod;
		Pow<<=1,Pow-=Pow>=mod?mod:0;
	}
	printf("%d\n",ans);
	return 0;
}