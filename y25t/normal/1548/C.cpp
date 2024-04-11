#include<bits/stdc++.h>
#define P 1000000007
#define N 3100005

inline int fmo(int x){
	return x+((x>>31)&P);
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
	if(x<0||y<0||x<0)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int n,q;

int f[N];

int main(){
	scanf("%d%d",&n,&q);
	init(3*n+3);
	f[0]=n+1,f[1]=1ll*n*(n+1)/2%P*3%P;
	for(int i=3;i<=3*n+1;i++)
		f[i-1]=1ll*inv[3]*fmo(C(3*n+3,i)-fmo(3ll*f[i-2]%P+f[i-3]-P))%P;
	while(q--){
		int k;
		scanf("%d",&k);
		printf("%d\n",f[k]);
	}
}