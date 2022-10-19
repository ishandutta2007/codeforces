#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=1000000007;
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int dp[N][N][2][2],f[N]={1},s[N],n,k,ans;
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
int c(int n,int m)
{
	return 1ll*f[n]*qp(f[m],mod-2)%mod*qp(f[n-m],mod-2)%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		f[i]=1ll*f[i-1]*i%mod;
	dp[0][0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int x=0;x<2;x++)
			{
				for(int y=0;y<2;y++)
				{
					add(dp[i+1][j][y][0],dp[i][j][x][y]);
					if(x==0&&i!=0) add(dp[i+1][j+1][y][0],dp[i][j][x][y]);
					if(i!=n-1) add(dp[i+1][j+1][y][1],dp[i][j][x][y]);
				}
			}
		}
	}
	for(int j=0;j<=n;j++)
	{
		for(int x=0;x<2;x++)
			for(int y=0;y<2;y++)
				add(s[j],dp[n][j][x][y]);
		s[j]=1ll*s[j]*f[n-j]%mod;
	}
	ans=s[k];
	for(int i=k+1;i<=n;i++)
	{
		if((i-k)%2)
			ans=(ans+mod-1ll*s[i]*c(i,k)%mod)%mod;
		else
			ans=(ans+1ll*s[i]*c(i,k)%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}