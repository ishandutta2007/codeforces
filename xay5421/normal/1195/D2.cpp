#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int P=998244353;
const int N=100005;
int n,ans,tot[15],g[15][15],ten[25];
int pp(int x){
	int res=0;
	while(x)x/=10,++res;
	return res;
}
signed main(){
	ten[0]=1;rep(i,1,24)ten[i]=ten[i-1]*10%P;
	rd(n);
	rep(i,1,n){
		int x;rd(x);
		int len=pp(x);++tot[len];
		rep(j,1,len){
			(g[len][j]+=x%10)%=P;
			x/=10;
		}
	}
	rep(i,1,10)rep(j,1,10){
		int x=i,y=j;
		int len=0;
		for(int k=0;;++k){
			if(!x&&!y)break;
			if(y)(ans+=tot[i]%P*g[j][k+1]%P*ten[len++]%P)%=P,--y;
			if(x)(ans+=tot[j]%P*g[i][k+1]%P*ten[len++]%P)%=P,--x;
		}
	}
	pt(ans,'\n');
	return 0;
}