#include<bits/stdc++.h>
#define P 1000000007
#define N 1000005

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

int fac[N],inv[N],ifac[N];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
inline int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int T;

int main(){
	init(1e6);
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(n==m){
			printf("%lld\n",1ll*n*k%P);
			continue;
		}
		int res=0;
		for(int i=1;i<=m;i++)
			res=fmo(res+1ll*fp(inv[2],n-i)*C(n-1-i,m-i)%P*i%P*k%P-P);
		printf("%d\n",res);
	}
}