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
const int max_R=2e5+5;
int fac[max_R],inv_fac[max_R];
inline void init(int R)
{
	fac[0]=1;
	for(int i=1;i<=R;++i)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv_fac[R]=qpow(fac[R],mod-2);
	for(int i=R-1;i>=0;--i)
		inv_fac[i]=(i+1ll)*inv_fac[i+1]%mod;
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
inline int C2(int x,int y)
{
	return C(x+y,x);
}
const int max_k=2e3+5;
int r[max_k],c[max_k],id[max_k];
inline bool cmp(int x,int y)
{
	return r[x]+c[x]<r[y]+c[y];
}
const int max_log=20+5;
int dp[max_k][max_log],f[max_log],val[max_log];
int main()
{
	int n,m,k,s;
	scanf("%d%d%d%d",&n,&m,&k,&s);
	init(n+m);
	int tot=0;
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",r+i,c+i);
		if((r[i]==1&&c[i]==1)||(r[i]==n&&c[i]==m))
			s=(s+1)>>1;
		else
			r[++tot]=r[i],c[tot]=c[i];
	}
	k=tot;
	r[++k]=1,c[k]=1;
	for(int i=1;i<=k;++i)
		id[i]=i;
	sort(id+1,id+k+1,cmp);
	val[0]=s;
	int lim=0;
	while(val[lim]>1)
	{
		val[lim+1]=(val[lim]+1)>>1;
		++lim;
	}
	if(!lim)
	{
		puts("1");
		return 0;
	}
	dp[1][0]=1;
	for(int x=2;x<=k;++x)
	{
		int a=id[x],v=C2(r[a]-1,c[a]-1),sum=0;
		for(int i=1;i<=lim;++i)
		{
			int res=v;
			for(int y=1;y<x;++y)
			{
				int b=id[y];
				if(r[b]<=r[a]&&c[b]<=c[a])
					res=(res-1ll*dp[y][i]*C2(r[a]-r[b],c[a]-c[b]))%mod;
			}
			res+=res<0?mod:0;
			res-=sum;
			res+=res<0?mod:0;
			dp[x][i]=res;
			sum+=res;
			sum-=sum>=mod?mod:0;
		}
		dp[x][lim+1]=v-sum;
		dp[x][lim+1]+=dp[x][lim+1]<0?mod:0;
//		fprintf(stderr,"x=%d r=%d c=%d\n",x,r[a],c[a]);
//		for(int i=1;i<=lim;++i)
//			fprintf(stderr,"i=%d dp[x][i]=%d\n",i,dp[x][i]);
	}
	int v=C2(n-1,m-1),sum=0;
	for(int i=0;i<lim;++i)
	{
		int res=v;
		for(int y=1;y<=k;++y)
			res=(res-1ll*dp[y][i+1]*C2(n-r[id[y]],m-c[id[y]]))%mod;
		res+=res<0?mod:0;
		res-=sum;
		res+=res<0?mod:0;
		f[i]=res;
		sum+=res;
		sum-=sum>=mod?mod:0;
	}
	f[lim]=v-sum;
	f[lim]+=f[lim]<0?mod:0;
	long long ans=0;
	for(int i=0;i<=lim;++i)
	{
//		fprintf(stderr,"i=%d f[i]=%d val[i]=%d\n",i,f[i],val[i]);
		ans+=1ll*f[i]*val[i];
	}
	ans=ans%mod*qpow(v,mod-2)%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
19 19 23 1001
13 19
11 4
8 4
3 1
16 6
12 15
13 18
12 7
10 18
12 10
10 16
1 18
13 13
6 4
7 11
8 3
19 8
2 12
14 8
2 17
4 8
12 9
13 10
----
156317295
*/