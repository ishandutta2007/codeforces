#include<cstdio>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=10005;
int n,a[N],p[N],vis[N],cnt,uu[N],vv[N];
void ae(int u,int v){
	uu[++cnt]=u,vv[cnt]=v;
}
void pre(){
	vis[0]=vis[1]=1;
	for(int i=2;i<N;++i){
		if(!vis[i])p[++*p]=i;
		for(int j=1;i*p[j]<N&&j<=*p;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
signed main(){
	pre();
	rd(n);
	for(int i=1;i<=n;++i)ae(i,i%n+1);
	int u=1;
	while(vis[cnt]){
		ae(u,(u+(n/2))%n);
		++u;
	}
	pt(cnt,'\n');
	for(int i=1;i<=cnt;++i)pt(uu[i],' '),pt(vv[i],'\n');
	return 0;
}