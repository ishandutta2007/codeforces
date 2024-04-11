#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=100005;
int n,m,k,a[N],ans,cnt;
signed main(){
	rd(n),rd(m),rd(k);
	rep(i,1,m)rd(a[i]);
	for(int i=1;i<=m;){
		int tot=0;
		int j=i;
		while(j<=m&&(a[j]-cnt-1)/k==(a[i]-cnt-1)/k)++tot,++j;
		cnt+=tot;
		++ans;
		i=j;
	}
	pt(ans,'\n');
	return 0;
}