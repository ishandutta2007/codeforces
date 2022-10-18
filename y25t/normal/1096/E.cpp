#include<bits/stdc++.h>
#define P 998244353
#define N 10000005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}
int inv[N];
inline void init(int x){
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
}
inline int C(int x,int y){
	int u=1,v=1;
	for(int i=1;i<=y;i++)
		u=1ll*u*(x-i+1)%P,v=1ll*v*i%P;
	return 1ll*u*fp(v)%P;
}

int n,m,k;

int f[N];

int ans;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(!k)
		return printf("%d\n",fp(n)),0;
	init(std::max(n,m));
	f[0]=1;
	for(int i=0;i<m;i++)
		f[i+1]=1ll*inv[i+1]*fmo(
		1ll*(n+i)*f[i]%P+fmo(
		(i-k+1>=0?1ll*fmo(i-k+1-1ll*n*k%P)*f[i-k+1]%P:0)+
		(i-k>=0?1ll*fmo(1ll*n*k%P-n-i+k)*f[i-k]%P:0)-P)-P)%P;
	printf("%lld\n",1ll*fmo(C(n-1+m,m)-f[m])*inv[n]%P*fp(C(n-1+m-k,m-k))%P);
}