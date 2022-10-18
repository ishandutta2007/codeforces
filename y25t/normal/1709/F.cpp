#include<bits/stdc++.h>
#define P 998244353
#define N 400005

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P) if(k&1)
		res=1ll*res*x%P;
	return res;
}

int fac[N],inv[N],ifac[N];
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=n;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
inline int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

const int G=114514;
int lmt,rev[N<<2],g[N<<2],ig[N<<2];
inline void build(int n){
	lmt=1;
	while(lmt<=n)
		lmt<<=1;
	for(int i=0;i<lmt;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)*(lmt>>1));
	for(int k=1;k<lmt;k<<=1){
		int gn=fp(G,(P-1)/(k<<1)),ign=fp(gn);
		g[k]=ig[k]=1;
		for(int j=1;j<k;j++)
			g[k+j]=1ll*g[k+j-1]*gn%P,ig[k+j]=1ll*ig[k+j-1]*ign%P;
	}
}
inline void dft(int *a,int tp){
	for(int i=0;i<lmt;i++) if(i<rev[i])
		std::swap(a[i],a[rev[i]]);
	for(int k=1;k<lmt;k<<=1) for(int i=0;i<lmt;i+=k<<1) for(int j=0;j<k;j++){
		int x=a[i+j],y=1ll*(tp==1?g:ig)[k+j]*a[i+j+k]%P;
		a[i+j]=fmo(x+y-P),a[i+j+k]=fmo(x-y);
	}
	if(tp==-1){
		int tmp=fp(lmt);
		for(int i=0;i<lmt;i++)
			a[i]=1ll*a[i]*tmp%P;
	}
}

int n,m,k;

int f[N<<2],F[N<<2];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	build(m<<1);
	for(int i=0;i<=m;i++)
		f[i]=1;
	for(int o=1;o<=n;o++){
		dft(f,1);
		for(int i=0;i<lmt;i++)
			f[i]=1ll*f[i]*f[i]%P;
		dft(f,-1);
		if(o==n)
			break;
		for(int i=lmt-1;~i;i--)
			F[i]=fmo(F[i+1]+f[i]-P);
		for(int i=0;i<=m;i++)
			f[i]=fmo(F[i]+1ll*f[i]*(m-i)%P-P);
		for(int i=m+1;i<lmt;i++)
			f[i]=0;
	}
	printf("%d\n",f[k]);
}