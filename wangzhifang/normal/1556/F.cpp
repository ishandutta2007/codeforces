#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
#define mod 1000000007
#define max_n 14
typedef long long ll;
il ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
inline void mod2(int&x){
	x<0&&(x+=mod);
}
int h[1<<max_n][max_n],p[1<<max_n],a[max_n],g[1<<max_n],t[1<<max_n];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%d",a+i);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			h[1<<i][j]=quickpow(a[i]+a[j],mod-2,a[i])/*,printf("%d %d: %d\n",i,j,h[1<<i][j])*/;
	for(int j=0; j<n; ++j)
		h[0][j]=1;
	int f=(1<<n)-1;
	for(int i=3; i<f; ++i){
		cs int v=1<<__builtin_ctz(i);
		cs int j=i^v;
		for(int k=0; k<n; ++k)
			h[i][k]=ll(h[j][k])*h[v][k]%mod/*,printf("%d %d: %d\n",i,k,h[i][k])*/;
	}
	p[0]=0;
	for(int i=f; i; --i)
		p[i]=1;
	t[0]=0;
	for(int i=1; i<f; ++i){
		int v=f^i,pi=p[i],m=1<<__builtin_popcount(v);
		int cnt=m;
//		printf("%d\n",pi);
		for(int j=v; j; j=(j-1)&v/*,printf("%d %d\n",cnt,t[cnt])*/)
			t[--cnt]=j;
		g[0]=1;
		for(int j=0; j<__builtin_ctz(m); ++j)
			g[1<<j]=h[i][__builtin_ctz(t[1<<j])]/*,printf("%d: %d\n",j,__builtin_ctz(t[1<<j]))*/;
		for(int j=1; j<m; ++j){
			g[j]=g[j&(j-1)]*ll(g[j&(-j)])%mod;
//			printf("%d: %d\n",t[j],g[j]);
			mod2(p[t[j]|i]-=ll(pi)*g[j]%mod);
		}
		p[i]=ll(pi)*g[m-1]%mod;
//		printf("p_%d: %d\n",i,p[i]);
	}
//	printf("p_%d: %d\n",f,p[f]);
	int ans=0;
	for(int i=f; i; --i)
		ans=(ans+ll(p[i])*__builtin_popcount(i))%mod;
	printf("%d\n",ans);
	return 0;
}