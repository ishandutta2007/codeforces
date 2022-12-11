#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int max_R=2e5+5;
int inv[max_R],inv_fac[max_R],fac[max_R];
const int R=2e5;
inline void init()
{
	inv_fac[0]=fac[0]=1;
	inv[1]=inv_fac[1]=fac[1]=1;
	for(int i=2;i<=R;++i)
	{
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
		fac[i]=1ll*fac[i-1]*i%mod;
	}
}
namespace BIT
{
	int val[max_R];
	inline void add(int k,int v)
	{
		for(int i=k;i<=R;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}
int cnt[max_R];
const int max_n=2e5+5;
int s[max_n],t[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",s+i);
		++cnt[s[i]];
	}
	for(int i=1;i<=m;++i)
		scanf("%d",t+i);
	init();
	int now=1;
	for(int i=1;i<=R;++i)
	{
		now=1ll*now*inv_fac[cnt[i]]%mod;
		BIT::add(i,cnt[i]);
	}
	int ans=0;
	for(int i=1;i<=min(n,m);++i)
	{
		ans=(ans+1ll*fac[n-i]*now%mod*BIT::query(t[i]-1))%mod;
		if(!cnt[t[i]])
		{
			printf("%d\n",ans);
			return 0;
		}
		now=1ll*now*(cnt[t[i]]--)%mod;
		BIT::add(t[i],-1);
	}
	if(n<m)
	{
		++ans;
		ans-=ans>=mod?mod:0;
	}
	printf("%d\n",ans);
	return 0;
}