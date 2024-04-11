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
const int N=50005;
int q;std::string s[N];int sum[400005],sum2[400005];
signed main(){
	rd(q);
	while(q--){
		int n,m;rd(n),rd(m);
		rep(i,1,n)std::cin>>s[i],s[i]=" "+s[i];
		rep(i,1,n)sum[i]=0;
		rep(i,1,m)sum2[i]=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				sum[i]+=s[i][j]=='*';
				sum2[j]+=s[i][j]=='*';
			}
		}
		int ans=n+m-1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ans=min(ans,n+m-1-(sum[i]+sum2[j]-(s[i][j]=='*')));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}