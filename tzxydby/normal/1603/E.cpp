#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,mod,fc[N],iv[N],ans,a1,dp[N][N][N],v[N][N][N];
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int dfs(int i,int j,int k)
{
	int &f=dp[i][j][k];
	if(v[i][j][k]==a1)
		return f;
	if(i==n)
		return f=1;
	if(!k)
		return f=iv[n-i];
	v[i][j][k]=a1;
	f=0;
	for(int c=0;c<=(a1-j)/k;c++)
	{
		if(k>1&&i+c<n+1-a1-k+1)
			continue;
		f=(f+1ll*dfs(i+c,j+c*k,k-1)*iv[c])%mod;
	}
	return f;
}
int main()
{
	scanf("%d%d",&n,&mod);
	fc[0]=iv[0]=1;
	for(int i=1;i<=n;i++)
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	for(a1=max(1,(int)(n-2*sqrt(n)-1));a1<=n;a1++)
		ans=(ans+dfs(0,0,n+1-a1))%mod;
	ans=1ll*ans*fc[n]%mod;
	printf("%d\n",ans);
	return 0;
}