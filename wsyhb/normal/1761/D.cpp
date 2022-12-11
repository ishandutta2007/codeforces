#include<bits/stdc++.h>
using namespace std;
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
const int max_n=1e6+5;
int fac[max_n],inv_fac[max_n],Pow3[max_n];
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv_fac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv_fac[i]=(i+1ll)*inv_fac[i+1]%mod;
	Pow3[0]=1;
	for(int i=1;i<=n;++i)	
		Pow3[i]=3ll*Pow3[i-1]%mod;
	if(!k)
	{
		printf("%d\n",Pow3[n]);
		return 0;
	}
	int ans=0;
	for(int c=1;c<=k&&c-1<=n-k;++c)
		ans=(ans+(1ll*C(n-k,c)*(2*c<=n?Pow3[n-2*c]:0)+1ll*C(n-k,c-1)*Pow3[n-2*c+1])%mod*C(k-1,c-1))%mod;
	printf("%d\n",ans);
	return 0;
}