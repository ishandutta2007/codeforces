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
const int max_n=1e5+5;
int fac[max_n],inv_fac[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		fac[0]=1;
		for(int i=1;i<=n;++i)
			fac[i]=1ll*fac[i-1]*i%mod;
		inv_fac[n]=qpow(fac[n],mod-2);
		for(int i=n-1;i>=0;--i)
			inv_fac[i]=(i+1ll)*inv_fac[i+1]%mod;
		int ans=1;
		for(int p=1;p<=n&&n-(k-1)*(p-1)>=p;++p)
			ans=(ans+1ll*fac[n-(k-1)*(p-1)]*inv_fac[p]%mod*inv_fac[n-k*(p-1)-1]%mod*fac[n-p]%mod*fac[p]%mod*inv_fac[n])%mod;
		printf("%d\n",ans);
	}
	return 0;
}