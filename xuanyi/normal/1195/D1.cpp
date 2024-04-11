#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int P=998244353;
int n,ans;
int pp(int x){
	int res=0;
	while(x)x/=10,++res;
	return res;
}
signed main(){
	rd(n);
	rep(i,1,n){
		int x;rd(x);
//		int len=pp(x);
		int s=1;
		while(x){
			(ans+=s*(x%10)%P)%=P;
			(ans+=(s*10)%P*(x%10)%P)%=P;
			(s*=100)%=P;
			x/=10;
		}
	}
	pt(ans*n%P,'\n');
	return 0;
}