#include<bits/stdc++.h>
using namespace std;
int N=1;
const int max_n=2e5+5;
int fac[max_n],inv[max_n],inv_fac[max_n];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline void init(int n)
{
	while(N<n)
	{
		++N;
		fac[N]=1ll*fac[N-1]*N%mod;
		inv[N]=1ll*(mod-mod/N)*inv[mod%N]%mod;
		inv_fac[N]=1ll*inv_fac[N-1]*inv[N]%mod;
	}
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int main()
{
	fac[0]=inv_fac[0]=1;
	fac[1]=inv[1]=inv_fac[1]=1;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l,r;
		scanf("%d%d%d",&n,&l,&r);
		init(n);
		int h=n>>1;
		int p=min(1-l,r-n);
		int ans=1ll*p*C(n,h)%mod;
		if(n&1)
			add(ans,ans);
		for(int k=p+1;;++k)
		{
			int rg=min(n,r-k);
			int lf=max(1,l+k);
			if(rg-lf+1<0||h+1-(lf-1)<0)
				break;
			add(ans,C(rg-lf+1,h-(lf-1)));
			if(n&1)
				add(ans,C(rg-lf+1,h+1-(lf-1)));
		}
		printf("%d\n",ans);
	}
	return 0;
}