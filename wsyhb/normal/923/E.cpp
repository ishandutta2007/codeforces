#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
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
const int max_N0=1<<18|5;
int F[max_N0],G[max_N0],W[max_N0],rev[max_N0],N;
inline void NTT(int *f,int n,int ty)
{
	if(n!=N)
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
		int w=qpow(3,ty*(mod-1)/b+mod-1);
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
	if(ty==-1)
	{
		int t=qpow(N,mod-2);
		for(int i=0;i<N;++i)
			f[i]=1ll*f[i]*t%mod;
	}
}
const int max_N=1e5+5;
int fac[max_N],inv_fac[max_N],inv[max_N];
inline void init(int R)
{
	fac[0]=1;
	for(int i=1;i<=R;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv_fac[R]=qpow(fac[R],mod-2);
	for(int i=R-1;i>=0;--i)
	{
		inv_fac[i]=(i+1ll)*inv_fac[i+1]%mod;
		inv[i+1]=1ll*inv_fac[i+1]*fac[i]%mod;
	}
//	for(int i=0;i<=R;++i)
//		fprintf(stderr,"i=%d i!=%d inv(i!)=%d inv(i)=%d\n",i,fac[i],inv_fac[i],inv[i]);
}
int P[max_N];
int main()
{
	int N;
	long long M;
	scanf("%d%lld",&N,&M);
	M%=mod-1;
	init(N+1);
	for(int i=0;i<=N;++i)
	{
		scanf("%d",P+i);
		F[i]=1ll*P[i]*fac[i]%mod;
		G[i]=inv_fac[N-i];
	}
	int N0=1;
	while(N0<=2*N)
		N0<<=1;
	NTT(F,N0,1),NTT(G,N0,1);
	for(int i=0;i<N0;++i)
		F[i]=1ll*F[i]*G[i]%mod;
	NTT(F,N0,-1);
	for(int i=0;i<N0;++i)
		G[i]=0;
	for(int i=0;i<=N;++i)
	{
		F[i]=1ll*F[i+N]%mod*qpow(inv[i+1],M)%mod;
		G[i]=inv_fac[N-i];
		if((N-i)&1)
			G[i]=mod-G[i];
	}
	for(int i=N+1;i<N0;++i)
		F[i]=0;
	NTT(F,N0,1),NTT(G,N0,1);
	for(int i=0;i<N0;++i)
		F[i]=1ll*F[i]*G[i]%mod;
	NTT(F,N0,-1);
	for(int i=0;i<=N;++i)
		printf("%lld%c",1ll*inv_fac[i]*F[i+N]%mod,i<N?' ':'\n');
	return 0;
}