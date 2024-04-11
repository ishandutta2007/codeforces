#include<bits/stdc++.h>
using namespace std;
inline int char_to_int(char x) // A~Z & a~z -> 0 ~ 51
{
	return x<='Z'?x-'A':x-'a'+26;
}
const int max_n=1e5+5;
char s[max_n];
const int tot=52;
const int max_tot=52+5;
int cnt[max_tot];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a<b?mod:0);
}
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
int ans[max_tot][max_tot];
const int max_m=5e4+5;
int dp[max_m],f[max_m],g[max_m],fac[max_m],inv_fac[max_m];
int main()
{
	int q;
	scanf("%s%d",s+1,&q);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)
		++cnt[char_to_int(s[i])];
	int m=n>>1;
	dp[0]=1;
	for(int i=0;i<tot;++i)
	{
		if(!cnt[i])
			continue;
		if(cnt[i]>m)
		{
			puts("0");
			return 0;
		}
		for(int j=m;j>=cnt[i];--j)
			add(dp[j],dp[j-cnt[i]]);
	}
	for(int i=0;i<=m;++i)
		f[i]=dp[i];
	fac[0]=1;
	for(int i=1;i<=m;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv_fac[m]=qpow(fac[m],mod-2);
	for(int i=m-1;i>=0;--i)
		inv_fac[i]=inv_fac[i+1]*(i+1ll)%mod;
	int c=1ll*fac[m]*fac[m]%mod;
	for(int i=0;i<tot;++i)
	{
		if(cnt[i])
			c=1ll*c*inv_fac[cnt[i]]%mod;
	}
	int Ans=1ll*dp[m]*c%mod;
	for(int i=0;i<tot;++i)
	{
		if(!cnt[i])
			continue;
		for(int k=0;k<=m;++k)
			g[k]=f[k];
		for(int k=cnt[i];k<=m;++k)
			sub(g[k],g[k-cnt[i]]);
		for(int j=i+1;j<tot;++j)
		{
			if(!cnt[j]||cnt[i]+cnt[j]>m)
				continue;
			for(int k=0;k<=m;++k)
				dp[k]=g[k];
			for(int k=cnt[j];k<=m;++k)
				sub(dp[k],dp[k-cnt[j]]);
			for(int k=m;k>=cnt[i]+cnt[j];--k)
				add(dp[k],dp[k-(cnt[i]+cnt[j])]);
			ans[i][j]=1ll*dp[m]*c%mod;
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int a=char_to_int(s[x]),b=char_to_int(s[y]);
		if(a>b)
			swap(a,b);
		if(a==b)
			printf("%d\n",Ans);
		else
			printf("%d\n",ans[a][b]);
	}
	return 0;
}