#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=100005;
int n,h[2][N],f[N][2];
signed main(){
	rd(n);
	rep(op,0,1){
		rep(i,1,n){
			rd(h[op][i]);
		}
	}
	f[0][0]=f[0][1]=0,f[1][0]=h[0][1],f[1][1]=h[1][1];
	for(int i=2;i<=n;++i){
		f[i][0]=h[0][i]+max(f[i-1][1],max(f[i-2][1],f[i-2][0]));
		f[i][1]=h[1][i]+max(f[i-1][0],max(f[i-2][0],f[i-2][1]));
	}
	pt(max(f[n][0],f[n][1]),'\n');
	return 0;
}