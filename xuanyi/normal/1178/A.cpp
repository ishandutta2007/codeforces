#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=105;
int n,a[N],q[N],sum,s;
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]),sum+=a[i];
	q[++*q]=1,s+=a[1];
	for(int i=2;i<=n;++i)if(a[i]*2<=a[1])q[++*q]=i,s+=a[i];
	if(s*2>sum){
		pt(*q,'\n');
		for(int i=1;i<=*q;++i)pt(q[i],' ');
	}else puts("0");
	return 0;
}