#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,s,c[N][N],fc[N],iv[N],p[N][N];
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	fc[0]=iv[0]=1;
	for(int i=1;i<=n;i++)
		fc[i]=1ll*fc[i-1]*i%mod,iv[i]=qp(fc[i],mod-2);
	for(int i=0;i<=n;i++)
		p[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			p[i][j]=(1ll*(i-j)*p[i-1][j-1]%mod+1ll*(j+1)*p[i-1][j]%mod)%mod;
	for(int k=0;k<n;k++)
	{
		s=0;
		for(int i=max(k,1);i<=n;i++)
			s=(s+1ll*c[n][i]*p[i][k]%mod*fc[n-i]%mod)%mod;
		printf("%d ",s);
	}
	return 0;
}