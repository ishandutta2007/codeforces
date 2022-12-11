#include<bits/stdc++.h>
using namespace std;
const int mod=469762049;
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
const int max_N=1<<20|5;
int F[max_N],W[max_N],rev[max_N],N;
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
const int max_R=1e3+5;
int cnt[max_R];
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,k,R=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		R=max(R,a);
		++cnt[a];
	}
	for(int i=1;i<=R;++i)
		F[i]=cnt[i];
	int N=1;
	while(N<=R*k)
		N<<=1;
	NTT(F,N,1);
	for(int i=0;i<N;++i)
		F[i]=qpow(F[i],k);
	NTT(F,N,-1);
	for(int i=1;i<=R*k;++i)
	{
		if(F[i])
			printf("%d ",i);
	}
	putchar('\n');
	return 0;
}