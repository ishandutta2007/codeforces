#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define int long long
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
 
const int N=100005;
 
int n,a[N],b[N],sum;
 
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	std::sort(a+1,a+1+n);int cnt=0;
	rep(i,2,n)if(a[i]==a[i-1])++cnt;if(cnt>1){puts("cslnb");return 0;}
	rep(i,2,n)if(a[i]==a[i+1]&&a[i-1]==a[i]-1){puts("cslnb");return 0;}
	rep(i,1,n)if(a[i]>=*b)sum^=(a[i]-*b)&1,b[++*b]=a[i];else{puts("cslnb");return 0;}
	if(sum&1)puts("sjfnb");
	else puts("cslnb");
	return 0;
}