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
int fac[max_n],inv_fac[max_n],Pow2[max_n],Pow[max_n];
inline void init(int R)
{
	fac[0]=1,Pow[0]=Pow2[0]=1;
	for(int i=1;i<=R;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		Pow2[i]=Pow2[i-1]<<1;
		Pow2[i]-=Pow2[i]>=mod?mod:0;
		Pow[i]=Pow[i-1]+(Pow[i-1]&1?mod:0);
		Pow[i]>>=1;
	}
	inv_fac[R]=qpow(fac[R],mod-2);
	for(int i=R-1;i>=0;--i)
		inv_fac[i]=inv_fac[i+1]*(i+1ll)%mod;
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int main()
{
	init(1e6);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(n==m)
		{
			printf("%lld\n",1ll*n*k%mod);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
			ans=(ans+1ll*i*Pow2[i-1]%mod*C(n-(i+1),m-i))%mod;
		ans=1ll*ans*Pow[n-1]%mod*k%mod;
		printf("%d\n",ans);
	}
	return 0;
}