#include<bits/stdc++.h>
#define P 998244353
#define N 400005

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

namespace poly{
	const int G=114514,iG=fp(G);
	
	int l,rev[N<<2],gn[N<<2],ign[N<<2];
	inline void build(int len){
		int lmt=1;
		while(lmt<len){
			lmt<<=1;
			l++;
		}
		for(int i=0;i<lmt;i++)
			rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=1;i<lmt;i<<=1){
			gn[i]=fp(G,(P-1)/(i<<1));
			ign[i]=fp(iG,(P-1)/(i<<1));
		}
	}
	inline void dft(int *f,int k,int tp){
		int lmt=1<<k;
		for(int i=0;i<lmt;i++)
			if(i<(rev[i]>>(l-k)))
				std::swap(f[i],f[rev[i]>>(l-k)]);
		for(int mid=1;mid<lmt;mid<<=1)
			for(int i=0,wn=tp==1?gn[mid]:ign[mid];i<lmt;i+=mid<<1)
				for(int j=0,w=1;j<mid;j++,w=1ll*w*wn%P){
					int x=f[i+j],y=1ll*f[i+j+mid]*w%P;
					f[i+j]=(x+y)%P;
					f[i+j+mid]=(x-y+P)%P;
				}
		if(tp==-1)
			for(int i=0,tmp=fp(lmt);i<lmt;i++)
				f[i]=1ll*f[i]*tmp%P;
	}
	inline void cpy(int *g,int *f,int k){
		for(int i=0;i<(1<<k);i++)
			g[i]=f[i];
		for(int i=1<<k;i<(1<<k+1);i++)
			g[i]=0;
	}
	inline void mul(int *h,int *f,int *g,int k=l-1){
		static int *a=new int[N<<2],*b=new int[N<<2];
		cpy(a,f,k),cpy(b,g,k);
		dft(a,k+1,1),dft(b,k+1,1);
		for(int i=0;i<(1<<k+1);i++)
			a[i]=1ll*a[i]*b[i]%P;
		dft(a,k+1,-1);
		cpy(h,a,k);
	}
	inline void inv(int *g,int *f,int k=l-1){
		if(!k){
			g[0]=fp(f[0],P-2);
			g[1]=0;
			return;
		}
		static int *a=new int[N<<2],*b=new int[N<<2];
		inv(b,f,k-1);
		cpy(a,f,k),cpy(b,b,k);
		dft(a,k+1,1),dft(b,k+1,1);
		for(int i=0;i<(1<<k+1);i++)
			a[i]=(2ll*b[i]%P-1ll*b[i]*b[i]%P*a[i]%P+P)%P;
		dft(a,k+1,-1);
		cpy(g,a,k);
	}
	inline void dif(int *g,int *f,int k=l-1){
		static int *a=new int[N<<2];
		cpy(a,f,k);
		for(int i=0;i<(1<<k)-1;i++)
			a[i]=1ll*(i+1)*a[i+1]%P;
		a[(1<<k)-1]=0;
		cpy(g,a,k);
	}
	inline void inf(int *g,int *f,int k=l-1){
		static int *a=new int[N<<2];
		cpy(a,f,k);
		for(int i=(1<<k);i;i--)
			a[i]=1ll*fp(i)*a[i-1]%P;
		a[0]=0;
		cpy(g,a,k);
	}
	inline void log(int *g,int *f,int k=l-1){
		static int *a=new int[N<<2],*b=new int[N<<2];
		inv(a,f,k),dif(b,f,k);
		mul(a,a,b,k);
		inf(a,a,k);
		cpy(g,a,k);
	}
	inline void exp(int *g,int *f,int k=l-1){
		if(!k){
			g[0]=1;
			g[1]=0;
			return;
		}
		static int *a=new int[N<<2],*b=new int[N<<2];
		exp(a,f,k-1);
		cpy(a,a,k),log(b,a,k);
		for(int i=0;i<(1<<k);i++)
			b[i]=((i==0)+f[i]-b[i]+P)%P;
		mul(a,a,b,k);
		cpy(g,a,k);
	}
}

int n,m;

int a[N<<2],b[N<<2],c[N<<2];

int f[N<<2];

int main(){
	scanf("%d",&n),m=n>>1;
	init(n),poly::build(n<<2);
	for(int i=1;i<=m;i++)
		a[i]=inv[i];
	poly::exp(a,a,poly::l-2);
	for(int i=2;i<=n-m;i++)
		b[i]=1ll*fac[i-2]*a[n-i]%P;
	for(int i=0;i<=n;i++)
		c[i]=ifac[n-i]%P;
	poly::mul(c,b,c);
	for(int i=2;i<=n;i++)
		f[i]=1ll*c[n+i]*fac[n-i]%P*(i-1)%P;
	f[1]=f[2];
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	puts("");
}