#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;b>>=1;}return ans;}
int n,m,k,f[N][N],ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	f[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=(1ll*f[i-1][j-1]*(n+1-j)%mod+1ll*f[i-1][j]*j%mod)%mod;
	for(int i=1;i<=k;i++)
		ans=(ans+1ll*f[k][i]*qp(qp(m,mod-2),i)%mod)%mod;
	printf("%d\n",ans);
	return 0;
}