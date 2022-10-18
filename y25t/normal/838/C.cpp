#include<bits/stdc++.h>
#define pc __builtin_popcount
#define W 18

int P;
inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int fac[1<<W],inv[1<<W],ifac[1<<W];
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

inline void fwt(int *f,int tp){
	int n=1<<W;
	for(int mid=1;mid<n;mid<<=1)
		for(int i=0;i<n;i+=mid<<1)
			for(int j=0;j<mid;j++)
				f[i+j+mid]=fmo(f[i+j+mid]+1ll*fmo(tp)*f[i+j]%P-P);
}

int n,m;

int f[W+1][1<<W],g[W+1][1<<W],h[W+1];

int ans;

int main(){
	scanf("%d%d%d",&n,&m,&P);
	ans=fp(m,n);
	if(n&1){
		printf("%d\n",ans);
		return 0;
	}
	init((1<<W)-1);
	for(int i=0;i<(1<<W);i++)
		g[pc(i)][i]=ifac[i];
	for(int i=0;i<=W;i++)
		fwt(g[i],1);
	for(int i=0;i<(1<<W);i++)
		f[0][i]=1;
	while(m){
		if(m&1)
			for(int i=W-1;~i;i--)
				for(int j=0;j<i;j++)
					for(int k=0;k<(1<<W);k++)
						f[i][k]=(f[i][k]+1ll*f[j][k]*g[i-j][k])%P;
		for(int i=W-1;~i;i--)
			for(int j=0;j<i;j++)
				for(int k=0;k<(1<<W);k++)
					g[i][k]=(g[i][k]+1ll*g[j][k]*g[i-j][k])%P;
		m>>=1;
	}
	fwt(f[pc(n)],-1);
	printf("%d\n",fmo(ans-1ll*fac[n]*f[pc(n)][n]%P));
}