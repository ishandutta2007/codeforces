#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=505,P=998244353;
int n,m,a[N],f[N][N];
signed main(){
	rd(n),rd(m);
	rep(i,1,n){
		rd(a[i]);
	}
	for(int i=1;i<=n+1;++i)f[i][i]=f[i][i-1]=1;
	for(int L=2;L<=n;++L){
		for(int i=1;i<=n+1-L;++i){
			int j=i+L-1,x=i,L=0,R=0;
			for(int k=i;k<=j;++k)if(a[k]<a[x])x=k;
			for(int k=i;k<=x;++k)(L+=1ll*f[i][k-1]*f[k][x-1]%P)%=P;
			for(int k=x;k<=j;++k)(R+=1ll*f[x+1][k]*f[k+1][j]%P)%=P;
			f[i][j]=1ll*L*R%P;
		}
	}
	pt(f[1][n],'\n');
	return 0;
}