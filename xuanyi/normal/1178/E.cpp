#include<cstdio>
#include<cstring>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=1000005;
int n,len;char s[N],t[N];
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n/2;i+=2){
		if(s[i]==s[n-i+1]||s[i]==s[n-i]){
			t[++len]=s[i];
		}else{
			t[++len]=s[i+1];
		}
	}
	for(int i=1;i<=len;++i)putchar(t[i]);
	for(int i=len-(n/2&1);i>=1;--i)putchar(t[i]); 
	return 0;
}