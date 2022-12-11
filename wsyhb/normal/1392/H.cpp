#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int max_n=2e6+5;
int fac[max_n<<1],inv[max_n<<1],inv_fac[max_n<<1],f[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fac[0]=inv_fac[0]=1;
	fac[1]=inv[1]=inv_fac[1]=1;
	for(int i=2;i<=n+m+1;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
	}
	int s1=fac[m-1],s2=mod-fac[m-1],s3=0;
	for(int x=1;x<=n;++x)
	{
		s1=(s1+1ll*fac[m-1+x]*inv_fac[x])%mod;
		s2=(s2+(x-1ll)*fac[m-1+x]%mod*inv_fac[x])%mod;
		f[x]=((n+m+1ll)*inv_fac[m+x+1]%mod*((1ll*x*s1-s2+mod)%mod)+1ll*inv_fac[m+x]*s3)%mod*m%mod*fac[x]%mod*(m+x)%mod*inv[x]%mod;
		s3=(s3+1ll*f[x]*fac[m-1+x]%mod*inv_fac[x])%mod;
	}
	printf("%d\n",f[n]);
    return 0;
}