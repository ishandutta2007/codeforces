#include<bits/stdc++.h>
#define P 998244353
#define N 5005

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

int n;

int f[N][N];

int main(){
	scanf("%d",&n);
	init(n);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			f[i][j]=fmo(1ll*(j+1)*f[i-1][j]%P+1ll*(i-j)*f[i-1][j-1]%P-P);
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=1;j<=n;j++)
			ans=fmo(ans+1ll*ifac[j]*f[j][i]%P-P);
		ans=1ll*ans*fac[n]%P;
		printf("%d ",ans);
	}
}