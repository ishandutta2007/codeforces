#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int qpow(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
const int max_n=2e5+5;
int fac[max_n],inv_fac[max_n];
inline void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv_fac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv_fac[i]=inv_fac[i+1]*(i+1ll)%mod; 
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int sa[max_n],rk[max_n];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n-1;++i)
	{
		scanf("%d",sa+i);
		rk[sa[i]]=i+1;
	}
	int cnt_same=0;
	for(int i=0;i<n-1;++i)
		cnt_same+=rk[sa[i]+1]<rk[sa[i+1]+1];
	init(max(n,k));
	int ans=0;
	for(int i=max(n-k,0);i<=cnt_same;++i)
		ans=(ans+1ll*C(cnt_same,i)*C(k,n-i))%mod;
	printf("%d\n",ans);
	return 0;
}