#include<cstdio>
#include<string>
#include<iostream>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=105;
int q,cnt[256];char s[N],t[N],p[N];
bool chk(){
	int j=0;
	for(int i=0;s[i];++i){
		while(t[j]&&t[j]!=s[i])++j;
		if(!t[j])return 0;
		++j;
	}
	return 1;
}
signed main(){
	rd(q);
	while(q--){
		scanf("%s%s%s",s,t,p);
		if(!chk()){puts("NO");goto tag;}
		for(int i='a';i<='z';++i)cnt[i]=0;
		for(int i=0;p[i];++i)++cnt[p[i]];
		for(int i=0;s[i];++i)++cnt[s[i]];
		for(int i=0;t[i];++i)if((--cnt[t[i]])<0){puts("NO");goto tag;}
		puts("YES");
		tag:;
	}
	return 0;
}