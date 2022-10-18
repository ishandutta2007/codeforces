#include<cstdio>
#include<algorithm>
#define P 998244353
#define N 100005

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

const int G=3,iG=fp(G,P-2);
int lmt=1,rev[N<<2];
inline void build(int len){
	while(lmt<len)
		lmt<<=1;
	for(int i=0;i<lmt;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)*(lmt>>1));
}
inline void ntt(int *a,int opt){
	for(int i=0;i<lmt;i++)
		if(i<rev[i])
			std::swap(a[i],a[rev[i]]);
	for(int mid=1;mid<lmt;mid<<=1){
		int wn=fp(opt==1?G:iG,(P-1)/(mid<<1));
		for(int i=0;i<lmt;i+=(mid<<1))
			for(int j=0,w=1;j<mid;j++,w=1ll*w*wn%P){
				int x=a[i+j],y=1ll*w*a[i+j+mid]%P;
				a[i+j]=(x+y)%P;
				a[i+j+mid]=(x-y+P)%P;
			}
	}
	if(opt==-1){
		int tmp=fp(lmt,P-2);
		for(int i=0;i<lmt;i++)
			a[i]=1ll*a[i]*tmp%P;
	}
}

int n,k;

int inv[N];

int f[N<<2],g[N<<2];

int ans;

int main(){
	scanf("%d%d",&n,&k);
	inv[0]=inv[1]=1;
	for(int i=2;i<=k+1;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	for(int i=2;i<=k;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%P;
	for(int i=0;i<=k;i++)
		f[i]=1ll*fp(i,k)*inv[i]%P;
	for(int i=0;i<=k;i++)
		g[i]=1ll*((i&1)?P-1:1)*inv[i]%P;
	build((k+1)<<1);
	ntt(f,1),ntt(g,1);
	for(int i=0;i<lmt;i++)
		f[i]=1ll*f[i]*g[i]%P;
	ntt(f,-1);
	for(int i=0,tmp=1;i<=k&&i<=n;tmp=1ll*tmp*(n-i)%P,i++)
		ans=fmo(ans+1ll*f[i]*tmp%P*fp(n+1,n-i)%P-P);
	printf("%d\n",ans);
}