#include<bits/stdc++.h>
#define P 1000000007
#define N 5000005

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
	if(x<0||y<0||x<y)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int n;

int ans;

int main(){
	scanf("%d",&n);
	init(n);
	for(int k=1;k<=n/2;k++)
		ans=fmo(ans+2ll*fac[2*k]%P*fmo(C(2*k,n-2*k)%P+C(2*k-1,n-2*k-1)-P)%P-P);
	printf("%d\n",ans);
}