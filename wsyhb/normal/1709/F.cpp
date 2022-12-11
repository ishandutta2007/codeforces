#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int g=3;
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
const int max_N=1<<19|5;
int rev[max_N],N,W[max_N];
inline void NTT(int *f,int n,int type)
{
	if(N!=n)
	{
		N=n;
		for(int i=0;i<N;++i)
			rev[i]=(rev[i>>1]>>1)|(i&1?N>>1:0);
	}
	for(int i=0;i<N;++i)
	{
		if(i<rev[i])
			swap(f[i],f[rev[i]]);
	}
	W[0]=1;
	for(int a=1,b=2;a<N;a<<=1,b<<=1)
	{
		int w=qpow(g,type*(mod-1)/b+(mod-1));
		for(int i=a-2;i>=0;i-=2)
			W[i+1]=1ll*(W[i]=W[i>>1])*w%mod;
		for(int i=0;i<N;i+=b)
			for(int j=i;j<i+a;++j)
			{
				int x=f[j],y=1ll*f[j+a]*W[j-i]%mod;
				f[j]=x+y,f[j]-=f[j]>=mod?mod:0;
				f[j+a]=x-y,f[j+a]+=f[j+a]<0?mod:0;
			}
	}
	if(!~type)
	{
		int t=qpow(N,mod-2);
		for(int i=0;i<N;++i)
			f[i]=1ll*f[i]*t%mod;
	}
}
int dp[2][max_N],tmp[max_N];
int main()
{
	int n,k,f;
	cin>>n>>k>>f;
	int sta=n&1;
	for(int i=0;i<=k;++i)
		dp[sta][i]=1;
	int N=1;
	while(N<=2*k)
		N<<=1;
	for(int i=n-1;i>=0;--i)
	{
		int y=i&1,x=y^1;
		NTT(dp[x],N,1);
		for(int j=0;j<N;++j)
			tmp[j]=1ll*dp[x][j]*dp[x][j]%mod;
		NTT(tmp,N,-1);
		for(int j=0;j<N;++j)
			dp[y][j]=0;
		if(i)
		{
			long long sum=0;
			for(int j=k+1;j<=(k<<1);++j)
				sum+=tmp[j];
			dp[y][k]=sum%mod;
			for(int j=k-1;j>=0;--j)
			{
				dp[y][j]=dp[y][j+1]+tmp[j+1];
				dp[y][j]-=dp[y][j]>=mod?mod:0;
			}
			for(int j=0;j<=k;++j)
				dp[y][j]=(dp[y][j]+(k-j+1ll)*tmp[j])%mod;
		}
		else
		{
			for(int j=0;j<=(k<<1);++j)
				dp[y][j]=tmp[j];
		}
	}
	printf("%d\n",dp[0][f]);
	return 0;
}