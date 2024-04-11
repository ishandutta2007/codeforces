#include<cstdio>
#include<algorithm>
#define P 998244353
#define N 55
#define L 2005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	if(k<0)
		k+=P-1;
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int n,k,a[N],l;

int fac[L],inv[L],ifac[L];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(P-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}

int m,f[N][L][N],g[L][N];

int ans;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l+=a[i];
	}
	init(l);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=(a[i]-1)/k;j++){
			int A=1ll*(a[i]-j*k)*inv[l]%P;
			if(j)
				g[j-1][1]=1ll*(j&1?P-1:1)*ifac[j-1]%P*fp(A,j-1)%P;
			g[j][0]=1ll*(j&1?P-1:1)*ifac[j]%P*fp(A,j)%P;
		}
		for(int j=0;j<=(a[i]-1)/k;j++)
			for(int o=0;o<2;o++)
				for(int x=0;x<=m;x++)
					for(int y=0;y<i;y++)
						f[i][j+x][o+y]=fmo(f[i][j+x][o+y]+1ll*g[j][o]*f[i-1][x][y]%P-P);
		m+=(a[i]-1)/k;
		for(int j=0;j<=(a[i]-1)/k;j++)
			for(int o=0;o<2;o++)
				g[j][o]=0;
	}
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++){
			int a=i,b=fmo(1-1ll*(i+j)*k*inv[l]%P),c=f[n][i][j];
			if(b==1)
				continue;
			ans=fmo(ans-1ll*c*fac[a]%P*fp(fp(fmo(1-b),a+1))%P);
		}
	printf("%d\n",ans);
}